#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "register_login.h"

void LoginManager::readin_user_data() {
	std::ifstream user_data("username_password.txt", std::ios::in);

	if (!user_data) {
		std::cout << "Could not open file" << std::endl;
	}

	while (user_data >> username >> password) {
		user_database[username] = password;
	}

	user_data.close();
}

bool LoginManager::find_username(std::string input_username) {
	std::unordered_map<std::string, std::string>::const_iterator got = user_database.find(input_username);
	if (got == user_database.end())
		return false;
	else
		return true;
}

std::string LoginManager::get_password(std::string input_username) {
	std::unordered_map<std::string, std::string>::const_iterator got = user_database.find(input_username);
	return got->second;
}

void Login::username_password_prompt() {
	std::cout << "Username: ";
	std::cin >> username_atpt;
	std::cout << "Password: ";
	std::cin >> password_atpt;
}

void Login::password_prompt() {
	std::cout << "Password: ";
	std::cin >> password_atpt;
}

void Login::login() {
	LoginManager login_manager;	
	login_manager.readin_user_data();

	username_password_prompt();
	if (login_manager.find_username(username_atpt)) {
		std::string password_database = login_manager.get_password(username_atpt);
		do {
			if (password_atpt == password_database) {
				break;
			}
			else {
				std::cout << "Password not correct, enter again!" << std::endl;
				password_prompt();
			}
		} while (password_atpt != password_database);
		std::cout << "Logging in..." << std::endl;
		//home_page()
	}
	else {
		std::cout << "Username doesn't exist, create a new account." << std::endl;
		Register new_register;
		new_register.new_account();
	}
}

void Register::new_account() {
	std::cout << "Create username: ";
	std::cin >> username;
	std::cout << "Create password: ";
	std::cin >> password;

	std::ofstream output_file;
	output_file.open("username_password.txt", std::ios::out | std::ios::app);

	output_file << username << ' ' << password << std::endl;
	output_file.close();
}


//int main() {
//	Login login;
//	login.login();
//
//	system("pause");
//	return 0;
//}