# LCD16x2 STM32F4xx
Drive LCD 16x2 with 4pin, Without I2C 

#### ports:
All pins are set on GPIOE:
```
d7 -> pin 15 as D7_Pin
d6 -> pin 14 as D6_Pin
d5 -> pin 13 as D5_Pin
d4 -> pin 12 as D4_Pin
E  -> pin 11 as E_Pin
RS -> pin 10 as RS_Pin
RW -> pin 9  as RW_Pin
```

## LCD_LIB.c Library:

### LCD_init():
Send some command to LCD for turn LCD On and responsible and select 4pin Mode.<sub>(READ about commands in datasheet)</sub>

### LCD_send_data(char data):
Because we use 4pin mode we should split our character ASCII HEX to 4 highbit and 4 lowbit.

Then sending 4 highbit and 4 lowbit of character to LCD_send function with `rs = 0` (for sending data we need rs = 0, more information in LCD_send) 

### LCD_send_cmd(char cmd):
Work like LCD_send_data but with `rs = 1`

### LCD_send(char data, int rs):
At first we define RS_Pin with function `rs` input
```
RS_Pin must be 0 for sending data
RS_Pin must be 1 for sending data
```
In this step, `char` is 4 bit, so we send it by set our 4 Data Pin<sub>(D4-D7)</sub>, 1 or 0.

After that we set E_Pin, 1, to say to LCD that we sending data, read the pins! and give LCD some time, then set E_Pin to 0.

### LCD_send_string(char *str) :
This function get a string, select string characters and send them to LCD_send_data function.

### LCD_cur(int row, int col) :
Select curser location with command.<sub>(READ datasheet to know how it works)</sub>

### LCD_cls() :
Send Clear-Screen command to LCD and give LCD some time.
