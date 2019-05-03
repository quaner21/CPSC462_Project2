#pragma once

#include "register_login.h"
#include "contacts_dial.h"
#include "pulse.h"
#include "glucose.h"
#include "location.h"

class User {
public:	
	std::string username;
	ContactLibrary contacts;
	LocationService location;

	void user_login();
	void user_make_calls(std::string);
	void user_dial_911();
	bool user_detect_emergency();
	void user_generate_daily_pulse_repo();
	void user_generate_weekly_pulse_repo();
	void user_generate_monthly_pulse_repo();
	void user_generate_daily_glucose_repo();
	void user_generate_weekly_glucose_repo();
	void user_generate_monthly_glucose_repo();

private:
	PulseRecord pulse;
	GlucoseRecord glucose;
};