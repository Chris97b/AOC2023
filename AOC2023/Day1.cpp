#include <fstream>
#include <string>
#include <iostream>
#include "Day1.h"
#include "Utils.h"

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
