/*
 * PWM.c
 *
 * Created: 05/12/2021 01:40:26 p. m.
 * Author : 410
 */ 

#define F_CPU 16000000UL
#include <util/xc.h>

#include <util/delay.h>
#include <util/lcdA.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>

double dutyCycleR = 0;
double dutyCycleG = 0;
double dutyCycleB = 0;

ISR(TIMER0_OVF_vect)
{
	OCR0A = (dutyCycleR/100.0)*255;
	OCR0B = (dutyCycleG/100.0)*255;
	OCR2B = (dutyCycleB/100.0)*255;
}

int main(void)
{
    int indice;
    char bufferR[10];
    char bufferG[10];
    char bufferB[10];
	
    // DDRD = 0xFF;		// PWM
	// 4 PWM channel outputs
	// DDRB |= 1<<PB3; // OC2A
	DDRD |= 1<<PD3; // OC2B
	DDRD |= 1<<PD5; // OC0B
	DDRD |= 1<<PD6; // OC0A	


	DDRB = 0x00;		// AUMENTAR PWM
	DDRC = 0xFF;		// LCD
	
	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
	TIMSK0 = (1 << TOIE0);

	sei();
	
	TCCR0B = (1 << CS00) | (1 << CS02);

//
    TCCR2A |= (1 << COM2B1) | (1<<WGM20) | (1<<WGM21) | (1<<WGM22);
	TIMSK0 = (1 << TOIE2);
	TCCR2B = (1 << CS20) | (1 << CS22);
//

	OCR0A = (dutyCycleR/100.0)*255.0;
    OCR0B = (dutyCycleG/100.0)*255.0;
    OCR2B = (dutyCycleB/100.0)*255.0;

    LCD_INICIALIZA();
	LIMPIA_LCD();
	REGRESO_CASA();

    /* Replace with your application code */
    while (1) 
    {
        indice = PINB & 0xFF;
		_delay_ms(30);
        
        switch(indice){
            case 0b0001:
                dutyCycleR += 10;
            break;
            case 0b0010:
                dutyCycleR -= 10;
            break;
			
            case 0b0100:
                dutyCycleG += 10;
            break;
            case 0b1000:
				dutyCycleG -= 10;
            break;
			
            case 0b00010000:
				dutyCycleB += 10;
            break;
            case 0b00100000:
				dutyCycleB -= 10;
            break;
        }
			
	
		if(dutyCycleR > 100 || dutyCycleR < 0)
		{
			dutyCycleR = 0;
            LIMPIA_LCD();
		}

		if(dutyCycleG > 100 || dutyCycleG < 0)
		{
			dutyCycleG = 0;
        	LIMPIA_LCD();
		}

		if(dutyCycleB > 100 || dutyCycleB < 0)
		{
			dutyCycleB = 0;
        	LIMPIA_LCD();
		}
        
        POS_LINEA1(1);
        itoa(dutyCycleR, bufferR, 10);
		ENVIA_CADENA("R: ");
		ENVIA_CADENA(bufferR);
		ENVIA_CADENA("%");

        POS_LINEA1(9);
        itoa(dutyCycleG, bufferG, 10);
		ENVIA_CADENA("G: ");
		ENVIA_CADENA(bufferG);
		ENVIA_CADENA("%");

        POS_LINEA2(1);
        itoa(dutyCycleB, bufferB, 10);
		ENVIA_CADENA("B: ");
		ENVIA_CADENA(bufferB);
		ENVIA_CADENA("%");
    }
}

