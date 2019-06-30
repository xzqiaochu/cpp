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
	H3,H1,H2,M6,
	H3,H2,H1,H2,M6,
	H3,H1,H2,H2,
	H5,H3,M7,H1,H1,M7,
	M6,M7,H1,H2,M5,
	H6,H5,H3,H3,H3,H2,
	H1,H2,H3,H2,H3,H2,H5,
	H5,

	H3,H1,H2,M6,
	H3,H2,H1,H2,M6,
	H3,H1,H2,H2,H2,
	H5,H3,M7,H1,H1,M7,
	M6,M7,H1,H2,M5,
	H6,H5,H3,H3,H3,H2,
	H1,H2,H3,H2,M5,
	M6,M6,H1,M6
};
float durt[]= {
	1,1,1,1,
	0.5,0.5,0.5,0.5,2,
	1,1,1,1,
	0.5,0.5,1,1,0.5,0.5,
	1,0.5,0.5,1,1,
	0.5,0.5,1,1,0.5,0.5,
	1,0.5,0.5,0.5,0.5,0.5,0.5,
	4,

	1,1,1,1,
	0.5,0.5,0.5,0.5,2,
	1,1,1,0.5,0.5,
	0.5,0.5,1,1,0.5,0.5,
	1,0.5,0.5,1,1,
	0.5,0.5,1,1,0.5,0.5,
	1,0.5,0.5,1,1,
	1,0.5,0.5,2
};

int main () {
	int length = sizeof(tune) / sizeof(tune[0]);
	for(int i = 0; i < length; i++) Beep(tune[i], durt[i] * 200);
}
