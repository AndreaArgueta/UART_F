/*
 * UART.c
 *
 *  Created on: 16 may 2022
 *      Author: andya
 */
#include "../lib/include.h"
extern void Configurar_UART3(void)
{
    SYSCTL->RCGCUART = (1<<3); // Habilitar UART 3
    SYSCTL->RCGCGPIO |= (1<<0); // Habilitar puerto A          Pag 1163
    GPIOA_AHB->DIR = (1<<5) | (0<<4); // Entrada(Rx) y salida(Tx)
    GPIOA_AHB->AFSEL = (1<<5 | 1<<4); //A5 Tx, A4 Rx
    GPIOA_AHB->PCTL = (0x01<<20) | (0x01<<16); // indica que tipo de periferico
    GPIOA_AHB->DEN = (1<<5) | (1<<4); //Digitales

    UART3->CTL = (0<<9) | (0<<8) | (0<<0);
    //IBRD = 40,000,000 / (16 * 115200) = 21.7013   pag 1172
    //FBRD = integer(0.7013 * 64 + 0.5) = 45.38
    UART3->IBRD=21;
    UART3->FBRD=45;
    UART3->LCRH = (0x3<<5)|(0<<4); //1186, bit 5 longitud de palabra (min 5 max 8) || Bit 4 desabilita la pila
    UART3->CC = (0<<0); // seleccionar reloj del sistema
    UART3->CTL = (1<<0)|(1<<8)|(1<<9); // bit 8 y 9 habilitan transmisión y recepción, bit 0 habilita el UART

}
extern char readChar(void)
{
    int v;
    char c;
    while ((UART3->FR & (1<<4)) !=0);
    v = UART3->DR & 0xFF;
    c=v;
    return c;
}

extern void writeDato(char c)
{
    while((UART3->FR & (1<<5)) != 0);
    UART3->DR = c;
}




