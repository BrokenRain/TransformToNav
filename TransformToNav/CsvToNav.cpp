#include "CsvToNav.h"

CsvToNav::CsvToNav(map<int, ShotData_Csv> &Navmap)
{
	this->Navmap = Navmap;
}

CsvToNav::CsvToNav()
{
	
}


CsvToNav::~CsvToNav()
{
}

bool CsvToNav::ReadShot()
{
	ifstream TransFormFile(TransFormFileName, ios::app);

	if (!TransFormFile)
		return false;

	char Dat[400] = { 0 };
	string str = "";

	int StartFlag = 0;

	while (!TransFormFile.eof())
	{
		int ShowFlag = 0;
		
		memset(Dat, 0, sizeof(Dat));
		TransFormFile.getline(Dat, 400);
		StartFlag++;

		if (StartFlag <= 6 || Dat[0] == '\0')
		{
			continue;
		}

		ShotData_Csv SD;

		for (int i = 0; i < sizeof(Dat); i++)
		{
			if (Dat[i] != ',' && Dat[i] != '\0' && Dat[i] != '\n' && Dat[i] != ' ')
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
				}
				break;
				case 5:
				{
					SD.SMilliSecond = str.substr(11, 6);
					str = "";
				}
				break;
				case 15:
				{
					SD.Latitude = str;
					str = "";
				}
				break;
				case 16:
				{
					SD.Longitude = str;
					str = "";
					Navmap.insert(pair<int, ShotData_Csv>(SD.Shot, SD));
				}
				break;
				default:
				{
					str = "";
				}
				break;
				}
			}
		}
	}
	return true;
}

bool CsvToNav::TransForm()
{
	if ((_access(SaveFileName.c_str(), 0)) != -1)		//ÎÄ¼þ´æÔÚ
	{
		remove(SaveFileName.c_str());
	}
	ofstream NavFile(SaveFileName, ios::app);

	if (!NavFile)
		return false;

	NavFile << "#Shotnb			Date		       Time          Latitude£¨Z£©	Longitude£¨Z£©" << endl;

	map<int, ShotData_Csv>::iterator it;

	it = Navmap.begin();
	for (; it != Navmap.end(); it++)
	{
		ShotData_Csv sd = it->second;

		string STime = sd.STime + "." + sd.SMilliSecond;

// 		NavFile << sd.Shot << "   " << sd.SData << "			" << STime << "			"
// 			<< sd.Latitude << "			 " << sd.Longitude << endl;

		NavFile << sd.Shot << "   " << sd.SData << "			" << STime << "			"
			 	<< 0 << "			 " << 0 << endl;

	}
	/*
	it = --Navmap.end();
	map<int, ShotData_Csv>::iterator it1;
	it1 = --Navmap.begin();

	int b = 1386;

	for (; it != it1; it--)
	{
		ShotData_Csv sd = it->second;

		string STime = sd.STime + "." + sd.SMilliSecond;

		NavFile << b++ << "   " << sd.SData << "			" << STime << "			"
			<< 0 << "			 " << 0 << endl;
	}
	*/
	return true;
}