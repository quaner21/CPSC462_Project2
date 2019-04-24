#pragma once

class SysTime {
public:
	SysTime(int, int, int);
	int get_sys_time_hour();
	int get_sys_time_minute();
	int get_sys_time_second();
	bool system_time_oclock(SysTime);
	void print_current_system_datetime();
	SysTime get_current_sys_date(); // year, month, day
	SysTime get_current_sys_time(); // hour, minute, second

private:
	int system_time_hour;
	int system_time_minute;
	int system_time_second;
};