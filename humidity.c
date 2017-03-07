/*
 * humidity.c
 *
 * Created: 06-07-2016 12:12:13
 *  Author: RISHABH JAIN
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "lcd_4b.h"

int main(void)
{
	DDRB=0xFF;
	ADMUX|=(1<<REFS0);
	int r;
	char ar[10];
	_delay_ms(10);
	lcd_init(LCD_DISP_ON_CURSOR);
    while(1)
    {
	  PORTB=0x01;
      r=adc_init();
	  _delay_ms(10);
	  sprintf(ar,"%d",r);
	  _delay_ms(10);
	  lcd_puts(ar);
	  _delay_ms(5000);
	  lcd_clrscr();
    }
}