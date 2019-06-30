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

int tune[]= {
	D0,D5,M1,M2,
	M2,M3,M3,D0,M1,M2,M3,
	M2,M5,M5,D7,D0,M5,M6,M7,
	M7,H1,H1,D0,H2,H3,H2,H1,
	M7,D0,H1,M7,M5,
	M5,M6,M6,D0,M6,M5,M4,
	M4,M5,M5,M1,M1,D0,M1,M2,
	M3,M4,M4,M4,M4,M5,M4,
	M3,M2,M2,D5,M1,M2,
	M2,M3,M3,D0,M1,M2,M3,
	M2,M5,M5,D7,D0,M5,M6,M7,
	M7,H1,H1,D0,H2,H3,H2,H1,
	M7,D0,H1,M7,M5,
	M5,M6,M6,D0,M5,M4,
	M4,M5,M5,M1,D0,M1,M2,
	M3,M4,D6,M1,D7,
	M1,D0,M1,M3,M5,
	M6,D0,D7,M1,M6,
	M6,M5,M5,D0,D7,M1,M5,
	M5,M4,M4,M3,M3,M2,M2,M1,
	M2,M3,M3,D0,M1,M3,M5,
	M6,D0,M7,M7,M6,M5,
	M5,D0,M3,M4,M5,M4,M4,M3,
	M4,M5,M5,M6,M7,H1,
	H3,H4
};
float durt[]= {
	0.25,0.25,0.25,0.25,
	0.5,0.5,2,0.25,0.25,0.25,0.25,
	0.5,0.5,0.5,1.5,0.25,0.25,0.25,0.25,
	0.5,0.5,1,0.5,0.5,0.5,0.25,0.25,
	2,0.5,0.5,0.5,0.5,
	0.5,0.5,2,0.25,0.25,0.25,0.25,
	0.5,0.5,0.5,0.25,1.25,0.5,0.25,0.25,
	0.5,0.5,0.5,0.25,1.25,0.5,0.5,
	1.5,0.5,0.5,0.5,0.5,0.5,
	0.5,0.5,2,0.25,0.25,0.25,0.25,
	0.5,0.5,0.5,1.5,0.25,0.25,0.25,0.25,
	0.5,0.5,1,0.5,0.5,0.5,0.25,0.25,
	2,0.5,0.5,0.5,0.5,
	0.5,0.5,2,0.5,0.25,0.25,
	0.5,0.5,0.5,1.5,0.5,0.25,0.25,
	0.5,1,0.5,1,1,
	2,0.5,0.5,0.5,0.5,
	2,0.5,0.5,0.5,0.5,
	0.5,0.5,1,0.5,0.5,0.5,0.5,
	0.5,0.5,0.5,0.5,0.5,0.25,0.75,0.5,
	0.5,0.5,1,0.5,0.5,0.5,0.5,
	2,0.5,0.5,0.5,0.25,0.25,
	1,0.5,0.25,0.25,0.5,0.5,0.5,0.5,
	1,0.5,0.5,0.75,0.75,0.5,
	1.75,0.25
};

int main () {
	int length = sizeof(tune) / sizeof(tune[0]);
	for(int i = 0; i < length; i++) Beep(tune[i], durt[i] * 968);
}

