#include <windows.h>

#define D0 0 

#define D1 294
#define D2 330
#define D3 370
#define D4 392
#define D5 440
#define D6 494
#define D7 554

#define M1 587
#define M2 659
#define M3 740
#define M4 784
#define M5 880
#define M6 988
#define M7 1109

#define H1 1175
#define H2 1318
#define H3 1480

int tune[]= {
	M1,M5,M3,M5,
	D7,M5,M3,M5,M3,M5,
	M6,M5,M1,M5,M3,
	M3,D0,M2,M3,
	D6,M1,D7,M6,
	M5,M3,M2,M1,M2,M3,
	M4,M3,M2,M1,M1,M3,M2,
	M2,D0,D0,
	M1,M5,M3,M5,
	D7,M5,M3,M5,M3,M5,
	M6,M6,M5,M1,M5,M3,
	M3,D0,M2,M3,
	D6,M1,D7,M6,
	M5,M3,M2,M1,M2,M3,
	M4,M3,M2,M1,
	D0,D0,D7,M2,M1,
	M1,D0,D0
};
float durt[]= {
	0.5,1,0.5,2,
	0.5,1,0.5,1,0.5,0.5,
	1.5,0.5,1,0.5,0.5,
	2,1,0.5,0.5,
	1.5,0.5,1,1,
	1,0.5,0.5,1,0.5,0.5,
	0.5,0.5,0.5,0.5,1,0.5,0.5,
	2,1,1,
	0.5,1,0.5,2,
	0.5,1,0.5,1,0.5,0.5,
	0.5,1,0.5,1,0.5,0.5,
	2,1,0.5,0.5,
	1.5,0.5,1,1,
	1,0.5,0.5,1,0.5,0.5,
	1,0.5,0.5,2,
	1,1,1,0.5,0.5,
	2,1,1
};

int main () {
	int length = sizeof(tune) / sizeof(tune[0]);
	for(int i = 0; i < length; i++) Beep(tune[i], durt[i] * 600);
}
