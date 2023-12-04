#include "Day3.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Utils.h"


struct Character
	{
	int LineNum;
	int Pos;
	};

struct PartNum
	{
	int Value;
	int LineNum;
	int StartPos;
	int EndPos;
	std::vector<Character> AdjacentCharacters;
	};


void Day3()
	{
	 std::string Contents = FileGetContents("Day3.txt");
	 std::vector<std::string> LineArr = Explode('\n', Contents);
		std::vector<PartNum> PossibleParts;
		
		//Parts
		for (int i = 0; i < LineArr.size(); i++)
			{
			for (int j = 0; j < LineArr[i].length(); j++)
				{
				if (isdigit(LineArr[i].at(j)))
					{
					PartNum Part;
					Part.LineNum = i;
					Part.StartPos = j;
					int EndPos = j;
					bool EndFound = false;
					while (!EndFound)
						{
						if (EndPos == LineArr[i].length() - 1)
							EndFound = true;
						else
							{
							if (isdigit(LineArr[i].at(EndPos + 1)))
								EndPos++;
							else
								EndFound = true;
							}
						}
					Part.Value = stoi(LineArr[i].substr(j, EndPos - j + 1));
					Part.EndPos = EndPos;
					std::vector<Character> AdjChars;
					if (Part.StartPos > 0)
						AdjChars.push_back({ Part.LineNum, Part.StartPos - 1 });
					if (Part.EndPos < LineArr[i].length()-1)
						AdjChars.push_back({ Part.LineNum, Part.EndPos + 1 });
					if (i > 0)
						{
						if (Part.StartPos > 0)
							AdjChars.push_back({ Part.LineNum - 1, Part.StartPos - 1 });
						if (Part.EndPos < LineArr[i].length()-1)
							AdjChars.push_back({ Part.LineNum - 1, Part.EndPos + 1 });
						AdjChars.push_back({ Part.LineNum - 1, Part.StartPos });
						int P = Part.StartPos + 1;
						while (P <= Part.EndPos)
							{
							AdjChars.push_back({ Part.LineNum - 1, P });
							P++;
							}
						}

					if (i < LineArr.size() - 1)
						{
						if (Part.StartPos > 0)
							AdjChars.push_back({ Part.LineNum + 1, Part.StartPos - 1 });
						if (Part.EndPos < LineArr[i].length()-1)
							AdjChars.push_back({ Part.LineNum + 1, Part.EndPos + 1 });
						AdjChars.push_back({ Part.LineNum + 1, Part.StartPos });
						int P = Part.StartPos + 1;
						while (P <= Part.EndPos)
							{
							AdjChars.push_back({ Part.LineNum + 1, P });
							P++;
							}
						}

					Part.AdjacentCharacters = AdjChars;

					PossibleParts.push_back(Part);
					j = EndPos + 1;
					}
				}
			}
		
		//Gears
		std::vector<Character> PossibleGears;
		for (int i = 0; i < LineArr.size(); i++)
			{
			for (int j = 0; j < LineArr[i].length(); j++)
				{
				if (LineArr[i].at(j) == '*')
					PossibleGears.push_back({ i, j });
				}
			}
		int Total = 0;
		for (int i = 0; i < PossibleParts.size(); i++)
			{
			for (int j = 0; j < PossibleParts[i].AdjacentCharacters.size(); j++)
				{
				int Line = PossibleParts[i].AdjacentCharacters[j].LineNum;
				int Pos = PossibleParts[i].AdjacentCharacters[j].Pos;
				if (LineArr[Line].at(Pos) != '.')
					{
					Total += PossibleParts[i].Value;
					break;
					}
				}
			}
		int GearTotal = 0;
		for (int i = 0; i < PossibleGears.size(); i++)
			{
			int AdjCount = 0;
			int TempTotal = 0;
			for (int j = 0; j < PossibleParts.size(); j++)
				{
				for (int k = 0; k < PossibleParts[j].AdjacentCharacters.size(); k++)
					{
					int Line = PossibleParts[j].AdjacentCharacters[k].LineNum;
					int Pos = PossibleParts[j].AdjacentCharacters[k].Pos;
					if (PossibleGears[i].LineNum == Line && PossibleGears[i].Pos == Pos)
						{
						AdjCount++;
						if (TempTotal == 0)
							TempTotal = PossibleParts[j].Value;
						else
							TempTotal *= PossibleParts[j].Value;
						}
					}
				}
			if (AdjCount == 2)
				GearTotal += TempTotal;
			}

		std::cout << "Parts Total: " << Total << std::endl;
		std::cout << "Gear Total: " << GearTotal << std::endl;

		}
