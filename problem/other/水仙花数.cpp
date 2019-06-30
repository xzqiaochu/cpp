#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a, b, c;
	for ( a = 1; a <= 9; a++ )
	{
		for ( b = 0; b <= 9; b++ )
		{
			for ( c = 0; c <= 9 ; c++ )
			{
				if ( pow(a, 3) + pow(b, 3) + pow(c, 3) == 100 * a + 10 * b + c)
				{
					cout << a << b << c << endl;
				}
			}
		}
	}
	return(0);
}
