#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

struct decData
{
	string Label;			//ת���󱣴��ļ���
	int FirstShot;			//��һ��
	int LastShot;			//���һ��
	int ShotDelay;			//���ں���ʱ����msȡ����
	int SourceDepth;		//��Դ���		
	int OBSDepth;			//OBS���
	int LatOBS;				//OBSγ��
	int LonOBS;				//OBS����
	int RecordLength;		//ȡ���ں����ms����
};

class DecFile
{
public:
	DecFile();
	~DecFile();

private:
	void SetFileName(string filename) { DecFileName = filename; }
	bool ReadDec();

private:
	string DecFileName;
};

