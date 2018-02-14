#include <ctime>  // time and localtime
#include "date.h"

#include <sstream>
#include <iostream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

std::istream &operator>>(std::istream &input, Date &d){
	int year, month, day;
	char dash1, dash2;
	input >> year >> dash1 >> month >> dash2 >> day;
	if(year > 9999 || year < 0 || month > 12 || month < 1 || day > Date::daysPerMonth[month] || day < 1){
		input.setstate(std::ios_base::failbit);
	}
	//if(!input) input.setstate(std::ios_base::eofbit);
	d = Date(year, month, day);
	return input;
}

std::ostream &operator<<(std::ostream &output, const Date &d){
	return output << d.getYear() << "-" << d.getMonth() << "-" << d.getDay();
}

std::string Date::toString(){
	std::stringstream temp;
	temp << year << "-" << month << "-" << day;
	return temp.str();
}

void Date::next() {
	++day;
	if(day > daysPerMonth[month]){
		day = 1;
		if(month >= 12){
			year++;
			month = 1;
		}else{
			month++;
		}
	}
}

