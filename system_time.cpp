#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime> 

#include "system_time.h"

SysTime::SysTime(int h, int m, int s) {
	system_time_hour = h;
	system_time_minute = m;
	system_time_second = s;
}

int SysTime::get_sys_time_hour() {
	return system_time_hour;
}

int SysTime::get_sys_time_minute() {
	return system_time_minute;
}

int SysTime::get_sys_time_second() {
	return system_time_second;
}

bool SysTime::system_time_oclock(SysTime t) {
	if (t.get_sys_time_minute() == 0 && t.get_sys_time_second() == 0)
		return true;
	else
		return false;
}

void SysTime::print_current_system_datetime() {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	std::cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< ' '
		<< now->tm_hour << ':'
		<< now->tm_min << ':'
		<< now->tm_sec
		<< "\n";
}

SysTime SysTime::get_current_sys_date() {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	SysTime sys_date(now->tm_year, now->tm_mon, now->tm_mday);
	return sys_date;
}

SysTime SysTime::get_current_sys_time() {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	SysTime sys_time(now->tm_hour, now->tm_min, now->tm_sec);
	return sys_time;
}

//int main() {
//	std::time_t t = std::time(0);   // get time now
//	std::tm* now = std::localtime(&t);
//
//	SysTime cur_time(now->tm_hour, now->tm_min, now->tm_sec);
//	cur_time.print_current_system_datetime();
//
//	bool isOclock = cur_time.system_time_oclock();
//	std::cout << isOclock << std::endl;
//	int hour = cur_time.get_sys_time_hour();
//	std::cout << hour << std::endl;
//	int min = cur_time.get_sys_time_minute();
//	std::cout << min << std::endl;
//	int sec = cur_time.get_sys_time_second();
//	std::cout << sec << std::endl;
//
//	system("pause");
//	return 0;
//}