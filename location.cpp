#include <iostream>
#include <string>

#include "location.h"
#include "contacts_dial.h"

void LocationService::receive_location(Coordinates GPS_signal) {
	location.latitude = GPS_signal.latitude;
	location.longitude = GPS_signal.longitude;
}

double LocationService::get_latitude() {
	return location.latitude;
}

double LocationService::get_longitude() {
	return location.longitude;
}

void LocationService::share_location(std::string name) {
	ContactLibrary contacts;
	if (contacts.find_contact(name) != "") {
		std::cout << "Sharing your location with " << name << std::endl;
		// send location to name
	}
}