#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>

#include "generate_report.h"

void ReportGenerator::generate_report(std::vector<int> data, int entries) {
	int sum = 0;
	int max = 0;
	int min = 1000;
	int size = data.size();
	int i = std::min(size - 1, entries - 1);

	while (i >= 0) {
		sum += data[i];
		if (data[i] > max) {
			max = data[i];
		}
		if (data[i] < min) {
			min = data[i];
		}
		i--;
	}

	if (std::min(size, entries) > 0)
		std::cout << "Average: " << sum / std::min(size, entries) << std::endl;
	std::cout << "Highest: " << max << std::endl;
	std::cout << "Lowest: " << min << std::endl;
}

//int main() {
//	std::vector<int> myvector;
//	for (int i = 1; i <= 5; i++) myvector.push_back(i);
//	
//	ReportGenerator temp;
//	temp.generate_report(myvector, 243);
//
//	system("pause");
//	return 0;
//}