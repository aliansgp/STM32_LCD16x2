/*
 * LCD_LIB.h
 *
 *  Created on: Jan 8, 2023
 *      Author: Ali
 */

#ifndef INC_LCD_LIB_H_
#define INC_LCD_LIB_H_
#include "stm32f4xx_hal.h"

void LCD_init();
void LCD_cur(int row, int col);
void LCD_send_string(char *STR);
void LCD_cls();



#endif /* INC_LCD_LIB_H_ */
