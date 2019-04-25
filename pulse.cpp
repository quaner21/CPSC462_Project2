#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h> 
#include <chrono>
#include <ctime> 

#include "pulse.h"
#include "system_time.h"
#include "generate_report.h"

PulseRecord::PulseRecord() {
	pulse_data.clear();
}

void PulseRecord::readin_data() {
	std::ifstream pulse_data_input("pulse_data.txt", std::ios::in);

	if (!pulse_data_input) {
		std::cout << "Could not open file" << std::endl;
	}

	int pulse;
	while (pulse_data_input >> pulse) {
		pulse_data.push_back(pulse);
	}

	pulse_data_input.close();
}

// This function should run once every second in the system
void PulseRecord::save_hourly_measurement(int sensor_signal) {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	SysTime sys_time(now->tm_hour, now->tm_min, now->tm_sec);
	if (sys_time.system_time_oclock(sys_time)) {
		pulse_data.push_back(sensor_signal);
	}

	std::ofstream output_file;
	output_file.open("pulse_data.txt", std::ios::out | std::ios::app);

	output_file << sensor_signal << std::endl;
	output_file.close();
}

void PulseRecord::generate_daily_report() {
	for (std::vector<int>::iterator it = pulse_data.begin(); it != pulse_data.end(); ++it){ 
		std::cout << ' ' << *it;
	}

	std::cout << "Your daily pulse report: " << std::endl;
	ReportGenerator pulse_daily;
	pulse_daily.generate_report(pulse_data, 24);
}

void PulseRecord::generate_weekly_report() {
	std::cout << "Your weekly pulse report: " << std::endl;
	ReportGenerator pulse_weekly;
	pulse_weekly.generate_report(pulse_data, 168);
}

void PulseRecord::generate_monthly_report() {
	std::cout << "Your monthly pulse report: " << std::endl;
	ReportGenerator pulse_monthly;
	pulse_monthly.generate_report(pulse_data, 720);
}


int main() {
	srand(time(NULL));

	PulseRecord record;
	record.readin_data();
	record.generate_daily_report();

	system("pause");
	return 0;
}