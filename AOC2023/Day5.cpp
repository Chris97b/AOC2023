#include "Day5.h"

bool InRange(long long Start, long long Size, long long Num);


struct Map
	{
	long long SourceStart;
 long long TargetStart;
 long long Size;
	};

void Day5()
	{
	std::string Contents = FileGetContents("Day5.txt");
	std::vector<std::string> Lines = Explode('\n', Contents);
	std::string Seeds = Lines[0].substr(Lines[0].find(':')+2);
	std::vector<std::string> SeedArr = Explode(' ', Seeds, true);
	std::vector<Map> SeedToSoilMap;
	std::vector<Map> SoilToFertMap;
	std::vector<Map> FertToWaterMap;
	std::vector<Map> WaterToLightMap;
	std::vector<Map> LightToTempMap;
	std::vector<Map> TempToHumidMap;
	std::vector<Map> HumidToLocMap;
	std::vector<Map>* CurrentMap = nullptr;
	for (int i = 1; i < Lines.size(); i++)
		{
		if (Lines[i].substr(0, Lines[i].find(' ')) == "seed-to-soil")
			CurrentMap = &SeedToSoilMap;
		if (Lines[i].substr(0, Lines[i].find(' ')) == "soil-to-fertilizer")
			CurrentMap = &SoilToFertMap;
		if (Lines[i].substr(0, Lines[i].find(' ')) == "fertilizer-to-water")
			CurrentMap = &FertToWaterMap;
		if (Lines[i].substr(0, Lines[i].find(' ')) == "water-to-light")
			CurrentMap = &WaterToLightMap;
		if (Lines[i].substr(0, Lines[i].find(' ')) == "light-to-temperature")
			CurrentMap = &LightToTempMap;
		if (Lines[i].substr(0, Lines[i].find(' ')) == "temperature-to-humidity")
			CurrentMap = &TempToHumidMap;
		if (Lines[i].substr(0, Lines[i].find(' ')) == "humidity-to-location")
			CurrentMap = &HumidToLocMap;
		if (isdigit(Lines[i].at(0)))
			{
			std::vector<std::string> Nums = Explode(' ', Lines[i], true);
			if(CurrentMap != nullptr)
			 CurrentMap->push_back({ stoll(Nums[1]), stoll(Nums[0]), stoll(Nums[2]) });
			}
		}

	long long LowestLoc = 0;
	long long LLS = 0;
	long long Insanity = 0;
	for (int i = 0; i < SeedArr.size(); i += 2)
		{
		for (long long j = stoll(SeedArr[i]); j <= (stoll(SeedArr[i]) + stoll(SeedArr[i + 1])); j++)
			{
			Insanity++;
			long long SeedNum = j;
			long long Soil = -1, Fert = -1, Water = -1, Light = -1, Temp = -1, Humid = -1, Loc = -1;
			for (Map M : SeedToSoilMap)
				{
				if (InRange(M.SourceStart, M.Size, SeedNum))
					{
					long long Offset = SeedNum - M.SourceStart;
					Soil = M.TargetStart + Offset;
					break;
					}
				}
			if (Soil == -1)
				Soil = SeedNum;
			for (Map M : SoilToFertMap)
				{
				if (InRange(M.SourceStart, M.Size, Soil))
					{
					long long Offset = Soil - M.SourceStart;
					Fert = M.TargetStart + Offset;
					break;
					}
				}
			if (Fert == -1)
				Fert = Soil;
			for (Map M : FertToWaterMap)
				{
				if (InRange(M.SourceStart, M.Size, Fert))
					{
					long long Offset = Fert - M.SourceStart;
					Water = M.TargetStart + Offset;
					break;
					}
				}
			if (Water == -1)
				Water = Fert;

			for (Map M : WaterToLightMap)
				{
				if (InRange(M.SourceStart, M.Size, Water))
					{
					long long Offset = Water - M.SourceStart;
					Light = M.TargetStart + Offset;
					break;
					}
				}
			if (Light == -1)
				Light = Water;
			for (Map M : LightToTempMap)
				{
				if (InRange(M.SourceStart, M.Size, Light))
					{
					long long Offset = Light - M.SourceStart;
					Temp = M.TargetStart + Offset;
					break;
					}
				}
			if (Temp == -1)
				Temp = Light;
			for (Map M : TempToHumidMap)
				{
				if (InRange(M.SourceStart, M.Size, Temp))
					{
					long long Offset = Temp - M.SourceStart;
					Humid = M.TargetStart + Offset;
					break;
					}
				}
			if (Humid == -1)
				Humid = Temp;
			for (Map M : HumidToLocMap)
				{
				if (InRange(M.SourceStart, M.Size, Humid))
					{
					long long Offset = Humid - M.SourceStart;
					Loc = M.TargetStart + Offset;
					break;
					}
				}
			if (Loc == -1)
				Loc = Humid;
			if (LowestLoc == 0)
				LowestLoc = Loc;
			else if (Loc < LowestLoc)
				{
				LowestLoc = Loc;
				LLS = SeedNum;
				std::cout << " New Lowest Seed:" << SeedNum << " Soil:" << Soil << " Fert:" << Fert << " Water:" << Water << " Light:" << Light << " Temp:" << Temp << " Humid:" << Humid << " Loc:" << Loc << std::endl;
				}
			if (Insanity % 100000000 == 0)
				std::cout << "Insanity Level: " << floor(Insanity / 1000000) << std::endl;
			}
		}

	std::cout << "LowestLoc: " << LowestLoc << " - " << LLS << std::endl;
	std::cout << "Insanity: " << Insanity << std::endl;

	}


bool InRange(long long Start, long long Size, long long Num)
	{
	return (Num >= Start && Num <= (Start + Size -1));
	}