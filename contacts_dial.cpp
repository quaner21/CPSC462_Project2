#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "contacts_dial.h"

void ContactLibrary::add_contact(std::string name, std::string number) {
	std::ofstream output_file;
	output_file.open("contacts.txt", std::ios::out | std::ios::app);
	output_file << name << ' ' << number << std::endl;
	output_file.close();
}

std::string ContactLibrary::find_contact(std::string name) {
	std::ifstream contact_data("contacts.txt", std::ios::in);

	if (!contact_data) {
		std::cout << "You have no contacts yet!" << std::endl;
		return "";
	}
	else {
		std::string name, number;
		while (contact_data >> name >> number) {
			contacts[name] = number;
		}
	}
	contact_data.close();

	std::unordered_map<std::string, std::string>::const_iterator got = contacts.find(name);
	if (got == contacts.end())
	{
		std::cout << "Contact doesn't exists!" << std::endl;
		return "";
	}
	else
		//std::cout << got->second << std::endl;
		return got->second;
}

void Dial::dial_911() {
	// hard code "911" as the number to dial
	// call dial function from mobile
	std::cout << "Dialing 911..." << std::endl;
}

void Dial::dial_contact(std::string name) {
	ContactLibrary contact_book;
	std::string number_to_dial = contact_book.find_contact(name);
	if (number_to_dial.length() != 0) {
		std::cout << "Dialing " << number_to_dial << "..." << std::endl;
		// call dial function from mobile and pass number_to_dial
	}
}
