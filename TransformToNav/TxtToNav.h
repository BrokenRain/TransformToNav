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
	int Num;				//�ź������
	int Shot;				//�ڵ�
	string SData;			//����ʱ�� ������	��������ʱ��
	string STime;			//����ʱ�� ʱ����	��������ʱ��		
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