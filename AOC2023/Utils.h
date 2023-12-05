#pragma once
#include <string>
#include <vector>
#include <iostream>



int IsNum(std::string S, int Pos);
std::vector<std::string> Explode(char D, std::string S, bool T = false);
std::string FileGetContents(std::string Filename);
std::string Trim(std::string Input);