#include <cstdio>
#include <windows.h>

#define D0 0

#define D1 262
#define D2 294
#define D3 330
#define D4 349
#define D5 392
#define D6 440
#define D7 494

#define M1 523
#define M2 587
#define M3 659
#define M4 698
#define M5 784
#define M6 880
#define M7 988

#define H1 1046
#define H2 1175
#define H3 1318
#define H4 1397
#define H5 1568
#define H6 1760
#define H7 1976

int tune[] = {
    D6, D6, M3, M2, M1,
    D7, D7, D7, M2, M1, D7,
    D6, D6, H1, M7, H1, M7, H1,
    D6, D6, H1, M7, H1, M7, H1, // Line 1
    D6, D6, M3, M2, M1,
    D7, D7, D7, M2, M1, D7,
    D6, D6, H1, M7, H1, M7, H1,
    D6, D6, H1, M7, H1, M7, H1, // Line 2
    D6, D6, M3, M2, M1,
    D7, D7, D7, M2, M1, D7,
    D6, D6, H1, M7, H1, M7, H1,
    D6, D6, H1, M7, H1, M7, H1, // Line 3
    M1, M1, M1, M1, M3, M3, M3, M3,
    M2, M2, M2, M2, M5, M5, M5, M5,
    D6, D6, D6, D6, D6, D6, D6, D6,
    D6, D6, D6, D6, M2, M1, D7, D5 // Line 4
};

int durt[] = {
    4, 8, 8, 4, 4,
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 8, 8, 8, 8,
    4, 8, 8, 8, 8, 8, 8, // Line 1
    4, 8, 8, 4, 4,
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 8, 8, 8, 8,
    4, 8, 8, 8, 8, 8, 8, // Line 2
    4, 8, 8, 4, 4,
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 8, 8, 8, 8,
    4, 8, 8, 8, 8, 8, 8, // Line 3
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8 // Line 4
};

int speed = 126;

int main()
{
    int len = sizeof(tune) / sizeof(tune[0]);
    while (1)
        for (int i = 0; i < len; i++) {
            printf("%d %d\n", tune[i], 240 * 1000 / (durt[i] * speed));
            Beep(tune[i], 240 * 1000 / (durt[i] * speed));
    }
}