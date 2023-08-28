/ Program to demonstrate Patterns on 8 LEDs
/ Control is through Ports dedicated as outputs
/ LEDs connected to PORT1 P1.24 to P1.27
////////////////////////////////////////////////////////////////////////// */
#include <LPC214x.H>            /* LPC214x definitions */

#define CLK	0x00010000   //  or (1 << 16)	 //KEY1	   	P1.16
#define ACLK	0x00020000   //  or (1 << 17)	 //KEY5	   	P1.17
void delay(unsigned int count)
{
  int j=0,i=0;
  for(j=0;j<count;j++)
  {
    for(i=0;i<500;i++);
  }
}
int main (void) 
{
	unsigned char run=1;
  	IO1DIR = 0x0F000000;//make Port P1.27 to P1.24 as output
	PINSEL2 = 0x0; // make Port P1.27 to P1.24 as GPIO
{	
while(1)
{	
	if (!(IO1PIN & CLK) )	
		run = 1;
	if (!(IO1PIN & ACLK))
		run = 0;
	if (run==1)
		
			{
					IO1PIN = 0X01000000;
					delay(100);
					IO1PIN = 0X02000000;
					delay(100);
					IO1PIN = 0X04000000;
					delay(100);
					IO1PIN = 0X08000000;
					delay(100);
			}
			else
			{
					IO1PIN = 0X08000000;
					delay(100);
					IO1PIN = 0X04000000;
					delay(100);
					IO1PIN = 0X02000000;
					delay(100);
					IO1PIN = 0X01000000;
					delay(100);}
		}	 
}
}