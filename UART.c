/*
 * ComunicacionUART.c
 *
 * Creado: 
 * Autor: Luis
 */
#define F_CPU 16000000UL
#include "UART.h"
#include <util/delay.h>
#include <avr/io.h>

void UART_inicializar(void)
{
	DDRD |= (1<<PD1);          // Configurar el pin PD1 (TX) como salida
	DDRD &= ~(1<<PD0);         // Configurar el pin PD0 (RX) como entrada
	
	// Configurar el estado inicial del registro de control A de UART
	UCSR0A = (0<<TXC0)|(0<<U2X0)|(0<<MPCM0);
	
	// Configurar UART para habilitar transmisión y recepción
	UCSR0B = (1<<RXCIE0)|(0<<TXCIE0)|(0<<UDRIE0)|(1<<RXEN0)|(1<<TXEN0)|(0<<UCSZ02)|(0<<TXB80);
	
	// Configurar el modo UART, sin paridad, 1 bit de parada y tamaño de palabra de 8 bits
	UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)|(0<<UPM01)|(0<<UPM00)|(0<<USBS0)|(1<<UCSZ01)|(1<<UCSZ00)|(0<<UCPOL0);
	
	UBRR0 = 103;  // Configurar baudrate a 9600
}

unsigned char UART_leer(void)
{
	if (UCSR0A & (1<<RXC0))   // Comprobar si hay datos disponibles para lectura
	{
		return UDR0;          // Devolver el dato recibido
	}
	else
	{
		return 0;             // No hay datos disponibles
	}
}

void UART_escribir(unsigned char dato)
{
	while (!(UCSR0A & (1<<UDRE0)));  // Esperar hasta que el registro de datos esté listo para transmitir
	UDR0 = dato;                     // Enviar el dato por UART
}

void UART_enviar_cadena(char* texto)
{
	while (*texto != '\0')            // Enviar los caracteres de la cadena hasta encontrar el final ('\0')
	{
		UART_escribir(*texto);        // Enviar cada carácter
		texto++;                      // Avanzar al siguiente carácter
	}
}

void enviar_por_uart(uint8_t identificador)
{
	UART_escribir(identificador);     // Enviar un valor único o identificador
}

