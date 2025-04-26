#include "TBase.h"


TBase::TBase()
{
	ClearMain();
	CopyMainToTemp();
}

void TBase::ClearMain()
{
	// reset boards with ' '
	for (size_t row = 0; row < ROWS; row++)
	{
		for (size_t col = 0; col < COLS; col++)
		{
			boardMain[row][col] = ' ';
		}
	}
}
void TBase::ClearTemp()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			boardTemp[row][col] = ' ';
		}
	}
}


void TBase::CopyMainToTemp()
{
	// reset boards with ' '
	for (size_t row = 0; row < ROWS; row++)
	{
		for (size_t col = 0; col < COLS; col++)
		{
			boardTemp[row][col] = boardMain[row][col];
		}
	}
}

double	 TBase::GoDown(BlockBase* block)
{
	ClearTemp();
	CopyMainToTemp();
	double score = 0;

	//       X X X X
	// 0 1 2 3 4 5 6 7 8 9
	// block.Y = 3;
	// block.blockTemp
	isStopped = false;
	int maxRow = ROWS - 1;
	int maxCols = COLS - 1;
	for (int row = 0; row < ROWS; row++)
	{
		if (row == block->Position_Vertical)
		{
			for (int col = 0; col < COLS; col++)
			{
				if (col == block->Position_Horizontal)
				{
					block->CalculatePosition(row, col);
					for (auto p : block->VisibleOffsetGet())
					{
						if (p.x <= maxRow && p.x <= maxCols)
							boardTemp[p.x][p.y] = 'X';
					}
					for (auto p : block->VisibleOffsetGet())
					{
						if ((p.x + 1) < maxRow)
							if (boardMain[(p.x + 1)][p.y < maxCols ? p.y : maxCols] != ' ')
								isStopped = true;
					}

					if (row == (maxRow))
					{
						isStopped = true;
					}


					goto End;
				}
			}
		}

		if (isStopped)
			break;
	}

End:
	// copy to main
	if (isStopped)
	{
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				if (boardMain[row][col] != ' ') continue;
				boardMain[row][col] = boardTemp[row][col];
			}
		}

	DoScore:
		std::vector<int> lines;
		// check for lines
		for (int row = 0; row < ROWS; row++)
		{
			bool allFound = true;
			for (int col = 0; col < COLS; col++)
			{
				allFound &= boardMain[row][col] != ' ';
				if (!allFound)
					break;
			}
			if (allFound)
			{
				//if (std::count(lines.begin(), lines.end(), row) < 1)
					lines.push_back(row);
			}
		}

		if (!lines.empty())
		{

			double tmpScore = ResolveLines(lines);
			if (tmpScore > 0)
			{
				if (ResolveLineMovement())
					goto DoScore;
			}

			score += tmpScore;
		}
	}

	if (!isStopped)
	{
		block->Position_Vertical++;
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				if (boardTemp[row][col] != ' ') continue;
				boardTemp[row][col] = boardMain[row][col];
			}
		}
	}

	return score;
}

bool TBase::ResolveLineMovement()
{
	bool hasMovement = false;
	for (int row = ROWS - 1; row >= 0; row--)
	{
		if (row > 0 && row < (ROWS - 1))
		{
			for (int col = 0; col < COLS; col++)
			{
				if (boardMain[row][col] == 'X')
				{
					if (boardMain[(row + 1)][col] != 'X')
					{
						hasMovement = true;
						boardMain[(row + 1)][col] = 'X';
						boardMain[row][col] = ' ';
					}
				}
			}
		}
	}

	CopyMainToTemp();

	return hasMovement;
}

double TBase::ResolveLines(std::vector<int> lines)
{
	if (lines.empty())
		return 0;

	double scoreRatio = 1;
	if (lines.size() > 1) scoreRatio = lines.size() * 1.1;
	double score = lines.size() * scoreRatio * 100;

	for (auto row : lines)
	{
		for (int col = 0; col < COLS; col++)
		{
			boardMain[row][col] = ' ';
		}
	}

	return score;
}

