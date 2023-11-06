#include "buzzer.h"
#include <avr/io.h>

void initBuzzer() {
    // Configure the buzzer pin as an output
    DDRB |= (1 << PB2);
}

void activateBuzzer() {
    PORTB |= (1 << PB2);  // Turn on the buzzer
}

void deactivateBuzzer() {
    PORTB &= ~(1 << PB2); // Turn off the buzzer
}
