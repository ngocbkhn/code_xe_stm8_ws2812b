#ifndef _EFFECT_HEADER_
#define _EFFECT_HEADER_

typedef enum direction{
                       RIGHT = 0,
                       LEFT = 1
                       } direction_type;

typedef enum in_out{
                       IN = 0,
                       OUT = 1
                       } inout_type;

void Dir_Forward ();

void Dir_Back ();

void Dir_Right ();

void Dir_Left ();

void pinwheel (direction_type direction, unsigned char number_repeat );

void round_1 ();

void round_2 ();

void round_3 ();

void into_inout(inout_type inout, uint8_t number_repeat );

void into_inout_keep(inout_type inout, uint8_t number_repeat );

void one_led_keep_inout(inout_type inout, uint8_t number_repeat);

void fireball (inout_type inout, uint8_t number_repeat);

// void one_round_center(uint8_t number_repeat);

// void control_motor();

void delay_us(unsigned int value);

void delay_ms(unsigned int value);

extern unsigned char light_red;
extern unsigned char light_blue;
extern unsigned char light_green;

#endif /* _EFFECT_HEADER_ */