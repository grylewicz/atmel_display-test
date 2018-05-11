/*
 * mini_test.c
 *
 *  Created on: 16-01-2013
 *      Author: wojtek
 *      Version: 1.0
 */
#include <avr/io.h>
#include <util/delay.h>
int main (void)
{
	unsigned char segment, cyfra;							//deklaracja zmiennych
	DDRA |= 0x03;											//PA.0 i PA.1 jako wyjścia
	DDRB = 0xFF;											//wszystkie PB jako wyjścia
	DDRD = 0xFF;											//wszystkie PD jako wyjścia
	PORTA &= 0xFC;											//ustawienie '0' na PA.0 i PA.1
	PORTD = 0xFF;											//ustawienie '1' na PORTD
	while (1)												//nieskończona pętla
	{
		for (cyfra = 0; cyfra < 8; cyfra++) 				//pętla ustawiająca '1' na porcie B
		{
			PORTD = 0xFF;									//wygaszenie segmentów
			PORTB = (1<<cyfra);								//ustawienie '1' na danym pinie portu B
			_delay_ms(500);									//opóźnienie 0,5s
			if (cyfra < 4)									//jeśli cyfra mniejsza niż 4, to zapalaj segmenty
			{
				for (segment = 0; segment < 7; segment++)	//pętla zapalająca kolejne segmenty
				{
					PORTD = ~(1<<segment);
					_delay_ms(500);
				}
			}
		}
		PORTB = 0x00;										//zgaś diodę na pinie PB.7
		PORTA |= 0xFD;										//zapal diodę na PA.0
		_delay_ms(500);
		PORTA &= 0xFC;										//zgaś diodę
		PORTA |= 0xFE;										//zapal diodę na PA.1
		_delay_ms(500);
		PORTA &= 0xFC;										//zgaś diodę
	}
}

