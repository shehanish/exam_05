/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:16:14 by shkaruna          #+#    #+#             */
/*   Updated: 2025/08/05 17:54:38 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class vect2
{
	private:
		int x, y;
	
	public:
		//Default constructor
		vect2() : x(0), y(0) {};

		//Paramiterized constructor
		vect2(int x, int y) : x(x), y(y) {};

		//Copy constructor
		vect2(const vect2& oth) : x(oth.x), y(oth.y) {};

		//Assigment operator
		vect2&	operator=(const vect2& oth) 
		{
			if(*this != oth)
			{
				x = oth.x;
				y = oth.y;
				return *this;
			}
		}

		//Subscript operator (non - const)
		int&	operator[](int i)
		{
			return (i == 0 ? x : y);
		}
		
};