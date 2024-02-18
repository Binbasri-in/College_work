
// Triangle-DAC
#include <LPC214x.H>                       /* LPC214x definitions */

//////////   Init DAC  /////////////////
Init_DAC()
{
  // Convert Port pin 0.25 to function as DAC
  PINSEL1 = 0X00080000;
  DACR = 0;
}

//////////   Write DAC   /////////////////
Write_DAC(unsigned int dacval)
{
	DACR = dacval << 6;	
}

//////////   MAIN /////////////////
int main (void) 
{
unsigned int i;

  Init_DAC();

  while(1)
  {
	for(i=0;i<1024;i++)
		Write_DAC(i);
	for(i=1023;i>0;i--)
		Write_DAC(i);
  }
}
