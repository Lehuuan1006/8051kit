#include <REGX52.H>
void delay(int t) {
	while (t--);
	}
char sangtatdan[]={0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00,0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f};
int i;
void main(){
	while (1) {
	for (i=0;i<=15;i++){
		P2 = sangtatdan[i];
		delay(10000);
		}
		}
}