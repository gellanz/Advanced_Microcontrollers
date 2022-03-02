/*
 * P2-LCD.c
 *
 * Created: 30/09/2021 03:26:07 p. m.
 * Author : 410
 */ 

#define F_CPU 160000000L

#include <util/xc.h>
#include <avr/io.h>

#include <util/delay.h>
#include <util/lcdA.h>

int main(void)
{
	DDRD=0xFF;
	LCD_INICIALIZA();
	LIMPIA_LCD();
	CAR_ESP0();
	_delay_ms(100);
	CAR_ESP1();
	_delay_ms(100);
	LIMPIA_LCD();
	REGRESO_CASA();
	ENVIA_CADENA("Micros");
	ENVIA_DATO(0);
	ENVIA_CADENA ("Avanzados");
	POS_LINEA2(0);
	ENVIA_CADENA("TAVO");
	ENVIA_DATO(' ');
	ENVIA_DATO(1);
	ENVIA_CADENA(" A UPIITA ");
	ENVIA_DATO(' ');
	ENVIA_DATO(1);
}

