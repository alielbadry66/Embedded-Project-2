#include "buttons.h"
#include <avr/io.h>
#include <util/delay.h>


#define UP_BUTTON_PIN (1 << PD3)
#define DOWN_BUTTON_PIN (1 << PD2)

void initButtons() {
    // Initialize the buttons as input and enable pull-up resistors
    DDRD &= ~(UP_BUTTON_PIN | DOWN_BUTTON_PIN);
    PORTD |= UP_BUTTON_PIN | DOWN_BUTTON_PIN;
}

void readButtons(float *upperLimit) {
   if (!(PIND & DOWN_BUTTON_PIN)) {
        *upperLimit -= 1.0;
        _delay_ms(200); // Debounce
    }
    
    if (!(PIND & UP_BUTTON_PIN)) {
      *upperLimit += 1.0;
      _delay_ms(200); // Debounce
    }


}
