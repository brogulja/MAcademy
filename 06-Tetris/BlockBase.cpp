#include "BlockBase.h"


BlockBase::BlockBase()
{
	Init('O');
}
BlockBase::BlockBase(char type)
{
	Init(type);
}


void BlockBase::Init(char type)
{
	thisBlock = type;
	for (size_t rot = 0; rot < 4; rot++) // rotation
		for (size_t i = 0; i < 3; i++) // type
			for (size_t j = 0; j < 3; j++) // field/X
			{
				blocks[rot][i][j] = ' ';
			}

	switch (type)
	{
		case 'L':
			{
				// 0 degrees, default
				blocks[0][0][0] = 'X';		blocks[0][0][1] = ' ';		blocks[0][0][2] = ' ';
				blocks[0][1][0] = 'X';		blocks[0][1][1] = ' ';		blocks[0][1][2] = ' ';
				blocks[0][2][0] = 'X';		blocks[0][2][1] = 'X';		blocks[0][2][2] = ' ';

				// 90 degrees, left rot
				blocks[1][0][0] = ' ';		blocks[1][0][1] = ' ';		blocks[1][0][2] = ' ';
				blocks[1][1][0] = ' ';		blocks[1][1][1] = ' ';		blocks[1][1][2] = 'X';
				blocks[1][2][0] = 'X';		blocks[1][2][1] = 'X';		blocks[1][2][2] = 'X';

				// 180 degrees, left rot
				blocks[2][0][0] = ' ';		blocks[2][0][1] = 'X';		blocks[2][0][2] = 'X';
				blocks[2][1][0] = ' ';		blocks[2][1][1] = ' ';		blocks[2][1][2] = 'X';
				blocks[2][2][0] = ' ';		blocks[2][2][1] = ' ';		blocks[2][2][2] = 'X';

				// 270 degrees, left rot
				blocks[3][0][0] = 'X';		blocks[3][0][1] = 'X';		blocks[3][0][2] = 'X';
				blocks[3][1][0] = 'X';		blocks[3][1][1] = ' ';		blocks[3][1][2] = ' ';
				blocks[3][2][0] = ' ';		blocks[3][2][1] = ' ';		blocks[3][2][2] = ' ';

				break;
			}
		case 'J':
			{
				// 0 degrees, default
				blocks[0][0][0] = ' ';		blocks[0][0][1] = ' ';		blocks[0][0][2] = 'X';
				blocks[0][1][0] = ' ';		blocks[0][1][1] = ' ';		blocks[0][1][2] = 'X';
				blocks[0][2][0] = ' ';		blocks[0][2][1] = 'X';		blocks[0][2][2] = 'X';

				// 90 degrees, left rot
				blocks[1][0][0] = 'X';		blocks[1][0][1] = 'X';		blocks[1][0][2] = 'X';
				blocks[1][1][0] = ' ';		blocks[1][1][1] = ' ';		blocks[1][1][2] = 'X';
				blocks[1][2][0] = ' ';		blocks[1][2][1] = ' ';		blocks[1][2][2] = ' ';

				// 180 degrees, left rot
				blocks[2][0][0] = 'X';		blocks[2][0][1] = 'X';		blocks[2][0][2] = ' ';
				blocks[2][1][0] = 'X';		blocks[2][1][1] = ' ';		blocks[2][1][2] = ' ';
				blocks[2][2][0] = 'X';		blocks[2][2][1] = ' ';		blocks[2][2][2] = ' ';

				// 270 degrees, left rot
				blocks[3][0][0] = ' ';		blocks[3][0][1] = ' ';		blocks[3][0][2] = ' ';
				blocks[3][1][0] = 'X';		blocks[3][1][1] = ' ';		blocks[3][1][2] = ' ';
				blocks[3][2][0] = 'X';		blocks[3][2][1] = 'X';		blocks[3][2][2] = 'X';
				break;
			}
		case 'I':
			{
				// 0 degrees, default
				blocks[0][0][0] = ' ';		blocks[0][0][1] = 'X';		blocks[0][0][2] = ' ';
				blocks[0][1][0] = ' ';		blocks[0][1][1] = 'X';		blocks[0][1][2] = ' ';
				blocks[0][2][0] = ' ';		blocks[0][2][1] = 'X';		blocks[0][2][2] = ' ';

				// 90 degrees, left rot
				blocks[1][0][0] = ' ';		blocks[1][0][1] = ' ';		blocks[1][0][2] = ' ';
				blocks[1][1][0] = 'X';		blocks[1][1][1] = 'X';		blocks[1][1][2] = 'X';
				blocks[1][2][0] = ' ';		blocks[1][2][1] = ' ';		blocks[1][2][2] = ' ';

				// 180 degrees, left rot
				blocks[2][0][0] = ' ';		blocks[2][0][1] = 'X';		blocks[2][0][2] = ' ';
				blocks[2][1][0] = ' ';		blocks[2][1][1] = 'X';		blocks[2][1][2] = ' ';
				blocks[2][2][0] = ' ';		blocks[2][2][1] = 'X';		blocks[2][2][2] = ' ';

				// 270 degrees, left rot
				blocks[3][0][0] = ' ';		blocks[3][0][1] = ' ';		blocks[3][0][2] = ' ';
				blocks[3][1][0] = 'X';		blocks[3][1][1] = 'X';		blocks[3][1][2] = 'X';
				blocks[3][2][0] = ' ';		blocks[3][2][1] = ' ';		blocks[3][2][2] = ' ';
				break;
			}
		case 'O':
			{
				// 0 degrees, default
				blocks[0][0][0] = ' ';		blocks[0][0][1] = ' ';		blocks[0][0][2] = ' ';
				blocks[0][1][0] = 'X';		blocks[0][1][1] = 'X';		blocks[0][1][2] = ' ';
				blocks[0][2][0] = 'X';		blocks[0][2][1] = 'X';		blocks[0][2][2] = ' ';

				// 90 degrees, left rot
				blocks[1][0][0] = ' ';		blocks[1][0][1] = ' ';		blocks[1][0][2] = ' ';
				blocks[1][1][0] = 'X';		blocks[1][1][1] = 'X';		blocks[1][1][2] = ' ';
				blocks[1][2][0] = 'X';		blocks[1][2][1] = 'X';		blocks[1][2][2] = ' ';

				// 180 degrees, left rot
				blocks[2][0][0] = ' ';		blocks[2][0][1] = ' ';		blocks[2][0][2] = ' ';
				blocks[2][1][0] = 'X';		blocks[2][1][1] = 'X';		blocks[2][1][2] = ' ';
				blocks[2][2][0] = 'X';		blocks[2][2][1] = 'X';		blocks[2][2][2] = ' ';

				// 270 degrees, left rot
				blocks[3][0][0] = ' ';		blocks[3][0][1] = ' ';		blocks[3][0][2] = ' ';
				blocks[3][1][0] = 'X';		blocks[3][1][1] = 'X';		blocks[3][1][2] = ' ';
				blocks[3][2][0] = 'X';		blocks[3][2][1] = 'X';		blocks[3][2][2] = ' ';
				break;
			}

		default:
			// 0 degrees, default
			blocks[0][0][0] = 'X';		blocks[0][0][1] = 'X';		blocks[0][0][2] = 'X';
			blocks[0][1][0] = 'X';		blocks[0][1][1] = 'X';		blocks[0][1][2] = 'X';
			blocks[0][2][0] = 'X';		blocks[0][2][1] = 'X';		blocks[0][2][2] = 'X';

			// 90 degrees, left rot
			blocks[1][0][0] = 'X';		blocks[1][0][1] = 'X';		blocks[1][0][2] = 'X';
			blocks[1][1][0] = 'X';		blocks[1][1][1] = 'X';		blocks[1][1][2] = 'X';
			blocks[1][2][0] = 'X';		blocks[1][2][1] = 'X';		blocks[1][2][2] = 'X';

			// 180 degrees, left rot
			blocks[2][0][0] = 'X';		blocks[2][0][1] = 'X';		blocks[2][0][2] = 'X';
			blocks[2][1][0] = 'X';		blocks[2][1][1] = 'X';		blocks[2][1][2] = 'X';
			blocks[2][2][0] = 'X';		blocks[2][2][1] = 'X';		blocks[2][2][2] = 'X';

			// 270 degrees, left rot
			blocks[3][0][0] = 'X';		blocks[3][0][1] = 'X';		blocks[3][0][2] = 'X';
			blocks[3][1][0] = 'X';		blocks[3][1][1] = 'X';		blocks[3][1][2] = 'X';
			blocks[3][2][0] = 'X';		blocks[3][2][1] = 'X';		blocks[3][2][2] = 'X';
			break;
	}
}

std::vector<POINT> BlockBase::VisibleOffsetGet()
{
	return  offsets;
}

void BlockBase::Rotate(KBResult pressed)
{

	if (pressed != KBResult::ROTATE)
		return;

	// do rotate
	rotation++;
	if (rotation > 3)
		rotation = 0;

}

void BlockBase::Move(KBResult pressed)
{
	if (pressed == KBResult::LEFT)
	{
		Position_Horizontal--;
		if (Position_Horizontal < 0)Position_Horizontal = 0;
	}
	if (pressed == KBResult::RIGHT)
	{
		int max = GetMaxRight();
		Position_Horizontal++;
		if (Position_Horizontal > (9 - max))Position_Horizontal = (9 - max);
	}
}

int BlockBase::GetMaxRight()
{
	int lineMax = 0;
	for (int c = 0; c < 3; c++)
	{
		for (int r = 0; r < 3; r++)
		{
			if (blocks[rotation][r][c] == ' ') continue;
			lineMax = c;
			break;
		}
	}
	return lineMax;
}


void BlockBase::CalculatePosition(int rowOrigin, int colOrigin)
{

	offsets.clear();

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{

			if (blocks[rotation][r][c] == ' ') continue;
			int X = ((rowOrigin + r - 2));
			int Y = (colOrigin + c);
			if (X >= 0 && Y >= 0)
			{
				POINT temp ;
				temp.x = X;
				temp.y = Y;
				//if (std::count(offsets->begin(), offsets->end(), temp) == 0)
				offsets.push_back(temp);
			}
		}
	}

}