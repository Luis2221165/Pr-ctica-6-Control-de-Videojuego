/*
 * ComunicacionUART.h
 *
 * Creado: 23/07/2024 00:54:29
 * Autor: Usuario
 */

#include <avr/io.h>
#include <util/delay.h>

#ifndef COMUNICACIONUART_H_
#define COMUNICACIONUART_H_

// Declaraciones de funciones para la inicializaci�n y manejo de UART
void UART_inicializar(void);                // Inicializaci�n del m�dulo USART
unsigned char UART_recibir(void);           // Funci�n para recibir un byte
void UART_transmitir(unsigned char dato);   // Funci�n para transmitir un byte
void UART_enviar_cadena(char* texto);       // Funci�n para enviar una cadena de texto
void enviar_por_uart(uint8_t identificador); // Enviar identificador �nico

#endif /* COMUNICACIONUART_H_ */
