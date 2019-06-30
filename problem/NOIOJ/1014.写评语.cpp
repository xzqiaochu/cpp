#include <iostream>

using namespace std;

int main() {
	int score;
	cin >> score;
	if (score >= 90) {
		cout << "Excellent";
	}else if (score >= 80) {
		cout << "Good";
	}else if (score >= 60) {
		cout << "Pass";
	}else{
		cout << "Fail";
	}
	return 0;
} 
