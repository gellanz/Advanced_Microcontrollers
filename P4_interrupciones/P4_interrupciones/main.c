/*
 * P4_interrupciones.c
 *
 * Created: 14/10/2021 04:24:40 p. m.
 * Author : 410
 */ 

#define F_CPU 16000000UL
#include <util/xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/lcdA.h>

ISR(PCINT0_vect){
LIMPIA_LCD();
POS_LINEA1(0);
ENVIA_CADENA("UPIITA-IPN");	
for (int i=0; i<2; i++){
	for (int j = 0; j < 15; j++) {
		CURSOR_DER();
		_delay_ms(100);
	}
	for (int j = 0; j < 15; j++) {
		CURSOR_IZQ();
		_delay_ms(100);
	}
}
	
}

ISR(PCINT2_vect){
LIMPIA_LCD();
POS_LINEA2(0);
ENVIA_CADENA("2015170276");
for (int i=0; i<2; i++){
	for (int j = 0; j < 15; j++) {
		CURSOR_DER();
		_delay_ms(100);
	}
	for (int j = 0; j < 15; j++) {
		CURSOR_IZQ();
		_delay_ms(100);
	}
}
}

ISR (INT0_vect) {
LIMPIA_LCD();
POS_LINEA2(0);
ENVIA_DATO(4);
ENVIA_DATO(5);
for (int i=0; i<2; i++){
	for (int j = 0; j < 15; j++) {
		CURSOR_DER();
		_delay_ms(100);
	}
	for (int j = 0; j < 15; j++) {
		CURSOR_IZQ();
		_delay_ms(100);
	}
}	
}

ISR (INT1_vect) {
LIMPIA_LCD();
POS_LINEA1(0);
ENVIA_DATO(6);
ENVIA_DATO(7);
for (int i=0; i<2; i++){
	for (int j = 0; j < 15; j++) {
		CURSOR_DER();
		_delay_ms(100);
	}
	for (int j = 0; j < 15; j++) {
		CURSOR_IZQ();
		_delay_ms(100);
	}
}
}

int main(void)
{
	DDRC=0xFF;
	cli();
	EIMSK |= 0b00000011; 
	EICRA |= (1<<ISC01)|(1<<ISC00);
    PCICR  |= 0b00000001;
    PCMSK0 |= 0b00100000;
    PCICR  |= 0b00000100;
    PCMSK2 |= 0b00010000;
	sei();
	LCD_INICIALIZA();
	LIMPIA_LCD();
	while(1){
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
	POS_LINEA1(0);
	ENVIA_CADENA("Elizarraras");
	POS_LINEA2(0);
	ENVIA_CADENA("Gustavo");	
	for (int i=0; i<2; i++){
		for (int j = 0; j < 15; j++) {
		CURSOR_DER();
		_delay_ms(150);
		}
		for (int j = 0; j < 15; j++) {
		CURSOR_IZQ();
		_delay_ms(150);
		}
	}

	}
}

