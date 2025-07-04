
#pragma once
#include <iostream>
#include <algorithm>
#include <string>

class bigint
{
	private:
		std::string num;

	//Constructors and assigments 
	public:
		bigint(size_t n) : num(std::to_string(n)) {}

		bigint() : num("0") {}

		bigint(const bigint& oth) : num(oth.num) {}

		bigint(const std::string& n)
		{
			if(n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit))
		}
}