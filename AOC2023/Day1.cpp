#include <fstream>
#include <string>
#include <iostream>
#include "Day1.h"

void Day1()
	{
	std::ifstream Infile("Day1.txt");
	long Total = 0;
	if (Infile.is_open())
		{
		std::string Line;
		int Temp;
		while (getline(Infile, Line))
			{
			int First = -1;
			int Last = -1;
			for (int i = 0; i < Line.length(); i++)
				{
				Temp = IsNum(Line, i);
				if (Temp > 0)
					{
					if (First == -1)
						First = Temp;
					Last = Temp;
					}
				}
			Total += (First * 10) + Last;
			}
		std::cout << "Total: " << Total << std::endl;
		}
	}


int IsNum(std::string S, int Pos)
	{
	if (isdigit(S.at(Pos)))
		return S.at(Pos) - '0';
	if (S.substr(Pos, 3) == "one")
		return 1;
	if (S.substr(Pos, 3) == "two")
		return 2;
	if (S.substr(Pos, 5) == "three")
		return 3;
	if (S.substr(Pos, 4) == "four")
		return 4;
	if (S.substr(Pos, 4) == "five")
		return 5;
	if (S.substr(Pos, 3) == "six")
		return 6;
	if (S.substr(Pos, 5) == "seven")
		return 7;
	if (S.substr(Pos, 5) == "eight")
		return 8;
	if (S.substr(Pos, 4) == "nine")
		return 9;
	return -1;
	}