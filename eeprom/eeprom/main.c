/*
 * eeprom.c
 *
 * Created: 21/10/2021 03:08:29 p. m.
 * Author : 410
 */ 

#define F_CPU 16000000UL 
#include <avr/io.h> 
#include <avr/eeprom.h> 
#include <util/delay.h> 

uint8_t EEMEM direccion; // Reserva una localidad de memoria llamada direccion
uint8_t dato;
int main(void) { 
	short int indice;

	DDRB = 0x00; 
	PORTB = 0xFF; 

	DDRC = 0x00; 
	PORTC = 0xFF;

	DDRD = 0xFF; 
	// PORTD = 0xFF;

	// DDRB = 0xFF; 
	while(1) { 
		indice = PINB & 0x3; 
		switch(indice){ 
			case 1: // leer de la EEPROM 
				direccion = PINC & 0b00000111;
				dato=eeprom_read_byte(direccion); 
				_delay_ms(1000); 
				PORTD = dato >> 1; 
				break; 
			case 2: // escribir en la EEPROM 
				direccion = PINC & 0b00000111;
				dato = PINC & 0b00111000; 
				eeprom_write_byte(direccion, dato); 
				_delay_ms(1000); 
				PORTD = EEDR >> 1; 
				_delay_ms(1000); 
				PORTD = EEAR >> 1; 
				_delay_ms(1000); 
				PORTD=0x00; 
				_delay_ms(1000); 
				break; 
			} 
		} 
}

