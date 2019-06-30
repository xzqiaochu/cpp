#include <windows.h>

#define D0 0
#define D1 294
#define D2 330
#define D3 350
#define D4 393
#define D5 441
#define D6 495
#define D7 556

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

int tune[]= {
	D0,D5,H3,H2,H2,H1,
	H1,H1,H1,H1,H1,H1,M6,M5,
	H5,H6,H6,H6,H1,H2,
	H3,H5,H5,H5,H1,H2,
	H2,H1,
	D0,H1,H1,H1,H1,M6,M5,
	H5,H6,H6,H6,H1,H1,H2,
	H3,H5,H5,H5,H3,H2,
	H2,H3,H2,H2,H1,
	H1,H1,H1,H1,M6,M5,
	H5,H6,H6,H6,H1,H1,H2,
	H3,H5,H5,H5,H1,H2,
	H2,D0,H2,H3,H1,
	H1,H1,H1,H1,M6,
	H5,H6,H6,H6,H1,H2,
	H3,H5,H5,H3,H2,H2,
	H2
};
float durt[]= {
	0.5,0.5,0.5,0.5,0.5,0.5,
	0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
	0.5,1,0.5,1,0.5,0.5,
	0.5,1,0.5,0.5,1,0.5,
	2,2,
	1,0.5,0.5,0.5,0.5,0.5,0.5,
	0.5,1,0.5,0.5,0.5,0.5,0.5,
	0.5,1,0.5,0.5,1,0.5,
	2,0.5,0.5,0.5,0.5,
	1,1,0.5,0.5,0.5,0.5,
	0.5,1,0.5,0.5,0.5,0.5,0.5,
	0.5,1,0.5,0.5,1,0.5,
	2,0.5,0.5,0.5,0.5,
	1,0.5,0.5,1.5,0.5,
	0.5,1,0.5,1,0.5,0.5,
	0.5,1,1,0.5,0.5,0.5,
	4
};

int main () {
	int length = sizeof(tune) / sizeof(tune[0]);
	for(int i = 0; i < length; i++) Beep(tune[i], durt[i] * 500);
}
