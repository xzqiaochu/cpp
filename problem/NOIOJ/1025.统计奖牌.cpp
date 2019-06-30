#include <iostream>

using namespace std;

int main() {
	int n,a=0,b=0,c=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int this_a=0,this_b=0,this_c=0;
		cin>>this_a>>this_b>>this_c;
		a+=this_a;
		b+=this_b;
		c+=this_c;
	}
	int all=a+b+c;
	cout<<a<<' '<<b<<' '<<c<<' '<<all;
	return 0;
}
