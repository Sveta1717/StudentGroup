#pragma once
#include "Libraries.h"


class Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;

public:
	Date(unsigned short day = 1, unsigned short month = 1, unsigned short year = 2000);

	void SetDay(unsigned short day);
	void SetMonth(unsigned short month);
	void SetYear(unsigned short year);

	const unsigned short GetDay() const;
	const unsigned short GetMonth() const;
	const unsigned short GetYear() const;
};

