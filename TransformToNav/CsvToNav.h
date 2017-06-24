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
	int Shot;				//�ڵ�
	string SData;			//����ʱ�� ������	��������ʱ��
	string STime;			//����ʱ�� ʱ����	��������ʱ��
	string SMilliSecond;	//����ʱ�� ��  ��	��������ʱ��
	string Latitude;		//����
	string Longitude;		//γ��
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

