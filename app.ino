#include <util/delay.h>
#include "LCD.h"
#include "lcd.c"
#include "Temp_sensor.h"
#include "Temp_sensor.c"
#include "uart.h"
#include "uart.c"
#include "buzzer.h"
#include "buzzer.c"
#include "buttons.h"
#include "buttons.c"

#define TEMP_UPPER_LIMIT 40.0

int main() {
    LCD_Init();
    LCD_String("Temperature Control");

    initTemperatureSensor();
    initUART(9600);
    initBuzzer();
    initButtons();  // Initialize the buttons

    float currentUpperLimit = TEMP_UPPER_LIMIT;

    while (1) {
        float temperature = readTemperature();

        // Read the push buttons and update the upper limit
        readButtons(&currentUpperLimit);

        if (temperature > currentUpperLimit) {
            activateBuzzer();
        } else {
            deactivateBuzzer();
        }

        // Update the LCD display with the upper limit
        updateLCD(temperature, currentUpperLimit);

        _delay_ms(1000);
    }

    return 0;
}
