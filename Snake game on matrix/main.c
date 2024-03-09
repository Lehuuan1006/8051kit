#include <stdlib.h>
#include <REGX52.H>
#include "HC595.H"
#include "Delay.H"
#include "MatrixKey.H"
#include "Timer0.H"

unsigned char Dire,KeyNum,length,foodx,foody,Speed=30;
char Snakex[40]={0};
char Snakey[40]={0};
unsigned char code Coorx[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
unsigned char code Coory[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char Led[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void SnakeMove() //di chuyen moi phan cua snake den phan truoc do
{	unsigned char i;
    for (i=length+1;i>0;i--)
    {
        Snakex[i]=Snakex[i-1];
        Snakey[i]=Snakey[i-1];
    }	
	switch(Dire)//cap nhat ??u c?a snake d?a theo h??ng hi?n t?i
	{
		case 1:(Snakex[0])--;if((Snakex[0])<0){(Snakex[0])=7;}break; //?i trái, n?u ??u r?n ?i qua c?nh trái thì s? hi?n l?i v? bên ph?i
		case 2:(Snakex[0])++;(Snakex[0])%=8;break; //?i ph?i, n?u ??u r?n ?i qua c?nh ph?i thì s? hi?n l?i v? bên trái
		case 3:(Snakey[0])++;(Snakey[0])%=8;break; //?i lên, n?u ??u r?n ?i qua c?nh trên thì s? hi?n l?i v? bên d??i
		case 4:(Snakey[0])--;if((Snakey[0])<0){(Snakey[0])=7;}break; //?i xu?ng, n?u ??u r?n ?i qua c?nh d??i thì s? hi?n l?i v? bên trên
	}
}
void Scan_Key()
{
	if(KeyNum)
	{
		switch(KeyNum)
		{
			case 1:if(Dire!=3)Dire=4;break;
			case 2:if(Dire!=4)Dire=3;break;
			case 3:if(Dire!=2)Dire=1;break;
			case 4:if(Dire!=1)Dire=2;break;
		}
	}
}
void food()//th?c ?n hi?n ng?u nhiên, ko trùng v?i ?uôi r?n nh? length-1 và di?n ra trong ma tr?n 8x8
{	
	foodx=(rand()+Snakex[length-1])%8;
	foody=(rand()+Snakex[length-1])%8;
}
void PlaySnakeAC() //hi?n th? v? trí c?a r?n và ?? ?n trên led matrix
{
	unsigned char i;
	for(i=0;i<length;i++)
	{
	MatrixLed(Coorx[Snakex[i]],Coory[Snakey[i]]);
	MatrixLed(Coorx[foodx],Coory[foody]);
	}
}
void Snakedead() //ki?m tra n?u ??u r?n ??ng vào thân ho?c ?uôi thì t?t led matrix
{	unsigned char i;
	for(i=4;i<length;i++)
	{
		if(Snakex[0]==Snakex[i] && Snakey[0]==Snakey[i])
		{
			P0=0xFF;
			while(1);		
		}
	}
}
void Play_Game()
{	unsigned char i;
	Scan_Key();
	PlaySnakeAC();
	Snakedead();
	for(i=0;i<length;i++)
	{	
		if(foodx==Snakex[i] && foody==Snakey[i]) //n?u ??u r?n ?n food thì t?ng chi?u dài và có thêm food m?i
		{
			length++;
			food();
		}
	}
}
void main()
{	
	Timer0_Init();
	length=1;///kh?i t?o chi?u dài =1, h??ng ?i lên
	Dire=3;
	while(1)
	{	rand();
		KeyNum=Key();
		Play_Game();
	}
}

void Routine_Timer0()interrupt 1
{
	static unsigned int T0Count1,T0Count2;
	TL0 = 0xCD;		
	TH0 = 0xD4;			
	T0Count1++;
	if(T0Count1>=15)
	{
		T0Count1=0;
		Loop_MatrixKey();
	}
	T0Count2++;
	if(T0Count2>Speed)
	{	
		T0Count2=0;
		SnakeMove();
	}

}
