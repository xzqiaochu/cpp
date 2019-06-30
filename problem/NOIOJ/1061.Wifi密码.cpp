#include <iostream>

using namespace std;

int main() {
	while(1) {
		char c;
		cin>>c;
		if (c == 'Y') {
			string input;
			cin>>input;
			if (input == "NOIP@CCF") {
				cout<<"Success"<<endl;
				return 0;
			} else {
				cout<<"Sorry"<<endl;
			}
		} else {
			return 0;
		}
	}
}
