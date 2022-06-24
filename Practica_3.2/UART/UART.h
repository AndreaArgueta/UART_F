/*
 * UART.h
 *
 *  Created on: 16 may 2022
 *      Author: Samantha
 */

#ifndef UART_UART_H_
#define UART_UART_H_

extern void Configurar_UART3(void);
extern char readChar(void);
extern char readDato(void);
extern void writeChar(char c);
extern void writeDato(char c);
extern void writeString(char* string);
extern char * readString(char delimitador);
extern void DelayMs(int s);


#endif /* UART_UART_H_ */
