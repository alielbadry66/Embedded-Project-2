#include "Temp_sensor.h"
#include <avr/io.h>

// Define constants
#define TEMPERATURE_SENSOR_PIN 0   // Analog pin A0 on Arduino Uno

// Function to initialize the ADC
void initADC() {
    // Set reference voltage to AVCC and left-adjust result
    ADMUX = (1 << REFS0) | (1 << ADLAR);

    // Enable ADC, enable ADC interrupt, and set prescaler to 128
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Function to read the temperature
uint16_t readADC() {
    // Select the ADC channel
    ADMUX = (ADMUX & 0b11111000) | (TEMPERATURE_SENSOR_PIN & 0b00000111);
    
    // Start the conversion
    ADCSRA |= (1 << ADSC);
    
    // Wait for the conversion to complete
    while (ADCSRA & (1 << ADSC));
    
    // Return the ADC result
    return ADC;
}

void initTemperatureSensor() {
    // Initialize the ADC
    initADC();
}

float readTemperature() {
    // Read the temperature from the LM35DZ
    uint16_t adcValue = readADC();
    
    // Convert ADC value to temperature in Celsius
    float temperatureC = (adcValue /120) - 50.0;  // LM35DZ provides 120mV per degree Celsius
    
    return temperatureC;
}
