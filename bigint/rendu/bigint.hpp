
#pragma once
#include <iostream>
#include <algorithm>
#include <string>

class bigint
{
	private:
		std::string num;

	public:
		//Default constructor
		bigint() : num("0") {}

		//Constructor from size_t
		bigint(size_t n) : num(std::to_string(n)) {}

		//Copy constructor
		bigint(const bigint& oth) : num(oth.num) {}

		//Constructor from strings
		bigint(const std::string& n)
		{
			if(n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit) || (n.size() > 1 && n[0] == '0')) 
			{
				std::cout << "Invalid number strings" << std::endl;
				num = "0";
			}
			else
			{
				num = n;
			}
		}

		//Copy assigment operator
		bigint& operator=(const bigint& oth)
		{
			if(this != &oth)
			{
				num = oth.num;
			}
			return *this;
		}

		//Assigment from size_t
		bigint& operator=(size_t n)
		{
			num = std::to_string(n);
			return *this;
		}

		//Output operator 
		friend std::ostream& operator<<(std::ostream& os, const bigint& b)
		{
			return os << b.num;
		}

		//Additional Logic
		//Helper function to add two strings

		std::string add_strings(const std::string& n1, const std::string& n2)
		{
			std::string result;
			int carry = 0, i = n1.size() - 1, j = n2.size() - 1;
			while(i >= 0 || j >= 0 || carry)
			{
				int sum = (i >= 0 ? n1[i--] - '0' : 0) + (j >= 0 ? n2[j--] - '0' : 0) + carry;
				result.push_back(sum % 10 + '0');
				carry = sum / 10;
			}
			std::reverse(result.begin(), result.end());
			return (result);
		}

		//Comparison Operators
		bool	operator<(const bigint& oth) const
		{
			if(num.size() < oth.num.size())
				return (true);
			else if(num.size() > oth.num.size())
				return (false);
			return num < oth.num;
		}


};