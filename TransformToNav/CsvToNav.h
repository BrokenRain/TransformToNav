#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "io.h"
#include "stdio.h"

using namespace std;

struct ShotData_Csv
{
	int Shot;				//炮点
	string SData;			//放炮时间 日月年	格林尼治时间
	string STime;			//放炮时间 时分秒	格林尼治时间
	string SMilliSecond;	//放炮时间 毫  秒	格林尼治时间
	string Latitude;		//经度
	string Longitude;		//纬度
};

class CsvToNav
{
public:
	CsvToNav();
	CsvToNav(map<int, ShotData_Csv> &Navmap);
	~CsvToNav();

	void SetTransFormFileName(string filename) { this->TransFormFileName = filename; }
	void SetSaveFileName(string filename) { this->SaveFileName = filename; }
	bool ReadShot();
	bool TransForm();
private:
	string TransFormFileName;
	string SaveFileName;
	map<int, ShotData_Csv> Navmap;
};

