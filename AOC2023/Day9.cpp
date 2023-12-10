#include "Day9.h"


std::vector<long long> GetDiffs(std::vector<long long> NumArr);
bool AllZero(std::vector<long long> NumArr);


void Day9()
	{
	std::string Contents = FileGetContents("Day9.txt");
	std::vector<std::string> LArr = Explode('\n', Contents, true);
	std::vector<long long> Nums;
	long long P1Total = 0;
	long long P2Total = 0;
	for (std::string Line : LArr)
		{
		Nums.clear();
		std::vector<std::string> NumStr = Explode(' ', Line, true);
		for (int i = 0; i < NumStr.size(); i++)
			{
			Nums.push_back(stoll(NumStr[i]));
			}

		std::vector<std::vector<long long>> Diffs;
		std::vector<long long>TDiff = Nums;
		do {
			TDiff = GetDiffs(TDiff);
			Diffs.push_back(TDiff);

			} while (!AllZero(TDiff));
						
			long long P2Temp = 0;
			for (int i = Diffs.size()-2; i >= 0; i--)
				{
				long long Current = Diffs[i].at(Diffs[i].size() - 1);
				long long Next = Diffs[i + 1].at(Diffs[i + 1].size() - 1);
				long long New = Current + Next;
				Diffs[i].push_back(New);
				long long P2Current = Diffs[i].at(0);
				P2Temp = P2Current - P2Temp;
				}

			P1Total += Nums.at(Nums.size() - 1) + Diffs[0].at(Diffs[0].size() - 1);
			P2Temp = Nums.at(0) - P2Temp;
			P2Total += P2Temp;
		}

	std::cout << "P1Total: " << P1Total << std::endl;
	std::cout << "P2Total: " << P2Total << std::endl;

	}



std::vector<long long> GetDiffs(std::vector<long long> NumArr)
	{
	std::vector<long long> RetVal;
	for (int i = 0; i < NumArr.size() - 1; i++)
		{
		RetVal.push_back(NumArr[i + 1] - NumArr[i]);
		}
	return RetVal;
	}


bool AllZero(std::vector<long long> NumArr)
	{
	bool Zero = true;
	for (long long L : NumArr)
		{
		if (L != 0)
			Zero = false;
		}
	return Zero;
	}