#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

struct decData
{
	string Label;			//转换后保存文件名
	int FirstShot;			//第一炮
	int LastShot;			//最后一炮
	int ShotDelay;			//放炮后延时多少ms取数据
	int SourceDepth;		//来源深度		
	int OBSDepth;			//OBS深度
	int LatOBS;				//OBS纬度
	int LonOBS;				//OBS经度
	int RecordLength;		//取放炮后多少ms数据
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

