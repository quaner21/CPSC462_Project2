#pragma once

#include <vector>

class ReportGenerator {
public:
	void generate_report(std::vector<int>, int);

private:
	int sum;
	int max;
	int min;
};