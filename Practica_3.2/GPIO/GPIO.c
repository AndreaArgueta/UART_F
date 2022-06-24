/*
 * GPIO.c
 *
 *  Created on: 3 jun 2022
 *      Author: Samantha
 */
#include "lib/include.h"

extern void Configurar_GPIO(void)
{
                            // K
        SYSCTL->RCGCGPIO |= (1<<9);
        GPIOK->DIR = (1<<3)|(0<<2);
        GPIOK->DIR = 0x8;
        //Habilitarlos como digitales
        GPIOK->DEN |= (1<<3)|(1<<2);
}



