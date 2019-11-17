#include "Date.h"

Date::Date() : d(1), m(1), y(2019)
{

}

Date::Date(unsigned int day, unsigned int month, unsigned int year): Date()
{
	if (day > 31 || day < 1)
		printf("Invalid day parameter, it should be between 1 - 31.\n");
	else
		d = day;

	if (m > 12 || m < 1)
		printf("Invalid month parameter, it should be between 1 - 12.\n");
	else
		m = month;

	if (year > 9999 || year < 1000)
		printf("Invalid year parameter, it should between 1000 - 9999.\n");
	else
		y = year;
}

bool Date::isLeapYear() const
{
	if (((y % 4 == 0) && (y % 100 != 0)) || ((y % 100 == 0) && (y % 400 == 0)) || (y % 400 == 0))
	{
		return true;
	}
	return false;
}

Date& Date::operator++()
{
	if (d < 31)
		d++;
	else if (m < 12)
	{
		m++;
		d = 1;
	}
	else
	{
		d = 1;
		m = 1;
		y++;
	}

	return *this;
}

Date Date::operator++(int)
{
	Date old(d, m, y);

	if (d < 31)
		d++;
	else if (m < 12)
	{
		m++;
		d = 1;
	}
	else
	{
		d = 1;
		m = 1;
		y++;
	}


	return old;
}

Date& Date::operator--()
{
	if (d > 1)
		d--;
	else if (m > 1)
	{
		m--;
		d = 31;
	}
	else
	{
		d = 31;
		m = 12;
		y--;
	}

	return *this;
}

Date Date::operator--(int)
{
	Date old(d, m, y);

	if (d > 1)
		d--;
	else if (m > 1)
	{
		m--;
		d = 31;
	}
	else
	{
		d = 31;
		m = 12;
		y--;
	}

	return old;
}

bool Date::operator<(const Date& other) const
{
	// return true if this date is before other, false otherwise
	if (y < other.y) {
		printf("y\n");
		return true;
	}
	else if (m < other.m && y == other.y) {
		printf("m\n");
		return true;
	}
	else if (d < other.d && y == other.y && m == other.m) {
		printf("d\n");
		return true;
	}

	return false;
}

bool Date::operator==(const Date& other) const
{
	// return true if this date is equal to other, false otherwise
	
	if (y == other.y && m == other.m && d == other.d)
		return true;

	return false;
}

Date::operator string() const
{
	// return a string of the form "2nd November 2019"

	// Day str
	std::string res = std::to_string(d);
	if (d == 1)
		res += "st";
	else
		res += "nd";

	// Month str
	std::string arr_Months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	if (m > 0 || m <= 12)
	{
		res += ' ' + arr_Months[m - 1];
	}

	// Year str
	res += ' ' + std::to_string(y);

	return res;
}

ostream& operator<<(ostream& o, const Date& d)
{
	// output date in format dd/mm/yyyy, e.g. 02/11/2019
	std::string res;
	
	// Day str
	if (d.d < 10)
		res += '0';
	res += std::to_string(d.d) + '/';

	// Month str
	if (d.m < 10)
		res += '0';
	res += std::to_string(d.m) + '/';

	// Year str
	res += std::to_string(d.y);

	o << res;

	return o;
}

bool operator<=(const Date& d1, const Date& d2)
{
	// return true if d1 is equal to or before d2, false otherwise
	if (d1 == d2 || d1 < d2)
		return true;

	return false;
}

bool operator>(const Date& d1, const Date& d2)
{
	printf_s("what\n");
	// return true if d1 is after then d2
	if (d2 < d1)
		return true;

	return false;
}

bool operator!=(const Date& d1, const Date& d2)
{
	// return true if not equal
	if (d1 == d2)
		return false;

	return true;
}

bool operator>=(const Date& d1, const Date& d2)
{
	// return true if d1 is after d2 or equal
	if (d2 < d1 || d1 == d2)
		return true;

	return false;
}
