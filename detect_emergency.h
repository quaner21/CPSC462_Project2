#pragma once

class DetectEmergency {
public:
	int get_current_pulse();
	int get_current_glucose();
	bool detect_emergency();

private:
	int current_pulse;
	int current_glucose;
};
