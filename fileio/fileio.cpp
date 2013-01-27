// fileio.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <Windows.h>

using namespace System;
using namespace std;

void logMessage(const string& msg);

int main(array<System::String ^> ^args)
{
	ifstream dataFile("numbers.dat");

	const int DATA_SIZE = 10;
	int dataArray[DATA_SIZE];

	if(dataFile.fail()) {
		cerr << "open fail" << endl;
		exit(8);
	}

	int total = 0;
	int i = 0;
	for (i = 0; i < DATA_SIZE; i++)
	{
		assert(i >= 0);
		assert(i < static_cast<int>(sizeof(dataArray)/sizeof(dataArray[0])));
		dataFile >> dataArray[i];

		total += dataArray[i];
	}
	
	cout << total << endl;

    Console::WriteLine(L"finish");

	logMessage("log");

	Sleep(100000);

    return 0;
}

void logMessage(const string& msg)
{
	ofstream outFile("data.log", ios::out|ios::app|ios::ate);
	if (outFile.fail()) {
		cerr << "data.log open fail" << endl;
		return;
	}
	
	outFile << msg.c_str() << endl;
}
