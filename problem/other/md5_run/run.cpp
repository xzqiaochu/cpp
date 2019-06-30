#include "md5.cpp"
#include <ctime>
using namespace std;

const int SIZE_CHAR = 32;
const char CCH[] = "_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

int main()
{
    srand((unsigned)time(NULL));
    unsigned char encrypt[SIZE_CHAR + 1] = {0};
    unsigned char decrypt[16];
    unsigned char want[4] = {0x27, 0x6f, 0x72, 0x27};

    bool flag = false;
    
    int i = 0;

    double st = clock();
    while (flag == false)
    {
        i++;
        if (i >= 1000000) break;
        for (int i = 0; i < SIZE_CHAR; ++i)
        {
            int x = rand() / (RAND_MAX / (sizeof(CCH) - 1));
            encrypt[i] = CCH[x];
        }
        
        MD5_CTX md5;

        MD5Init(&md5);
        MD5Update(&md5, encrypt, (int)strlen((char *)encrypt)); //只是个中间步骤
        MD5Final(&md5, decrypt);                                //32位

        for (int i = 0; i < 4; i++)
        {
            if (decrypt[i] != want[i]) break;
            if (i == 3) flag = true;
        }
    }

    cout << clock() - st;
    return 0;
}