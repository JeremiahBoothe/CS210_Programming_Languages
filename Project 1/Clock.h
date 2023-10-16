#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED
#include <string>

void addHour(int&);
void addSecond(int&, int&, int&);
void addMinute(int&, int&);

int rolloverSeconds(int&, int&, int&);
int rolloverMinutes(int&, int&);

std::string get12HourFormat(unsigned int, unsigned int, unsigned int);
std::string get24HourFormat(unsigned int, unsigned int, unsigned int);

std::string twoDigit(std::string&);

#endif