/*
 * LCD_LIB.c
 *
 *  Created on: Jan 8, 2023
 *      Author: Ali
 */

#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "tim.h"
extern TIM_HandleTypeDef timer;


void LCD_delay(uint32_t us){
	HAL_TIM_Base_Start(&htim1);
	htim1.Instance->CNT=0;
	while(htim1.Instance->CNT <value);

}


void LCD_init(){

	LCD_send_cmd(0x02);		// To initialize LCD in 4-bit mode.
	HAL_Delay(1);
	LCD_send_cmd(0x28);		// To initialize LCD in 2 lines, 5x7 dots and 4bit mode.
	HAL_Delay(1);
	LCD_send_cmd(0x0C);
	HAL_Delay(1);
	LCD_send_cmd(0x06);
	HAL_Delay(1);
	LCD_send_cmd(0x80);
	HAL_Delay(1);

//    HAL_GPIO_WritePin(GPIOE, RS_Pin, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOE, E_Pin, GPIO_PIN_RESET);
//    LCD_send_data(0x00);
//    HAL_Delay(150);
//    LCD_send_cmd(0x03);
//    HAL_Delay(5);
//    LCD_send_cmd(0x03);
//    LCD_delay(150);
//    LCD_send_cmd(0x03);
//    LCD_send_cmd(0x02);
//    LCD_send_cmd(0x02);
//    LCD_send_cmd(0x08);
//    LCD_send_cmd(0x00);
//    LCD_send_cmd(0x0C);
//    LCD_send_cmd(0x00);
//    LCD_send_cmd(0x06);
//    LCD_send_cmd(0x00);
//    LCD_send_cmd(0x01);

}


void LCD_send_data(char data){

	char datatosend;
	datatosend = ((data>>4)&0x0f);
	LCD_send(datatosend, 1);
	datatosend = ((data)&0x0f);
	LCD_send(datatosend, 1);
}


void LCD_send_cmd(char cmd){

    char datatosend;
    datatosend = ((cmd>>4)&0x0f);
    LCD_send(datatosend,0);
    datatosend = ((cmd)&0x0f);
    LCD_send(datatosend, 0);

}


void LCD_send(char data, int rs){

    HAL_GPIO_WritePin(GPIOE, RS_Pin, rs);

    HAL_GPIO_WritePin(GPIOE, D7_Pin, ((data>>3)&0x01));
    HAL_GPIO_WritePin(GPIOE, D6_Pin, ((data>>2)&0x01));
    HAL_GPIO_WritePin(GPIOE, D5_Pin, ((data>>1)&0x01));
    HAL_GPIO_WritePin(GPIOE, D4_Pin, ((data>>0)&0x01));

    HAL_GPIO_WritePin(GPIOE, E_Pin, 1);
    //LCD_delay(200);
    /*--working:
     *  HAL_Delay(4);
     */
    HAL_Delay(4);
    //LCD_delay(4000000);
    HAL_GPIO_WritePin(GPIOE, E_Pin, 0);
    //LCD_delay(0);
}


void LCD_send_string(char *str){
	HAL_Delay(4);
	while (*str) LCD_send_data(*str++);
}


void LCD_cur(int row, int col){

    switch(row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }
    LCD_send_cmd(col);
}


void LCD_cls(){
	//LCD_send_cmd(0x00);
	LCD_send_cmd(0x01);
	HAL_Delay(1);
}

