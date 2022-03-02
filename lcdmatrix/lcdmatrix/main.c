/*
 * lcdmatrix.c
 *
 * Created: 07/10/2021 09:17:24 a. m.
 * Author : 410
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <util/TecladoBarrido.h>
#include <util/lcdA.h>

extern char VALOR_TECLADO;

int i=0;

int main(void)
{
	DDRC=0xFF;
	DDRD=0x00;
	DDRB=0xFF;
	LCD_INICIALIZA();
	LIMPIA_LCD();			//Limpia la pantalla del LCD

	while (1)
	{
		POS_LINEA2(i);
		
		BARRE_TECLADO();
		_delay_ms(10);
		LEE_TECLADO();
		if (VALOR_TECLADO!=0){
			//_delay_ms(500);
			//POS_LINEA2(0);
			ENVIA_DATO(VALOR_TECLADO);
			if ((VALOR_TECLADO=='A'))
			{
				LIMPIA_LCD();
				ENVIA_CADENA("Los Monos locos");
				i=0;
				POS_LINEA2(i);
			}
			if ((VALOR_TECLADO=='B'))
			{
				LIMPIA_LCD();
				ENVIA_CADENA("menu");
				i=0;
				POS_LINEA2(i);
			}
			_delay_ms(100);
			i++;
			VALOR_TECLADO=0;
		}
	}

}

