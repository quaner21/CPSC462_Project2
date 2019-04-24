#pragma once

#include<vector>

class PulseRecord {
public:
	PulseRecord();
	void readin_data();
	void save_hourly_measurement(int);
	void generate_daily_report();
	void generate_weekly_report();
	void generate_monthly_report();

private:
	std::vector<int> pulse_data;
	//void clear_records(SysTime);
};