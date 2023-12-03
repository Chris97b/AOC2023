#include "Day2.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Utils.h"


#define REDMAX 12
#define GREENMAX 13
#define BLUEMAX 14

void Day2()
	{
	std::ifstream Infile("Day2.txt");
	if (Infile.is_open())
		{
		std::string Line;
		int Total = 0;
		int GamePower = 0;
		int GameNum = 1;
		while (getline(Infile, Line))
			{
			Line = Line.substr(Line.find(':') + 2);
			std::vector <std::string> Games = Explode(';', Line);
			bool GamePossible = true;
			int RedMin = 0;
			int BlueMin = 0;
			int GreenMin = 0;
			for (int i = 0; i < Games.size(); i++)
				{
				std::vector<std::string>Cubes = Explode(',', Games[i]);
				for (int j = 0; j < Cubes.size(); j++)
					{
					if (Cubes[j].at(0) == ' ')
						Cubes[j] = Cubes[j].substr(1);
					std::string CountStr = Cubes[j].substr(0, Cubes[j].find(' '));
					int Count = std::stoi(CountStr);
					if (Cubes[j].substr(Cubes[j].find(' ') + 1, 3) == "red")
						{
						if (Count > REDMAX)
							GamePossible = false;
						if (Count > RedMin)
							RedMin = Count;
						}
					if (Cubes[j].substr(Cubes[j].find(' ') + 1, 4) == "blue")
						{
						if (Count > BLUEMAX)
							GamePossible = false;
						if (Count > BlueMin)
							BlueMin = Count;
						}
					if (Cubes[j].substr(Cubes[j].find(' ') + 1, 5) == "green")
						{
						if (Count > GREENMAX)
							GamePossible = false;
						if (Count > GreenMin)
							GreenMin = Count;
						}
					}
				}
			if (GamePossible)
				{
				Total += (GameNum);
				}
			GamePower += (RedMin * BlueMin * GreenMin);
			GameNum++;
			}
		std::cout << "Total: " << Total << std::endl;
		std::cout << "Power: " << GamePower << std::endl;
		}
	}



