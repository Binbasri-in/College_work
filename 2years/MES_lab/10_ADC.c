#include <LPC214x.h>
#include <stdio.h>
//-----------------------------------------------------
void init_uart()
{
    PINSEL0 = 0x5;
    U0LCR = 0x83; 
    U0DLM = 0x00;
    U0DLL = 0x61;
    U0LCR = 0x03;
}
//-----------------------------------------------------
void print_uart(char *str)
{
	  while(*str != 0x00)
    {
	while(!(U0LSR & 0x20));
         U0THR = *str;
       str++;
    }
}
//----------------------------------------------------
//////////   Init ADC0  /////////////////
void init_ADC()
{
  // Convert Port pin 0.28 to function as AD0.1
  PINSEL1 = 0X01000000;
}

//////////   READ ADC0 CH:2  /////////////////
unsigned int Read_ADC()
{
  unsigned int i=0;

		AD0CR |= 0x00200D02;  
    // AD0CR |= 0x00000000; // Start A/D Conversion
    
      do
      {
        i = AD0GDR; // Read A/D Data Register
      } while ((i & 0x80000000) == 0); // Wait for end of A/D Conversion
    
	return (i >> 6) & 0x03FF; // bit 6:15 is 10 bit AD value

}
//------------------------------------------------------------
int main()
{ 
	unsigned int delay,delay1,adc_value,prev_adc;
	char buf[10];
	init_uart();
	init_ADC();


  while(1)
	{
		  	adc_value = Read_ADC();	
				if(adc_value!=prev_adc){
					prev_adc=adc_value;
  	    sprintf((char *)buf, "%3d \n\r\n", adc_value);
				print_uart("ADC Value=");
				print_uart(buf);
				}
				for(delay=0; delay<10; delay++)
				for(delay1=0; delay1<500000; delay1++); 
	}
}    