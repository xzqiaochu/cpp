#include <iostream>
#include <cstdio>

using namespace std;

int year, month, day, sub;

void monthsub() {
	if (month == 1) {
		year--;
		month = 12;
	} else {
		month--;
	}
}

void daysub() {
	if (day == 1) {
		monthsub();
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			day = 31;
		} else if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
				day = 29;
			} else {
				day = 28;
			}
		} else {
			day = 30;
		}
	} else {
		day--;
	}
}

int main() {
	cin >> year >> month >> day >> sub;
	for (int i = 1; i < sub; i++) daysub();
	printf("%04d-%02d-%02d", year, month, day);
	return 0;
}
