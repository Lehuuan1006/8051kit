#include<main.h>
void Send_data_cot(unsigned char _data);
sbit SH_CP=P3^6;	//dinh nghia 
sbit DS=P3^4;			//dinh nghia 
sbit ST_CP=P3^5;	//dinh nghia chan ST
unsigned char a[24]= {
                             0xFF,0xFF,0xFF,0xB5,0xB5,0xB5,0xB5,0x81,//ma chu e
							 0xFF,0xFD,0xFD,0x81,0x81,0xFD,0xFD,0xFF,//ma chu t
							 0xC1,0xBF,0xBF,0xBF,0xC1,0xFF,0xFF,0xFF//ma chu u
                     };
unsigned char b[8]= {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//ma quét COT : C1 den C8, COT nao o gia tri =1 thì COT dó duoc sáng.
unsigned char i=0,k=0,j=0;
int main()
	{
			while(1){
               for(k=16;k>0;k--){
                  for(j=0;j<10;j++){
                     for(i=0;i<8;i++){
                              P0=a[i+k];     
                              Send_data_cot(b[i]); 
                              delay_us(100);     
                              Send_data_cot(0x00);
                        }
                  }
               } 
			   delay_ms(10);
			}
	}
void Send_data_cot(unsigned char _data)
{
unsigned char n,tam;
 
         ST_CP=0;//cho chan ST cua 74HC595 xuong muc 0
         SH_CP=0;//cho chan SH cua 74HC595 xuong muc 0
         DS=0;	//cho chan DS cua 74HC595 xuong muc 0
   for(n=0;n<8;n++){
		tam=_data&0x80;
       _data = _data<<1;//dich trai 1 bit de goi bit can goi ra  cot      
      if(tam==0x80)
      {
        DS=1;// cho LED sang COT =1
      }
      else                                 
     {
        DS=0;//cho LED tat COT =0
     }
      //tao xung dich du lieu   
      SH_CP=1;
      SH_CP=0;  
   }
    //tao xung chot du lieu
      ST_CP=1;
      ST_CP=0;  
}
