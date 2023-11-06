#ifndef UART_H
#define UART_H

void initUART(unsigned long baud);
void sendUART(char data);
char receiveUART();

#endif
