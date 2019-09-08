#include "Header.h"

int myAtoi(string str) {

	// trim leading spaces if exists...
	size_t start = str.find_first_not_of(" ");
	str = (start == std::string::npos) ? "" : str.substr(start);

	//discard if zero length string
	if (str.size() == 0)
		return 0;

	// discard if the first char is not a sign/digit
	if (!(str.at(0) == 43 || str.at(0) == 45 || (str.at(0) >= 48 && str.at(0) <= 57)))
		return 0;

	// discard if first two is sign
	if (str.size() >= 2 && (str.at(0) == 43 || str.at(0) == 45) && (str.at(1) == 43 || str.at(1) == 45))
		return 0;

	// discard if only one char and not a digit
	if (str.size() == 1 && (str.at(0) < 48 || str.at(0) > 57))
		return 0;

	bool bNeg = false;
	if (str.at(0) == 43 || str.at(0) == 45) {
		if (str.at(0) == 45)
			bNeg = true;
		str = str.substr(1);
	}

	string str1;
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((str.at(i) < 48 || str.at(i) > 57))
			break;
		str1.push_back(str.at(i));
	}

	long long val = 0;
	for (size_t i = 0; i < str1.size(); i++)
	{
		val = val * 10 + (str1.at(i) - '0');
		if (val > INT_MAX)
			return bNeg ? INT_MIN : INT_MAX;
	}
	if (bNeg)
		val *= -1;
	return val;
}
void main() {
	int val = myAtoi("20000000000000000000");
}