#include <iostream>
#include <string>
#include <chrono>
#include <vector>

#include "generate_report.h"

void ReportGenerator::generate_report(std::vector<int> data, int entries) {
	int sum = 0;
	int max = 0;
	int min = 1000;
	int i = 0;
	std::vector<int>::iterator it = data.end();

	while (i < entries && it != data.begin()) {
		sum += *it;
		if (*it > max) {
			max = *it;
		}
		if (*it < min) {
			min = *it;
		}
		i++;
		it--;
	}

	std::cout << "Average: " << sum / entries << std::endl;
	std::cout << "Highest: " << max << std::endl;
	std::cout << "Lowest: " << min << std::endl;
}
