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
	std::ifstream pulse_data("pulse_data.txt", std::ios::in);

	if (!pulse_data) {
		std::cout << "Could not open file" << std::endl;
	}

	int pulse;
	while (pulse_data >> pulse) {
		pulse_data.putback(pulse);
	}

	pulse_data.close();
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

//void PulseRecord::clear_records(SysTime current_time) {
//	if (current_time.get_sys_time_hour() == 0 && current_time.get_sys_time_minute() == 0 && current_time.get_sys_time_second() == 0)
//		hourly_measurements[24] = { 0 };
//}

//int main() {
//	srand(time(NULL));
//
//	PulseRecord record;
//
//	//int sensor_signal = rand() % 50 + 56;  // random number between 56-105
//	//SysTime current_time(17, 28, 52);  // hard coded
//	//bool user_request_measurement = true;
//
//	//if (current_time.system_time_oclock() || user_request_measurement) {
//	//	record.get_current_measurement(sensor_signal, current_time);
//	//}
//
//	system("pause");
//	return 0;
//}