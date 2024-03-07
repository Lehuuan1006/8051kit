#include <REGX52.H>
sbit but0=P3^0;
sbit but1=P3^1;

void delay(int t) {
	while (t--);
	}
char dem[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int i=0;
void main(){
	while (1) {
		if ((but0==0)&&(i<=9) && (i>=0))  {
			i++;
			P0 = dem[i];
			delay(100);
				}
		
		if ((but1==0) && (i>=0) && (i<=9)){
			i--;
			P0 = dem[i];
			delay(100);
		}
}
	}
