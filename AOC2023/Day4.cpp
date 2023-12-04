#include "Day4.h"
#include "Utils.h"
#include <iostream>


void Day4()
	{
	std::string Contents = FileGetContents("Day4.txt");
	std::vector<std::string> Lines = Explode('\n', Contents);
	int CardTotal = 0;
	int Total = 0;
	int CardNum = 1;
	
	
	for (std::string Line : Lines)
		{
		Line = Line.substr(Line.find(':') + 1);
		std::vector<std::string> Cards = Explode('|', Line);
		std::vector<std::string> SWinners = Explode(' ', Cards[0]);
		std::vector<std::string> SMyNums = Explode(' ', Cards[1]);
		int c = 0;
		std::vector<int> IWinners;
		std::vector<int> IMyNums;
		for (std::string SWinner : SWinners)
			{
			SWinner = Trim(SWinner); 
			IWinners.push_back(stoi(SWinner));
			}
		for (std::string SMyNum : SMyNums)
			{
			SMyNum = Trim(SMyNum); 
			IMyNums.push_back(stoi(SMyNum));
			}
		for (int i = 0; i < IWinners.size(); i++)
			{
			for (int MyNum : IMyNums)
				{
				if (MyNum == IWinners[i])
					{
					if (CardTotal == 0)
						CardTotal = 1;
					else
						CardTotal *= 2;
					break;
					}
				}
			}
		Total += CardTotal;
		CardNum++;
		CardTotal = 0;
  }
	std::cout << "Total: " << Total << std::endl;


	//Part 2
		struct Game
		{
		std::vector<int>Winners;
		std::vector<int>MyNums;
		};

	std::vector<Game> GameList;
	GameList.resize(199);
	int GameNum = 1;
	for (std::string Line : Lines)
		{
		Line = Line.substr(Line.find(':') + 1);
		std::vector<std::string> Cards = Explode('|', Line);
		std::vector<std::string> SWinners = Explode(' ', Cards[0]);
		std::vector<std::string> SMyNums = Explode(' ', Cards[1]);
		int c = 0;
		std::vector<int> IWinners;
		std::vector<int> IMyNums;
		for (std::string SWinner : SWinners)
			{
			SWinner = Trim(SWinner);
			IWinners.push_back(stoi(SWinner));
			}
		for (std::string SMyNum : SMyNums)
			{
			SMyNum = Trim(SMyNum);
			IMyNums.push_back(stoi(SMyNum));
			}
		Game CurrentGame;
		CurrentGame.Winners = IWinners;
		CurrentGame.MyNums = IMyNums;
		GameList[GameNum] = CurrentGame;
		GameNum++;
		}
 std::vector<int> CardStacks(199, 1);
	for (int i = 1; i <= 198; i++)
		{
		int NumWinners = 0;
		int Mult = CardStacks[i];
		for (int Winner : GameList[i].Winners)
			{
			for (int MyNum : GameList[i].MyNums)
				{
				if (MyNum == Winner)
					{
					NumWinners++;
					break;
					}
				}
			}
		if (NumWinners == 0)
			continue;
		for (int j = 1; j <= NumWinners; j++)
			{
			CardStacks[i + j] += Mult;
			}
  }

 int StackTotal = 0;
 for (int k = 1; k < CardStacks.size(); k++)
		StackTotal += CardStacks[k];
	std::cout << "Stack Total: " << StackTotal << std::endl;

	}