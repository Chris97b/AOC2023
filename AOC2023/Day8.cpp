#include "Day8.h"
#include <map>
#include <numeric>

struct Node
	{
	std::string L;
	std::string R;
	};


void Day8()
	{
	std::string Contents = FileGetContents("Day8.txt");
	std::vector<std::string> LArr = Explode('\n', Contents, true);
	std::map<std::string, Node> MapNodes;
	std::vector<std::string> AllNodes;
	std::string InsStr = LArr[0];
	for (int i = 1; i < LArr.size(); i++)
		{
		std::string ID = LArr[i].substr(0, 3);
		std::string L = LArr[i].substr(LArr[i].find('(')+1, 3);
		std::string R = LArr[i].substr(LArr[i].find(',')+2, 3);
		Node N = { L, R };
		MapNodes[ID] = N;
		AllNodes.push_back(ID);
		}

	std::string Pos = "AAA";
	int Steps = 0;
	int Index = 0;
	do
		{
		if (InsStr.at(Index) == 'L')
			Pos = MapNodes[Pos].L;
		else
			Pos = MapNodes[Pos].R;
		Steps++;
		Index++;
		if (Index == InsStr.size())
			Index = 0;
		} while (Pos != "ZZZ");

		std::cout << "P1 Steps: " << Steps << std::endl;


		std::vector<std::string> GPos;
		long long GSteps = 0;
		Index = 0;
		for (std::string S : AllNodes)
			{
			if (S.at(2) == 'A')
				GPos.push_back(S);
			}



		GSteps = 0;
		int GIndex = 0;
		std::vector<int> GRes;
		for (std::string S : GPos)
			{
			GSteps = 0;
			GIndex = 0;
			do
				{
				if (InsStr.at(GIndex) == 'L')
					S = MapNodes[S].L;
				else
					S = MapNodes[S].R;
				GSteps++;
				GIndex++;
				if (GIndex == InsStr.size())
					GIndex = 0;
				} while (S.at(2) != 'Z');
				GRes.push_back(GSteps);
			}

		long long LCM = std::lcm(GRes[0], GRes[1]);
		for (int i = 2; i<GRes.size(); i++)
			{
			LCM = std::lcm(LCM, GRes[i]);
			}

		std::cout << "P2 Steps: " << LCM << std::endl;




	}