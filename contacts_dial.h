#pragma once
#include <unordered_map>

class ContactLibrary {
public:
	void add_contact(std::string, std::string);
	std::string find_contact(std::string);
private:
	std::unordered_map<std::string, std::string> contacts;
};

class Dial {
public:
	void dial_911();
	void dial_contact(std::string);
};