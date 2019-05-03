#pragma once

struct Coordinates {
	double latitude;
	double longitude;
};

class LocationService {
public:
	void receive_location(Coordinates);
	double get_latitude();
	double get_longitude();
	void share_location(std::string);

private:
	Coordinates location;
};