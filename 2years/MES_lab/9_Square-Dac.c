//square wave
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
void delay(unsigned int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    for(i=0;i<120;i++);
  }
}
//////////   MAIN /////////////////
int main (void) 
{

   Init_DAC();

  while(1)
  {
	Write_DAC(00);
	delay(100);		 	// change this value to change Frequency
	Write_DAC(1023);	// change this value to change Amplitude
	delay(100);		    // change this value to change Frequency
  }
}
