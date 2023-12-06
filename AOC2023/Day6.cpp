#include "Day6.h"


long long RaceTime(long long TotalTime, long long HeldTime);


void Day6()
	{
	//Inputs redacted per AOC requirements
	int R1Time = 0;
	int R1Record = 0;
	int R2Time = 0;
	int R2Record = 0;
	int R3Time = 0;
	int R3Record = 0;
	int R4Time = 0;
	int R4Record = 0;
	long long R5Time = 0;
	long long R5Record = 0;

	int R1Combos = 0;
	for (int i = 1; i < R1Time; i++)
		{
		if (RaceTime(R1Time, i) > R1Record)
			R1Combos++;
		}

	int R2Combos = 0;
	for (int i = 1; i < R2Time; i++)
		{
		if (RaceTime(R2Time, i) > R2Record)
			R2Combos++;
		}

	int R3Combos = 0;
	for (int i = 1; i < R3Time; i++)
		{
		if (RaceTime(R3Time, i) > R3Record)
			R3Combos++;
		}

	int R4Combos = 0;
	for (int i = 1; i < R4Time; i++)
		{
		if (RaceTime(R4Time, i) > R4Record)
			R4Combos++;
		}

	int Ans = R1Combos * R2Combos * R3Combos * R4Combos;
 std::cout << "Part1: " << Ans << std::endl;

	int R5Combos = 0;
	for (long long i = 1; i < R5Time; i++)
		{
		if (RaceTime(R5Time, i) > R5Record)
			R5Combos++;
		}
 std::cout << "Part 2: " << R5Combos << std::endl;
	
	}


long long RaceTime(long long TotalTime, long long HeldTime)
	{
	return ((TotalTime - HeldTime) * HeldTime);
	}