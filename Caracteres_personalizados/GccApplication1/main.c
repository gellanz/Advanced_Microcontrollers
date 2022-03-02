#define F_CPU 16000000UL
#include <util/xc.h>
#include <avr/io.h>

#include <util/delay.h>
#include <util/lcdA.h>

int main(void)
{
	DDRC=0xFF;
	LCD_INICIALIZA();
	LIMPIA_LCD();
	CAR_ESP0();
	_delay_ms(100);
	CAR_ESP1();
	_delay_ms(100);
	CAR_ESP2();
	_delay_ms(100);
	CAR_ESP3();
	_delay_ms(100);
	CAR_ESP4();
	_delay_ms(100);
	CAR_ESP5();
	_delay_ms(100);
	CAR_ESP6();
	_delay_ms(100);
	CAR_ESP7();
	_delay_ms(100);
	LIMPIA_LCD();
	REGRESO_CASA();
	animacion();
	ENVIA_CADENA("ELIZARRARAS G");
	ENVIA_DATO(0);
	ENVIA_DATO(1);
	POS_LINEA2(0);
	ENVIA_CADENA ("2015170276");
	// CAR_ESP1();
	// _delay_ms(100);
	ENVIA_DATO(2);
	ENVIA_DATO(3);
	ENVIA_DATO(4);
	ENVIA_DATO(5);
	ENVIA_DATO(6);
	ENVIA_DATO(7);
	
}

