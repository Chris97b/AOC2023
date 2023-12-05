#include "Utils.h"
#include <fstream>



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


std::vector<std::string> Explode(char D, std::string S, bool T)
	{
	std::vector<std::string> V;
	std::string Buf = "";
	for (int i = 0; i < S.length(); i++)
		{
		if (S.at(i) == D)
			{
			if (Buf.size() > 0)
				{
				if (T)
					Buf = Trim(Buf);
				V.push_back(Buf);
				}
			Buf = "";
			}
		else
			Buf.append(1, S.at(i));
		}
	if (Buf.size() > 0)
		{
		if (T)
			Buf = Trim(Buf);
		 V.push_back(Buf);
		}
	if (V[V.size() - 1] == "")
		V.pop_back();
	return V;
	}


std::string FileGetContents(std::string Filename)
	{
	std::ifstream Infile(Filename);
	std::string Contents = "";
	if (Infile.is_open())
		 Contents.assign((std::istreambuf_iterator<char>(Infile)), (std::istreambuf_iterator<char>()));
	Infile.close();
	return Contents;
	}


std::string Trim(std::string Input)
	{
	if (Input.size() == 0)
		return Input;
	if (Input.at(0) == ' ')
		Input = Input.substr(1);
	if (Input.at(Input.size()-1) == ' ')
	 Input = Input.substr(0, Input.size() - 2);
	return Input;
	}