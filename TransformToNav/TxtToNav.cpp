#include "TxtToNav.h"


TxtToNav::TxtToNav(map<int, ShotData> &Navmap)
{
	this->Navmap = Navmap;
}

TxtToNav::TxtToNav()
{
}


TxtToNav::~TxtToNav()
{
}

bool TxtToNav::ReadShot()
{
	ifstream TransFormFile(TransFormFileName, ios::app);

	if (!TransFormFile)
		return false;

	char Dat[40] = { 0 };
	string str = "";

	while (!TransFormFile.eof())
	{
		int ShowFlag = 0;
		TransFormFile.getline(Dat, 40);

		ShotData SD;
		SD.Num = Dat[4] - '0';

		for (int i=6;i<sizeof(Dat);i++)
		{
			if (Dat[i] != ',' && Dat[i] != '\0' && Dat[i] != '\n')
			{
				str += Dat[i];
			}
			else
			{
				ShowFlag++;
				switch (ShowFlag)
				{
				case 1:
				{
					SD.Shot = atoi(str.c_str());
					str = "";
				}
				break;
				case 2:
				{
					SD.SData = str;
					str = "";
				}
				break;
				case 3:
				{
					SD.STime = str;
					str = "";
					Navmap.insert(pair<int, ShotData>(SD.Shot, SD));
				}
				break;
				}
			}
		}
	}
	return true;
}

bool TxtToNav::TransForm()
{
	if ((_access(SaveFileName.c_str(), 0)) != -1)		//ÎÄ¼þ´æÔÚ
	{
		remove(SaveFileName.c_str());
	}
	ofstream NavFile(SaveFileName, ios::app);

	if (!NavFile)
		return false; 

	NavFile << "#Shotnb			Date		       Time          Latitude£¨Z£©	Longitude£¨Z£©" << endl;

	map<int, ShotData>::iterator it;

	it = Navmap.begin();
	for (; it != Navmap.end(); it++)
	{
		ShotData sd = it->second;

		string SData = sd.SData.substr(0, 2) + "/" + sd.SData.substr(2, 2) + "/" + "20" + sd.SData.substr(4, 2);
		string STime = sd.STime.substr(0, 2) + ":" + sd.STime.substr(2, 2) + ":" + sd.STime.substr(4, 2) + sd.STime.substr(6, 7);
		
		NavFile << sd.Shot << "   " << SData << "			" << STime << "			" 
				<< "0" << "			 " << "0" << endl;
	}
	return true;
}
