#pragma once

#include<vector>

class GlucoseRecord {
public:
	GlucoseRecord();
	void readin_data();
	void save_hourly_measurement(int);
	void generate_daily_report();
	void generate_weekly_report();
	void generate_monthly_report();

private:
	std::vector<int> glucose_data;
};