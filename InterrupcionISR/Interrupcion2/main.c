#define F_CPU 16000000UL
#include <util/xc.h>

#include <util/delay.h>
#include <util/lcdA.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>

int of = 0;
int count = 0;
char buffer[10];
ISR(TIMER0_OVF_vect){
	PORTD = 0b10000000;
	_delay_ms(500);
	PORTD = 0x00;
	LIMPIA_LCD();
	POS_LINEA1(3);
	ENVIA_CADENA("Ya estas pdo");
	_delay_ms(1000);
	of = 1;
	count = 0;
	TCNT0 = 255;
}

int main(void)
{
	int indice;			//SELECTOR DE PUSH (PD1,PD2,PD3)
	int indice2;			//SELECTOR DE PUSH (PD1,PD2,PD3)
	cli();
	TCCR0B=(1<<CS02)|(1<<CS01)|(1<<CS00); //RELOJ FLANCO DE SUBIDA
	TIMSK0=(1<<TOIE0);	//HABILITA LA INTERRUPCIÓN POR SOBREFLUJO DEL TIMER 0
	DDRD = 0b10000000;		//PARA INT EXTERNA Y CONFIGURACION DE CONTEO
	DDRB = 0x00;		//PARA LED
	DDRC = 0xFF;		//LCD
	TCNT0 = 255;
	sei();
	LCD_INICIALIZA();
	LIMPIA_LCD();
	REGRESO_CASA();
	while(1)
	{
		of = 0;
		LIMPIA_LCD();
		POS_LINEA1(1);
		ENVIA_CADENA("Cuantas chelas?");
		POS_LINEA2(2);
		ENVIA_CADENA("A:2 B:4 C:6");
		while (of==0)
		{
			indice = PINB & 0b1110;
			indice = indice >> 1;
			switch(indice)
			{
				case 1:
					LIMPIA_LCD();
					POS_LINEA1(3);
					ENVIA_CADENA("Ahi van 2");
					TCNT0 = 255-2;
					of = 1;
				break;
				case 2:
					LIMPIA_LCD();
					POS_LINEA1(3);
					ENVIA_CADENA("Ahi van 4");
					TCNT0 = 255-4;
					of = 1;
				break;
				case 4:
					LIMPIA_LCD();
					POS_LINEA1(3);
					ENVIA_CADENA("Ahi van 6");
					TCNT0 = 255-6;
					of = 1;
				break;
			}
		}
		of = 0;
		POS_LINEA2(0);
		ENVIA_CADENA("Llevas: 0");
		while(of==0)
		{
			indice2 = PIND & 0b10000;
			_delay_ms(150);
			//if (indice==16)
			switch(indice2)
			{
			case 16:
				POS_LINEA2(8);
				count = count + 1;
				itoa(count,buffer,10);
				ENVIA_CADENA(buffer);
			break;
			}
		}
	}
}
