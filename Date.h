#pragma once

class Date
{
private:
	int day; int month; int year;
public:
	Date();
	Date(int day_, int month_, int year_);
	Date(const Date& obj);

	int GetDay();
	int GetMonth();
	int GetYear();
	bool Correct(int day_, int month_, int year_);
	bool WhatIsYear(int year_);
	int DaysInMonth(int year_, int month_);

	friend std::ostream& operator<<(std::ostream& stream, const Date& obj);
};