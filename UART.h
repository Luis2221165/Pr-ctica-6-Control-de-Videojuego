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

// Declaraciones de funciones para la inicialización y manejo de UART
void UART_inicializar(void);                // Inicialización del módulo USART
unsigned char UART_recibir(void);           // Función para recibir un byte
void UART_transmitir(unsigned char dato);   // Función para transmitir un byte
void UART_enviar_cadena(char* texto);       // Función para enviar una cadena de texto
void enviar_por_uart(uint8_t identificador); // Enviar identificador único

#endif /* COMUNICACIONUART_H_ */
