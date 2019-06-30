#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for (int k = 1; k <= 12; k++)
    {
        for (int i = 6; i <= 10000000000; i += 5)
        {
            bool flag = true;
            int left = (i - 1) / 5 * 4;
            for (int j = 1; j <= k; j++)
            {
                if (left % 5 == 1)
                {
                    left = (left - 1) / 5 * 4;
                }
                else
                {
                    flag = false;
                }
                if (flag == false)
                    break;
            }
            if (flag == true)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}