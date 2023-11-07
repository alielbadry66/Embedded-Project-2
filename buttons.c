#include "buttons.h"
#include <avr/io.h>
#include <util/delay.h>

#define UP_BUTTON_PIN (1 << PB2)
#define DOWN_BUTTON_PIN (1 << PB5)

void initButtons() {
    // Initialize the buttons as input and enable pull-up resistors
    DDRB &= ~(UP_BUTTON_PIN | DOWN_BUTTON_PIN);
    PORTB |= UP_BUTTON_PIN | DOWN_BUTTON_PIN;
}

void readButtons(float *upperLimit) {
    if (!(PINB & UP_BUTTON_PIN)) {
        *upperLimit += 1.0;
        _delay_ms(200); // Debounce
    }

    if (!(PINB & DOWN_BUTTON_PIN)) {
        *upperLimit -= 1.0;
        _delay_ms(200); // Debounce
    }
}
