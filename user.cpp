#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "user.h"
#include "register_login.h"
#include "contacts_dial.h"
#include "pulse.h"
#include "glucose.h"
#include "location.h"
#include "detect_emergency.h"

void User::user_login(){
	Login login;
	login.login();
}

void User::user_make_calls(std::string contact) {
	Dial make_a_call;
	make_a_call.dial_contact(contact);
}

void User::user_dial_911() {
	Dial make_a_call;
	make_a_call.dial_911();
}

bool User::user_detect_emergency() {
	DetectEmergency situation1;
	return situation1.detect_emergency();
}

void User::user_generate_daily_pulse_repo() {
	PulseRecord record;
	record.readin_data();
	record.generate_daily_report();
}

void User::user_generate_weekly_pulse_repo() {
	PulseRecord record;
	record.readin_data();
	record.generate_weekly_report();
}

void User::user_generate_monthly_pulse_repo() {
	PulseRecord record;
	record.readin_data();
	record.generate_monthly_report();
}

void User::user_generate_daily_glucose_repo() {
	GlucoseRecord record;
	record.readin_data();
	record.generate_daily_report();
}

void User::user_generate_weekly_glucose_repo() {
	GlucoseRecord record;
	record.readin_data();
	record.generate_weekly_report();
}

void User::user_generate_monthly_glucose_repo() {
	GlucoseRecord record;
	record.readin_data();
	record.generate_monthly_report();
}