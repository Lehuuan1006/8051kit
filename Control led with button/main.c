#include <REGX52.H>
sbit but0=P3^0;
sbit but1=P3^1;
sbit but2=P3^2;
sbit but3=P3^3;

sbit led0=P2^0;
sbit led1=P2^1;
sbit led2=P2^2;
sbit led3=P2^3;

void delay(int t) {
	while (t--);
	}
void main(){			
	while(1){
		if (but0==0) {
			led0=!led0;
			delay (40000);
			}
		if (but1==0) {
			led1=!led1;
			delay (40000);
			}
		if (but2==0) {
			led2=!led2;
			delay (40000);
			}
		if (but3==0) {
			led3=!led3;
			delay (40000);
			}
		}
	}
