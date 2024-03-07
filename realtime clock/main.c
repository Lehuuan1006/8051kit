#include <REGX52.h>
#include <RtcDS1302.h>
void delay(int t) {
	int j,y;
	for (j = 0;j<=t;j++){
		for (y = 0;y<5;y++);
	}
}
char Num[] = {0xff, 0xfb, 0xf7, 0xf3, 0xef, 0xeb, 0xe7, 0xe3};
unsigned char Led[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void main() {
	unsigned char gio,phut,giay;
	unsigned char chuc,donvi;
	int i,tictac;
	gio = phut = giay = tictac = 0;
	while(1) {
		for (i = 0;i<167;i++) {
	//gio
		 	chuc = gio/10;
			donvi = gio%10;
			P0 = Led[chuc];
			P2 = Num[0];
 			delay(1);
			P0 = 0x00;

			P0 = Led[donvi];
			P2 = Num[1];
 			delay(1);
			P0 = 0x00;
	//phut
		 	chuc = phut/10;
			donvi = phut%10;
			P0 = Led[chuc];
			P2 = Num[3];
 			delay(1);
			P0 = 0x00;

			P0 = Led[donvi];
			P2 = Num[4];
 			delay(1);
			P0 = 0x00;
	//giay
		 	chuc = giay/10;
			donvi = giay%10;
			P0 = Led[chuc];
			P2 = Num[6];
 			delay(1);
			P0 = 0x00;

			P0 = Led[donvi];
			P2 = Num[7];
 			delay(1);
			P0 = 0x00;

	//bo dem
			tictac++;
			if (tictac == 1000) {
				tictac = 0;		
				giay++;
				if (giay == 60) {
					giay = 0;
					phut++;
						if (phut == 60) {
							phut = 0;
							gio++;
								if (gio == 24) {
									gio = 0;
								}
						}
				}
			}
		}
	}
}
