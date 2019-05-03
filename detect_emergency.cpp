#include <iostream>
#include <string>
#include <ctime> 

#include "detect_emergency.h"
#include "contacts_dial.h"


int DetectEmergency::get_current_pulse() {
	int pseudo_sensor_signal = rand() % 50 + 56;  // sensor signal: random number between 56-105
	current_pulse = pseudo_sensor_signal;
	std::cout << "Current pulse: " << current_pulse << std::endl;

	return current_pulse;
}

int DetectEmergency::get_current_glucose() {
	int pseudo_sensor_signal = rand() % 90 + 61;  // sensor signal: random number between 61-150
	current_glucose = pseudo_sensor_signal;
	std::cout << "Current glucose: " << current_glucose << std::endl;

	return current_glucose;
}

bool DetectEmergency::detect_emergency() {
	get_current_pulse();
	get_current_glucose();
	if (current_pulse < 60 || current_pulse > 100 || current_glucose > 140 || current_glucose < 70) {
		std::cout << "Emergency! Abnormal pulse or glucose!" << std::endl;
		Dial dial_emergency;
		dial_emergency.dial_911();
		return true;
	}
	else
		return false;
}
