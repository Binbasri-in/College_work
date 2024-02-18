#include <LPC214x.h>
//-----------------------------------------------------
void init_uart()
{
    PINSEL0 = 0x5;   //P0.0 & P0.1 are configured as TXD0 & RXD0
    U0LCR = 0x83;    // 8-bits,no parity ,2 stop bits,DLAB=1,Enable access to Divisor Latches
    U0DLM = 0x00;
    U0DLL = 0x61;    //U0DLM,U0DLL = 0x61 , 9600 bits/sec
    U0LCR = 0x03;   // DLAB=0,Disable access to Divisor Latches   
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
//-----------------------------------------------------
int main()
{ 
	init_uart();
	print_uart("Hello World \n\r\n");
} 