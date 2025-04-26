#include "TEngine.h"
#include <string>

void TEngine::DetectKB()
{
	bool flagDual = false;
Retry:
	if (_kbhit())
	{
		int const ch = _getch();
		flagDual = (ch == 0 || ch == 224);
		if (flagDual) goto Retry;

		switch (ch)
		{
		case 75:
		case 65:
		case 97:
		{
			pressed = KBResult::LEFT;
			break;
		}

		case 77:
		case 68:
		case 100:
		{
			pressed = KBResult::RIGHT;
			break;
		}

		case 72:
		case 119:
		case 87:
		case 32:
		{
			pressed = KBResult::ROTATE;
			break;
		}

		case 115:
		case 83:
		case 80:
		{
			pressed = KBResult::DOWN_FAST_FORWARD;
			break;
		}

		default:
			// skip all
			// pressed = KBResult::NONE;
			break;
		}

	}
}

void TEngine::CheckPause()
{

	while (doWork)
	{
		Sleep(500);
		DetectKB();
		if (pressed != KBResult::PAUSE)
			break;
	}

}

TEngine::TEngine(DWORD _engineTimeout, DWORD _engineTimeoutHighSpeed)
{
	
	engineTimeout = _engineTimeout;
	engineTimeoutHighSpeed = _engineTimeoutHighSpeed;


	blocks[0] = BlockBase('L');
	blocks[1] = BlockBase('J');
	blocks[2] = BlockBase('I');
	blocks[3] = BlockBase('O');

	blockCurrent = GenerateNextBlock();
	tbase = new TBase();
}

TEngine::~TEngine()
{
	delete(tbase);
	delete(blocks);
}

void TEngine::PrintLineWithPipe(char item)
{
	std::cout << item << '|';
}

void TEngine::PrintLine(char item)
{
	std::cout << item;
}


void TEngine::PrintEL()
{
	std::cout << std::endl;
}

BlockBase TEngine::GenerateNextBlock()
{
	srand(4);
	int idx = lastBlockUsed;
	lastBlockUsed++;
	
	if (lastBlockUsed > 3)
		lastBlockUsed = 0;
	BlockBase b(blocks[idx].thisBlock);

	return  b;
}

void TEngine::PrintLine(char item[])
{
	std::cout << item;
}
std::string  TEngine::ResolveKB()
{
	 
	switch (pressed)
	{

	case KBResult::LEFT:
		return "LEFT";
		 
	case KBResult::RIGHT:
		return "RIGHT";
		 
	case KBResult::DOWN_FAST_FORWARD:
		return "DOWN_FAST_FORWARD";

	case KBResult::NONE:
		return "NONE";

	case KBResult::PAUSE:
		return "PAUSE";

	case KBResult::QUIT:
		return "QUIT";

	case KBResult::ROTATE:
		return "ROTATE"; 
	 
	}

	return "UNKNOWN";

}
void TEngine::ShowBoard()
{
	system("cls");
	Sleep(engineTimeoutHighSpeed);

	tbase->GoDown(&blockCurrent);

	std::cout << "KBResult is now " << ResolveKB() << std::endl;
	std::cout << "blockCurrent.Position_Vertical " << blockCurrent.Position_Vertical << std::endl;
	std::cout << "blockCurrent.Position_Horizontal " << blockCurrent.Position_Horizontal << std::endl;
	std::cout << "blockCurrent.rotation " << blockCurrent.rotation << std::endl;

	PrintEL();

	// draw board
	for (size_t row = 0; row < tbase->ROWS; row++)
	{
		for (size_t col = 0; col < tbase->COLS; col++)
		{
			PrintLineWithPipe(tbase->boardTemp[row][col]);
		}
		PrintEL();
	}

	if (tbase->IsDone())
	{
		blockCurrent = GenerateNextBlock();
	}	 
}

int TEngine::Run()
{
	while (doWork)
	{

		DetectKB();
		switch (pressed)
		{
		case ROTATE:
		{
			blockCurrent.Rotate(pressed);
			break;
		}
		case LEFT: 
		case RIGHT:
		{
			blockCurrent.Move(pressed);
			pressed = KBResult::NONE;
			break;
		}
		case PAUSE:
		{
			CheckPause();
		}

		case QUIT:
		{
			doWork = false;
			continue;
		}

		/*case DOWN_FAST_FORWARD:
			{
				break;
			}
		case NONE:
			{
				goto NormalWork;
			}*/

		}

	NormalWork:
		if (pressed == KBResult::DOWN_FAST_FORWARD)
		{ 
			Sleep(engineTimeoutHighSpeed);
		}
		else
		{
			Sleep(engineTimeout);
		}
		pressed = KBResult::NONE;
		ShowBoard();
	};


	return 0;
}
