#pragma once
#include <iostream>
#include <string>


class Robot {
	private :
		std::string name;
		std::string type;
		double price;
	public :
		Robot();
		Robot( std::string  n,  std::string  t, double p);
		std::string getName() const;
		bool operator<(const Robot & other) const;
		friend std::ostream & operator<<(std::ostream & out, const Robot & p);
		friend std::istream & operator>>(std::istream & in, Robot & p);
};
