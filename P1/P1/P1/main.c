/*
 * P1.c
 *
 * Created: 08/09/2021 08:20:31 p. m.
 * Author : 410
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRD = 0x00; // entradas
	DDRB = 0x00; // entradas	
	DDRC = 0xFF; // salidas
	int cicloned = 0b0000001;
	int ciclonei = 0b1000000;
	int x;	
    /* Replace with your application code */
    while (1) 
    {
		x = PIND;
		if (PINB == 0b0000000) {
			PORTC = 0b1010101;
			_delay_ms(750);
			PORTC = 0b0101010;
			_delay_ms(750);
		} else if (PINB == 0b0000010) {
			PORTC = x >> 2;		
			_delay_ms(50);
		} else if (PINB == 0b0000001) { 
			// Ciclone Eyes derecha

				for (int i = 1; i <= 8; i++) {
					PORTC = cicloned;
					cicloned = cicloned << 1;
					_delay_ms(100);
				}
				cicloned = 0b0000001;					
				for (int i = 1; i <= 8; i++) {
					PORTC = ciclonei;
					ciclonei = ciclonei >> 1;
					_delay_ms(100);
				}
				ciclonei = 0b1000000;
			//PORTC = 0b1001111;
		}
	
    }
}

