#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "io.h"
#include "stdio.h"

using namespace std;

struct ShotData
{
	int Num;				//信号输入口
	int Shot;				//炮点
	string SData;			//放炮时间 日月年	格林尼治时间
	string STime;			//放炮时间 时分秒	格林尼治时间		
};

class TxtToNav
{
public:
	TxtToNav();
	TxtToNav(map<int, ShotData> &Navmap);
	~TxtToNav();

	void SetTransFormFileName(string filename) { this->TransFormFileName = filename; }
	void SetSaveFileName(string filename) { this->SaveFileName = filename; }
	bool ReadShot();
	bool TransForm();
private:
	string TransFormFileName;
	string SaveFileName;
	map<int, ShotData> Navmap;
};