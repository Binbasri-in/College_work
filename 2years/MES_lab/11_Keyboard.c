#include <LPC214x.H>                       /* LPC214x definitions */

#define LCDEN	           (1 << 2)
#define LCDRS	           (1 << 3)

//#define LCD_DATA_MASK           0x007F8000

/****************************************************************************
  Function Name : delay()
********************************************************************************/
void delay(unsigned int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    for(i=0;i<120;i++);
  }
}
/********************************************************************************************
  Function Name :	lcd_command_write()
*********************************************************************************************/
void lcd_command_write( unsigned char command )
{
  unsigned int temp=0;
  temp=(command << 15);
  IO0CLR = 0x007F8000; 
  IO0SET = temp;
  IO0CLR = LCDRS;
  IO0SET = LCDEN;
  delay(5);
  IO0CLR = LCDEN;
  delay(5);
}
/**********************************************************************************************
  Function Name :	lcd_data_write()
*********************************************************************************************/
void lcd_data_write( unsigned char data )
{
  unsigned int temp=0;
  temp=(data << 15);
  IO0CLR = 0x007F8000;
  IO0SET = temp;
  IO0SET = LCDEN | LCDRS;
  delay(5);
  IO0CLR = LCDEN;
  delay(5);
}
/**********************************************************************************************
  Function Name :	lcd_gotoxy()
*********************************************************************************************/
int lcd_gotoxy( unsigned char x,unsigned char y)
{
    lcd_command_write( 0x80 + y );		
}
/**********************************************************************************************
  Function Name :	lcd_putchar()
*********************************************************************************************/
void lcd_putchar( unsigned char c )
{
 lcd_data_write( c );
}
/**********************************************************************************************
  Function Name :	init_lcd()
*********************************************************************************************/
void init_lcd( void )
{
  IO0DIR |= ( LCDEN | LCDRS );
  IO0CLR = ( LCDEN | LCDRS );	
  IO0DIR |= 0x007F8000;
  delay(1000);
  lcd_command_write(0x38);     /*   8-bit interface, two line, 5X7 dots.        */
  lcd_command_write(0x10);     /*     display shift       */
  lcd_command_write(0x0C);     /*     display on          */
  lcd_command_write(0x06) ;    /*   cursor move direction */
  lcd_command_write(0x01) ;    /*   cursor home      */
  delay(1000);
}

// Part 2
/////////////////////////////////////////////

#define COL1	   0X00010000  // OR       (1 << 16)  
#define COL2	   0X00020000  // OR       (1 << 17)
#define COL3	   0X00040000  // OR       (1 << 18)
#define COL4	   0X00080000  // OR       (1 << 19)

#define ROW1	   0X00100000  // OR       (1 << 20)
#define ROW2	   0X00200000  // OR       (1 << 21)
#define ROW3	   0X00400000  // OR       (1 << 22)
#define ROW4	   0X00800000  // OR       (1 << 23)

/////////////// COLUMN WRITE /////////////////////
void col_write( unsigned char data )	
{
  unsigned int temp=0;
  temp=(data << 16);

  IO1CLR = (COL1 | COL2 | COL3 | COL4);
  IO1SET = temp;
}
///////////////////////////////// MAIN  ///////////////////////////////////////
int main (void) 
{
unsigned char key, i;
unsigned char rval[] = {0x7,0xB,0xD,0xE,0x0};
unsigned char keyPadMatrix[] = 
{ 
    'C','8','4','0',
    'D','9','5','1',
    'E','A','6','2',
    'F','B','7','3'
};

  init_lcd();

  IO1DIR |= 0X000F0000;  //Set COLs as Outputs and Set ROW lines as Inputs
while (1)
 {
    key = 0;
    for( i = 0; i < 4; i++ )
    {       
        // turn on COL output one by one
		col_write(rval[i]);
        // read rows - break when key press detected
        if (!(IO1PIN & ROW1))
            break;
        key++;
        if (!(IO1PIN & ROW2))
            break;
        key++;
        if (!(IO1PIN & ROW3))
            break;
        key++;
		if (!(IO1PIN & ROW4))
            break;
        key++;
    }
  	if (key == 0x10) 
		{	
			key==0;
		}
		else
		{
			lcd_gotoxy(0,2);
			lcd_putchar(keyPadMatrix[key]);
		}
 }

}
