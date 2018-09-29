#include <iostream>
#include <string>

int power(const int &base, const int &exp) {
	if (exp == 0)
		return 1;
	int result = base;
	for (int power = 1; power < exp; power++)
		result *= base;
	return result;
}

double evalexpr(const std::string &mathexpr, const unsigned &start) {
	double result = 0.;
	unsigned position, digits = start;
	while (mathexpr[digits] >= '0' && mathexpr[digits] <= '9')
		digits++;
	for (position = start; position < digits; position++) {
		result += double(mathexpr[position] - '0')*power(10, digits - position - 1);
	}
	if (mathexpr[position] == '+')
		return result + evalexpr(mathexpr, position + 1);
	if (mathexpr[position] == '-')
		return result - evalexpr(mathexpr, position + 1);
	return result;
}

std::string constructInput(const int &argc, const char * const argv[]) {
	if (argc < 2) {
		return "Not enough arguments given\n";
	}
	size_t numberOfArgs = 0;
	std::string mathexpr;
	while (numberOfArgs++ < argc - 1)
		mathexpr += argv[numberOfArgs];
	return mathexpr;
}

int main(int argc, char *argv[]) {
	std::string mathexpr = constructInput(argc, argv);
	std::cout << evalexpr(mathexpr, 0u) << std::endl;
	return 0;
}