#ifndef LCD_H
#define LCD_H

void LCD_Init();
void LCD_Clear();
void LCD_String(const char *str);
void LCD_Command(unsigned char cmnd);
void LCD_Char(unsigned char data);
void updateLCD(float temperature, float upperLimit);

#endif
