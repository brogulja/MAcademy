#pragma once
#include "KBResult.h"
#include "Point.h"
#include <wtypes.h>
#include <vector>

class BlockBase
{
private:
	void Init(char type);
	std::vector<POINT>  offsets; // = new std::vector<POINT>(3);
	 
public:
	std::vector<POINT> VisibleOffsetGet();
	char blocks[4][3][3]; // rotation, ROWS, COLS
	int rotation = 0; // 0=0, 1=90, 2=180, 3=270
	int Position_Vertical = 0;
	int Position_Horizontal = 3;
	char blockTemp = 'X';
	char thisBlock = ' ';
	 
	BlockBase(char c);
	BlockBase();
	~BlockBase() { 
		//delete(offsets);
	}
	 
	void Rotate(KBResult pressed);
	void Move(KBResult pressed);
	int GetMaxRight();
	void CalculatePosition(int rowOrigin, int colOrigin);
};

