#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h> 
#include <chrono>
#include <ctime> 

#include "glucose.h"
#include "system_time.h"
#include "generate_report.h"

GlucoseRecord::GlucoseRecord() {
	glucose_data.clear();
}

void GlucoseRecord::readin_data() {
	std::ifstream glucose_data_input("glucose_data.txt", std::ios::in);

	if (!glucose_data_input) {
		std::cout << "Could not open file" << std::endl;
	}

	int glucose;
	while (glucose_data_input >> glucose) {
		glucose_data.push_back(glucose);
	}

	glucose_data_input.close();
}

// This function should run once every second in the system
void GlucoseRecord::save_hourly_measurement(int sensor_signal) {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	SysTime sys_time(now->tm_hour, now->tm_min, now->tm_sec);
	if (sys_time.system_time_oclock(sys_time)) {
		glucose_data.push_back(sensor_signal);
	}

	std::ofstream output_file;
	output_file.open("glucose_data.txt", std::ios::out | std::ios::app);

	output_file << sensor_signal << std::endl;
	output_file.close();
}

void GlucoseRecord::generate_daily_report() {
	std::cout << "Your daily glucose report: " << std::endl;
	ReportGenerator pulse_daily;
	pulse_daily.generate_report(glucose_data, 24);
}

void GlucoseRecord::generate_weekly_report() {
	std::cout << "Your weekly glucose report: " << std::endl;
	ReportGenerator pulse_weekly;
	pulse_weekly.generate_report(glucose_data, 168);
}

void GlucoseRecord::generate_monthly_report() {
	std::cout << "Your monthly glucose report: " << std::endl;
	ReportGenerator pulse_monthly;
	pulse_monthly.generate_report(glucose_data, 720);
}
