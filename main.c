/*
 * File:   main.c
 * Author: Hossam Eldeen Altokhy
 *
 * Created on April 4, 2020, 6:24 PM
 */

#include <avr/io.h>
#include "DIO.h"
#define  BUTTON0         0
#define  BUTTON1         4
#define  BUTTON2         2
#define  LED0            2
#define  LED1            7
#define  LED2            3


#define portA           1
#define portB           2
#define portC           3
#define portD           4

int main(void) {

    // Data Direction Register
    //DDRA = 0xFF;
    //PORTA = 0x00;
    //DDRC = 0xFF;
    //PORTC = 0x00;
    //DDRB &= ~(1 << BUTTON); // INPUT PIN.
    //DDRD |= (1 << LED);
    DDRB &= ~(1 << BUTTON1);
    DDRB &= ~(1 << BUTTON0);
    DDRD &= ~(1 << BUTTON2);
    DDRD |= (1 << LED2);
    DDRC |= (1 << LED0);
    DDRC |= (1 << LED1);





    while (1) {
        // Loop until power OFF
        if (isPressedB(BUTTON0)) { //PINA & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON

            setPIN(LED0, portC);
        } else {
            // False Condition
            //            PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED0, portC);
        }
        if (isPressedB(BUTTON1)) { //PINA & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON
            setPIN(LED1, portC);
        } else {
            // False Condition
            //            PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED1, portC);
        }
        if (isPressedD(BUTTON2)) { //PINA & (1<<PIN_number)
            //True Condition
            //            PORTA |= (1<<LED); // Turn LED ON
            setPIN(LED2, portD);
        } else {
            // False Condition
            //            PORTA &= ~(1<<LED);// Turn LED OFF
            resetPIN(LED2, portD);
        }

    }
}

