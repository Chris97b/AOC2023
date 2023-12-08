#include "Day7.h"
#include <algorithm>
#include <map>

bool CompareHands(const std::string& LHS, const std::string& RHS);
int CardToInt(char Card);
int JCount(std::string S);
bool JCompareHands(const std::string& LHS, const std::string& RHS);
int JCardToInt(char Card);


void Day7()
	{
	std::string Contents = FileGetContents("Day7.txt");
	std::vector<std::string> Lines = Explode('\n', Contents, true);
	std::vector<std::string> FiveOfAKind, Quads, Boat, Trips, TwoPair, Pair, HighCard;
	for (std::string Line : Lines)
		{
		std::vector<std::string> HandArr = Explode(' ', Line, true);
		std::string Hand = HandArr[0];
		int Bid = stoi(HandArr[1]);
		std::string SortedHand = Hand;
		std::sort(SortedHand.begin(), SortedHand.end());
		char Current = '0';
		int NumMatchGroups = 0;
		int MaxMatchGroup = 0;
		int Num = 0;
		for (int i = 0; i < 5; i++)
			{
			if (SortedHand.at(i) != Current)
				{
				if (Num > 1)
					NumMatchGroups++;
				Current = SortedHand.at(i);
				Num = 1;
				}
			else
				{
				Num++;
				if (Num > MaxMatchGroup)
					MaxMatchGroup = Num;
				}
			if (i == 4 && Num > 1)
				NumMatchGroups++;
			}
		if (MaxMatchGroup == 5)
			FiveOfAKind.push_back(Hand);
		else if (MaxMatchGroup == 4)
			Quads.push_back(Hand);
		else if (MaxMatchGroup == 3 && NumMatchGroups == 2)
			Boat.push_back(Hand);
		else if (MaxMatchGroup == 3)
			Trips.push_back(Hand);
		else if (MaxMatchGroup == 2 && NumMatchGroups == 2)
			TwoPair.push_back(Hand);
		else if (MaxMatchGroup == 2)
			Pair.push_back(Hand);
		else
			HighCard.push_back(Hand);

		}




	std::vector<std::string> JFiveOfAKind, JQuads, JBoat, JTrips, JTwoPair, JPair, JHighCard;

	for (std::string H : HighCard)
		{
		if (JCount(H) == 1)
			JPair.push_back(H);
		else
			JHighCard.push_back(H);
		}

	for (std::string H : Pair)
		{
		if (JCount(H) > 0)
			JTrips.push_back(H);
		else
			JPair.push_back(H);
		}

	for (std::string H : TwoPair)
		{
		int C = JCount(H);
		if (C == 2)
			JQuads.push_back(H);
		else if (C == 1)
			JBoat.push_back(H);
		else
			JTwoPair.push_back(H);
		}

	for (std::string H : Trips)
		{
		if (JCount(H) > 0)
			JQuads.push_back(H);
		else
			JTrips.push_back(H);
		}

	for (std::string H : Boat)
		{
		if (JCount(H) > 0)
			JFiveOfAKind.push_back(H);
		else
			JBoat.push_back(H);
		}

	for (std::string H : Quads)
		{
		if (JCount(H) > 0)
			JFiveOfAKind.push_back(H);
		else
			JQuads.push_back(H);
		}

	for (std::string H : FiveOfAKind)
		{
		JFiveOfAKind.push_back(H);
		}

	std::sort(FiveOfAKind.begin(), FiveOfAKind.end(), &CompareHands);
	std::sort(Quads.begin(), Quads.end(), &CompareHands);
	std::sort(Boat.begin(), Boat.end(), &CompareHands);
	std::sort(Trips.begin(), Trips.end(), &CompareHands);
	std::sort(TwoPair.begin(), TwoPair.end(), &CompareHands);
	std::sort(Pair.begin(), Pair.end(), &CompareHands);
	std::sort(HighCard.begin(), HighCard.end(), &CompareHands);


	std::sort(JFiveOfAKind.begin(), JFiveOfAKind.end(), &JCompareHands);
	std::sort(JQuads.begin(), JQuads.end(), &JCompareHands);
	std::sort(JBoat.begin(), JBoat.end(), &JCompareHands);
	std::sort(JTrips.begin(), JTrips.end(), &JCompareHands);
	std::sort(JTwoPair.begin(), JTwoPair.end(), &JCompareHands);
	std::sort(JPair.begin(), JPair.end(), &JCompareHands);
	std::sort(JHighCard.begin(), JHighCard.end(), &JCompareHands);


	long long Total = 0;
	int Mult = FiveOfAKind.size() + Quads.size() + Boat.size() + Trips.size() + TwoPair.size() + Pair.size() + HighCard.size();

	for (std::string H : FiveOfAKind)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				Total += (Bid * Mult);
				Mult--;
				}
			}
		}

	

	for (std::string H : Quads)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				Total += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : Boat)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				Total += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : Trips)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				Total += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : TwoPair)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				Total += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : Pair)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				Total += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : HighCard)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				Total += (Bid * Mult);
				Mult--;
				}
			}
		}

	std::cout << "P1 Total: " << Total << std::endl;


	long long JTotal = 0;
	Mult = FiveOfAKind.size() + Quads.size() + Boat.size() + Trips.size() + TwoPair.size() + Pair.size() + HighCard.size();

	for (std::string H : JFiveOfAKind)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				JTotal += (Bid * Mult);
				Mult--;
				}
			}
		}



	for (std::string H : JQuads)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				JTotal += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : JBoat)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				JTotal += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : JTrips)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				JTotal += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : JTwoPair)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				JTotal += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : JPair)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				JTotal += (Bid * Mult);
				Mult--;
				}
			}
		}

	for (std::string H : JHighCard)
		{
		for (int i = 0; i < Lines.size(); i++)
			{
			if (Lines[i].substr(0, 5) == H)
				{
				std::vector<std::string> HArr = Explode(' ', Lines[i]);
				int Bid = stoi(HArr[1]);
				JTotal += (Bid * Mult);
				Mult--;
				}
			}
		}

	std::cout << "P2 Total: " << JTotal << std::endl;

	}


bool CompareHands(const std::string& LHS, const std::string& RHS)
	{
	for (int i = 0; i < 5; i++)
		{
		int Card1 = CardToInt(LHS.at(i));
		int Card2 = CardToInt(RHS.at(i));
		if (Card1 > Card2)
			return true;
		else if (Card2 > Card1)
			return false;
		}
	return false;
	}

int CardToInt(char Card)
	{
	if (Card == 'T')
		Card = 58;
	if (Card == 'J')
		Card = 59;
	if (Card == 'Q')
		Card = 60;
	if (Card == 'K')
		Card = 61;
	if (Card == 'A')
		Card = 62;

	return Card;
	}

int JCount(std::string S)
	{
	int Count = 0;
	for (int i = 0; i < 5; i++)
		{
		if (S.at(i) == 'J')
			Count++;
		}
	return Count;
	}


bool JCompareHands(const std::string& LHS, const std::string& RHS)
	{
	for (int i = 0; i < 5; i++)
		{
		int Card1 = JCardToInt(LHS.at(i));
		int Card2 = JCardToInt(RHS.at(i));
		if (Card1 > Card2)
			return true;
		else if (Card2 > Card1)
			return false;
		}
	return false;
	}

int JCardToInt(char Card)
	{
	if (Card == 'T')
		Card = 58;
	if (Card == 'J')
		Card = 48;
	if (Card == 'Q')
		Card = 60;
	if (Card == 'K')
		Card = 61;
	if (Card == 'A')
		Card = 62;

	return Card;
	}