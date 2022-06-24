/**
 * main.c
 */
#include "lib/include.h"
int main(void)
{
    //char Dato;
    SetSystemClock_40MHz();
    Configurar_UART3();

    uint32_t a;
	while(1)
	{
	    //Lectura de dato
	    Dato=readChar();
	    //Escritura de dato
	    writeDato('H');
	    for(a=0;a<200000;a++){}
	    writeDato('O');
	    for(a=0;a<200000;a++){}
	    writeDato('L');
	    for(a=0;a<200000;a++){}
	    writeDato('A');
	    for(a=0;a<200000;a++){}
	}

}
