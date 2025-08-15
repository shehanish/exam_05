#pragma once
#include <iostream>
#include <algorithm>
#include <string>

class bigint
{
	private:
		std::string num;
		bool	is_negative;
		
	public:
		//Default constructor
		bigint() : num("0") {};
		
		//Constructor from size-t 
		bigint(size_t n) : num(std::to_string(n)) {};
		
		//Copy constructor
		bigint(const bigint& oth) : num(oth.num) {};
		
		//Constuctor from string
		bigint(std::string n)
		{
			is_negative = false;
			if(n.empty())
			{
				num = "0";
				return;
			}
			if(n[0] == '-')
			{
				is_negative = true;
				n = n.substr(1);
			}
			else if(n[0] == '+')
			{
				n = n.substr(1);
			}
			if(!std::all_of(n.begin(), n.end(), ::isdigit))
			{
				std::cout << "Invalid string number" << std::endl;
				num = "0";
				is_negative = false;
				return;
			}
			n.erase(0, n.find_first_not_of('0'));
			num = n.empty() ? "0" : n;
			
			if( num == "0")
				is_negative = false;
		}
		
		//Assigment operator
		bigint&	operator=(const bigint& oth)
		{
			if(this != &oth)
			{
				num = oth.num;
			}
			return *this;
		}
		
		//Asigment from size_t
		bigint&	operator=(size_t n)
		{
			num = std::to_string(n);
			return *this;
		}
		
		//output operator
		friend	std::ostream&	operator<<(std::ostream& os, const bigint& b)
		{
			return os << b.num;
		}
		
		//Additional functions
			//Helper function
		std::string	add_strings(const std::string& n1, const std::string& n2) const
		{
			std::string result;
			int carry = 0, i = n1.size() - 1, j = n2.size() - 1;
			while(i >= 0 || j >= 0 || carry)
			{
				int sum = (i >= 0 ? n1[i--] - '0' : 0) + ( j >= 0 ? n2[j--] - '0' : 0) + carry;
				result.push_back(sum % 10 + '0');
				carry = sum /10;
			}
			std::reverse(result.begin(), result.end());
			return result;
		}
		
		//Increment operators
			//Prefix
		bigint	operator++()
		{
			return *this += bigint(1);
		}
		
			//postfix++
		bigint	operator++(int)
		{
			bigint tmp(*this);
			++(*this);
			return tmp;
		}
		
			//operator+
		bigint	operator+(const bigint& oth) const
		{
			return bigint(add_strings(num, oth.num));
		}
		
			//operator+=
		bigint&	operator+=(const bigint& oth)
		{
			num = add_strings(num, oth.num);
			return *this;
		}
		
		//Left and right shifts
			//Left and right shift
		bigint	operator<<(size_t shift) const
		{
			return bigint(num + std::string(shift, '0'));
		}
		
			//Inplace left shift
		bigint&	operator<<=(size_t shift)
		{
			num += std::string(shift, '0');
			return *this;
		}
		
			//right shift
		bigint	operator>>(const bigint& b) const
		{
			bigint result(*this);
			return result >>= b;
		}
		
			//In place right shift
		bigint&	operator>>=(const bigint& b) 
		{
			if(bigint(num.size()) <= b)
				num = "0";
			else
			{
				bigint i(0);
				while(i < b)
				{
					num = num.substr(0, num.size() - 1);
					++i;
				}
			}
			return *this;
		}
		
		//Comparison operator
		bool	operator<(const bigint& oth) const
		{
			if(num.size() < oth.num.size())
				return true;
			else if(num.size() > oth.num.size())
				return false;
			return num < oth.num;
		}
		
		bool	operator>(const bigint& oth) const
		{
			return oth < *this;
		}
		
		bool	operator==(const bigint& oth) const
		{
			return num == oth.num;
		}
		
		bool	operator!=(const bigint& oth) const
		{
			return num != oth.num;
		}
		
		bool	operator>=(const bigint& oth) const
		{
			return !(*this < oth);
		}
		
		bool	operator<=(const bigint& oth)const
		{
			return !(*this > oth);
		}
		
		bigint	operator-(const bigint& oth) const
		{
			(void)oth;
			return bigint();
		}
};

		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
	
		
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
