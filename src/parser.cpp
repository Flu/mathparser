#include <iostream>
#include <string>

int power(const int&, const int&);
void startInteractiveShell();
void stripSpaces(std::string&);
long long evalexpr(const std::string&, const unsigned&);
std::string constructInput(const int&, const char* const[]);

void startInteractiveShell() {
	std::cout << "Math Parser (v0.2)\nInteractive shell, Fluturel Adrian (c) 2018\n";
	std::string mathexpr;
	while (true) {
		std::cout << "> ";
		std::getline(std::cin, mathexpr);
		if (mathexpr == "exit")
			break;
		stripSpaces(mathexpr);
		std::cout << std::endl << evalexpr(mathexpr, 0u) << std::endl;
	}
}

int power(const int &base, const int &exp) {
	if (exp == 0)
		return 1;
	int result = base;
	for (int power = 1; power < exp; power++)
		result *= base;
	return result;
}

void stripSpaces(std::string &mathexpr) {
	size_t spacesFound = 0ul;
	for (long index = 0l; index < mathexpr.length() - spacesFound; index++) {
		if (mathexpr[index + spacesFound] == 32)
			spacesFound++;
		mathexpr[index] = mathexpr[index + spacesFound];
	}
	mathexpr.resize(mathexpr.length() - spacesFound);
}

long long evalexpr(const std::string &mathexpr, const unsigned &start) {
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
	std::string mathexpr;
	if (argc < 2) {
		std::cin >> mathexpr;
		if (mathexpr.empty())
			return "Not enough arguments given\n";
		else
			return mathexpr;
	}
	size_t numberOfArgs = 0;
	while (numberOfArgs++ < argc - 1)
		mathexpr += argv[numberOfArgs];
	stripSpaces(mathexpr);
	return mathexpr;
}

int main(int argc, char *argv[]) {
	std::string mathexpr = constructInput(argc, argv);
	if (mathexpr == "-i" || mathexpr == "--interactive") {
		startInteractiveShell();
		return 0;
	}
	std::cout << evalexpr(mathexpr, 0u) << std::endl;
	return 0;
}