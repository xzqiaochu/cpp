#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	for ( a = 0; a <= 20; a++ )
	{
		for ( b = 0; b <= 33; b++ )
		{
			c = 100 - a - b;
			if ( 5 * a + 3 * b + c / 3 == 100 && c % 3 == 0 )
			{
				cout << a << ' ' << b << ' ' << c << endl;
			}
		}
	}
	return(0);
}
