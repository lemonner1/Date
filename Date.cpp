#include <iostream>
#include "Date.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 1970;
}
Date::Date(int day_, int month_, int year_)
{
	day = day_;
	month = month_;
	year = year_;
};
Date::Date(const Date& obj)
{
	day = obj.day;
	month = obj.month;
	year = obj.year;
}
int Date::GetDay()
{
	return day;
}
int Date::GetMonth()
{
	return month;
}
int Date::GetYear()
{
	return year;
}
bool Date::Correct(int day_, int month_, int year_)
{
	if (year >= 1970 && year <= 2099)
	{
		if (month >= 1 && month <= 12)
		{
			if (day >= 1 && day <= 31 && DaysInMonth(year, day))
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::WhatIsYear(int year_)
{
	if (year_ % 4 == 0)
	{
		return true;
	}
	return false;
}
int Date::DaysInMonth(int year_, int month_)
{
	int day_ = 30;
	if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
	{
		day_ = 31;
	}
	if (month_ == 2)
	{
		day_ = 28;
		if (WhatIsYear(year_))
			day_ = 29;
	}
	return day_;
}
std::ostream& operator<<(std::ostream& stream, const Date& obj)
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			stream << "0" << obj.day;
		else if (i == 1)
			stream << "0" << obj.month;
		else if (i == 2)
			stream << obj.year;
	}

	return stream;
}

int main()
{
	std::cout << Date(21, 02, 2001);
	return 0;
}