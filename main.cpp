#include <iostream>
#include <string>
#include <ctime> 

#include "user.h"

int main() {
	srand(time(NULL));

	User user_test;

	user_test.user_login();
	system("pause");
	system("CLS");
	user_test.user_login();
	system("pause");
	system("CLS");
	user_test.user_login();
	system("pause");
	system("CLS");
	user_test.user_login();

	std::cout << std::endl;
	std::cout << "\/\/ make_calls(\"Alice\")" << std::endl;
	user_test.user_make_calls("Alice");
	std::cout << std::endl;
	std::cout << "\/\/ make_calls(\"Bob\")" << std::endl;
	user_test.user_make_calls("Bob");
	std::cout << std::endl;
	std::cout << "\/\/ user_test.contacts.add_contact(\"Bob\", \"987-654-3210\")" << std::endl;
	user_test.contacts.add_contact("Bob", "987-654-3210");
	std::cout << "\/\/ user_test.contacts.find_contact (\"Bob\") " << std::endl;
	std::cout << user_test.contacts.find_contact("Bob") << std::endl;

	std::cout << std::endl;
	std::cout << "\/\/ user_test.user_detect_emergency()" << std::endl;
	user_test.user_detect_emergency();
	std::cout << std::endl;
	user_test.user_detect_emergency();
	std::cout << std::endl;
	user_test.user_detect_emergency();
	std::cout << std::endl;
	user_test.user_detect_emergency();
	std::cout << std::endl;
	user_test.user_detect_emergency();

	std::cout << std::endl;
	user_test.user_generate_daily_pulse_repo();
	std::cout << std::endl;
	user_test.user_generate_weekly_pulse_repo();
	std::cout << std::endl;
	user_test.user_generate_monthly_pulse_repo();

	std::cout << std::endl;
	user_test.user_generate_daily_glucose_repo();
	std::cout << std::endl;
	user_test.user_generate_weekly_glucose_repo();
	std::cout << std::endl;
	user_test.user_generate_monthly_glucose_repo();

	std::cout << std::endl;
	std::cout << "\/\/ user_test.location.share_location(\"Alice\")" << std::endl;
	user_test.location.share_location("Alice");
	std::cout << std::endl;
	std::cout << "\/\/ user_test.location.share_location(\"Jack\")" << std::endl;
	user_test.location.share_location("Jack");

	system ("pause");
	return 0;
}