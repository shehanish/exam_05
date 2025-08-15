/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:16:14 by shkaruna          #+#    #+#             */
/*   Updated: 2025/08/07 14:39:53 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class vect2 
{
	private:
		int x, y;
		
	public:
		vect2() : x(0), y(0) {};
		vect2(int x, int y) : x(x), y(y) {};
		vect2(const vect2& oth) : x(oth.x), y(oth.y) {};
		
		//Assigment operator 
		vect2&	operator=(const vect2& oth)
		{
			if(*this != oth)
			{
				x = oth.x;
				y = oth.y;
			}
			return *this;
		}
		
		//subscript operator (non - const)
		int&	operator[](int i)
		{
			return (i == 0 ? x : y);
		}
		
		//subscript operator (const)
		int	operator[](int i) const
		{
			return (i == 0 ? x : y);
		}
		
		//output operator 
		friend std::ostream& operator<<(std::ostream& os, const vect2& v)
		{
			os << "{" << v[0] << ", " << v[1] << "}";
			return os;
		}
		
		//Postfix++
		vect2	operator++(int)
		{
			vect2 tmp = *this;
			x++;
			y++;
			return tmp;
		}
		
		//Prefix++
		vect2&	operator++()
		{
			x++;
			y++;
			return *this;
		}
		
		//Postfix--
		vect2	operator--(int)
		{
			vect2	tmp = *this;
			x--;
			y--;
			return tmp;
		}
		
		//Prefix--
		vect2& 	operator--()
		{
			x--;
			y--;
			return *this;
		}
		
		//operator+
		vect2	operator+(const vect2& oth) const 
		{
			return vect2(x + oth.x, y + oth.y);
		}
		
		//Operator-
		vect2	operator-(const vect2& oth) const
		{
			return vect2(x - oth.x, y - oth.y);
		}
		
		//operator+=
		vect2& 	operator+=(const vect2& oth)
		{
			x += oth.x;
			y += oth.y;
			return *this;
		}
		
		//operator-=
		vect2&	operator-=(const vect2& oth)
		{
			x -= oth.x;
			y -= oth.y;
			return *this;
		}
		
		//Scalar*
		vect2	operator*(int s) const
		{
			return vect2(x * s, y * s);
		}
		
		//Scalar *=
		vect2&	operator*=(int s)
		{
			x *= s;
			y *= s;
			return *this;
		}
		
		//unary minus
		vect2	operator-()
		{
			return vect2(-x, -y);
		}
		
		//Scalar * vector
		friend vect2	operator*(int s, const vect2& v)
		{
			return vect2(v.x * s, v.y * s);
		}
		
		//Comparison operators
		bool	operator==(const vect2& oth) 
		{
			return (x == oth.x && y == oth.y);
		}
		
		bool	operator!=(const vect2& oth)
		{
			return !(x == oth.x && y == oth.y);
		}
		
};

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
				
		
		
		
		
		
		
		
