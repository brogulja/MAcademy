#pragma once
#include "BlockBase.h"
#include <vector>

class TBase
{
private:
	bool isStopped = false;
	int lastPosition = 0;
	int maxPosition = 20;
	void ClearMain();
	void ClearTemp();
	void CopyMainToTemp();
	double ResolveLines(std::vector<int> lines);
	bool    ResolveLineMovement();
public:
	static const int ROWS = 20;
	static const int COLS = 10;
	char boardMain[ROWS][COLS];
	char boardTemp[ROWS][COLS];
	TBase();

	double GoDown(BlockBase* block);
	bool IsDone() { return isStopped; }

};

