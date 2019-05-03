#pragma once

#include <unordered_map>

class LoginManager {
public:
	void readin_user_data();
	bool find_username(std::string input_username);
	std::string get_password(std::string input_username);

private:
	std::string username;
	std::string password;
	std::unordered_map<std::string, std::string> user_database;
};

class Login {
public:
	void login();

private:
	std::string username_atpt;
	std::string password_atpt;
	void username_password_prompt();
	void password_prompt();
};

class Register {
public:
	void new_account();
private:
	std::string username;
	std::string password;
};