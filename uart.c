#include "uart.h"
#include <avr/io.h>

void initUART(unsigned long baud) {
    // Calculate the baud rate register value
    uint16_t ubrr_value = F_CPU / (16 * baud) - 1;

    // Set the baud rate register
    UBRR0H = (ubrr_value >> 8);
    UBRR0L = ubrr_value;

    // Enable transmitter and receiver
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    // Set data frame format: 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void sendUART(char data) {
    // Wait until the transmit buffer is empty
    while (!(UCSR0A & (1 << UDRE0)));

    // Put the data into the transmit buffer
    UDR0 = data;
}

char receiveUART() {
    // Wait until data is available in the receive buffer
    while (!(UCSR0A & (1 << RXC0)));

    // Return the received data
    return UDR0;
}
