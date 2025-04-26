#pragma once

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <synchapi.h> 

#include "TBase.h"
#include "KBResult.h"
#include <string>

    
class TEngine
{

private:
	BlockBase blockCurrent;
	int lastBlockUsed = 0;
	BlockBase blocks[4] ;
	bool doWork = true;
	TBase * tbase;
	KBResult pressed = KBResult::NONE;
	DWORD engineTimeout = 1000;
	DWORD engineTimeoutHighSpeed = 100;

private:
	void DetectKB();
	void CheckPause();
	void PrintLine(char item);
	void PrintLineWithPipe(char item);
	void PrintLine(char item[]);
	std::string ResolveKB();
	void PrintEL( );
	BlockBase GenerateNextBlock();
public:

public:
	TEngine(DWORD _engineTimeout = 1000, DWORD _engineTimeoutHighSpeed = 100);
	~TEngine();
	int Run();

	void ShowBoard();

};

