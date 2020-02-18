#include<reg52.h>
#define seg_data P2
sbit seg1=P1^3;
sbit seg2=P1^4;
sbit rd=P1^2;
sbit wr=P1^1;
sbit intr=P1^0;
void msdelay(unsigned int itime);
void delay();
void display_digit(int);
void main()
{
unsigned int num;
unsigned int ones,tens=0;
while(1)
{
rd=1;
wr=0;
msdelay(1);
wr=1;			
while(intr);		
rd=0;					
num=P3;

num=num*1.0;	
ones=num%10;
tens=(num/10)%10;			
display_digit(ones);
seg1=1;
delay();
seg1=0;
display_digit(tens);
seg2=1;
delay();
seg2=0;	
}
}	     
		   

void msdelay(unsigned int itime)	  
{
unsigned int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);
}


void display_digit(int c)
{
switch(c)
{
case 0:
seg_data=0xC0;
break;
case 1:
seg_data=0xF9;
break;
case 2:
seg_data=0xA4;
break;
case 3:
seg_data=0xB0;
break;
case 4:
seg_data=0x99;
break;
case 5:
seg_data=0x92;
break;
case 6:
seg_data=0x82;
break;
case 7:
seg_data=0xF8;
break;
case 8:
seg_data=0x80;
break;
case 9:
seg_data=0x98;
break;
}
}
void delay()
{
long int k;
for(k=0;k<100;k++);
}