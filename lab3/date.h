#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int getYear() const;       // get the year
	int getMonth() const;      // get the month
	int getDay() const;        // get the day
	void next();               // advance to next day
	std::string toString();
	friend std::istream &operator>>(std::istream &input, Date &d);
	friend std::ostream &operator<<(std::ostream &output, const Date &d);
	static int daysPerMonth[12]; // number of days in each month
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
};

#endif
