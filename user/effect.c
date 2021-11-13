#include "stm8s.h"
#include "stm8s_uart1.h"
#include "WS2812B.h"
#include "effect.h"
#include <time.h>

#define F_CPU 				16000000UL
#define dly_const			(F_CPU / 16000000UL)

unsigned char light_red =10;
unsigned char light_blue =0;
unsigned char light_green =0;

void Dir_Forward ()
{
  //WS2812B_reset();
  WS2812B_set_colour_on_channel(2, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(6, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(10, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(11, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(12, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(13, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(14, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(18, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(26, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(34, light_red, light_green, light_blue);
}

void Dir_Back ()
{
  //WS2812B_reset();
  WS2812B_set_colour_on_channel(2, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(6, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(12, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(16, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(17, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(18, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(19, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(8, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(26, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(34, light_red, light_green, light_blue);
}

void Dir_Right ()
{
  //WS2812B_reset();
  WS2812B_set_colour_on_channel(0, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(4, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(9, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(14, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(13, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(15, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(16, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(17, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(22, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(30, light_red, light_green, light_blue);


}

void Dir_Left ()
{
  //WS2812B_reset();
  WS2812B_set_colour_on_channel(0, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(4, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(8, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(10, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(11, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(19, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(9, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(15, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(22, light_red, light_green, light_blue);
  WS2812B_set_colour_on_channel(30, light_red, light_green, light_blue);

}

void pinwheel (direction_type direction, uint8_t number_repeat )
{
  uint8_t index;
  uint8_t colour_red = 0;
  uint8_t colour_green = 0;
  uint8_t colour_blue = 0;

  srand((int)time(NULL));
  if (direction == RIGHT)
  {
    for (index =0; index <number_repeat; index ++)
    {
        colour_red = rand() % 20;
        colour_green = rand() % 20;
        colour_blue = rand() % 20;
        // thang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(26, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(12, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(2, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(6, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(18, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(34, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo phai tren
        WS2812B_reset();
        WS2812B_set_colour_on_channel(1, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(24, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(5, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(32, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // ngang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(30, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(15, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(4, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(0, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(9, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(22, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo phai duoi
        WS2812B_reset();
        WS2812B_set_colour_on_channel(28, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(3, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(7, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(20, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // thang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(26, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(12, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(2, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(6, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(18, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(34, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo trai duoi
        WS2812B_reset();
        WS2812B_set_colour_on_channel(1, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(24, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(5, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(32, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // ngang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(30, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(15, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(4, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(0, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(9, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(22, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo trai tren
        WS2812B_reset();
        WS2812B_set_colour_on_channel(28, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(3, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(7, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(20, colour_red, colour_green, colour_blue);
        delay_ms(200);
    }
  }
  /*
  else if (direction == LEFT)
  {
     for (index =0; index <number_repeat; index ++)
    {
        colour_red = rand() % 20;
        colour_green = rand() % 20;
        colour_blue = rand() % 20;
        // thang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(26, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(12, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(2, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(6, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(18, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(34, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo phai duoi
        WS2812B_reset();
        WS2812B_set_colour_on_channel(28, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(3, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(7, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(20, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // ngang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(30, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(15, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(4, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(0, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(9, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(22, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo phai tren
        WS2812B_reset();
        WS2812B_set_colour_on_channel(1, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(24, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(5, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(32, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // thang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(26, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(12, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(2, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(6, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(18, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(34, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo trai tren
        WS2812B_reset();
        WS2812B_set_colour_on_channel(28, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(3, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(7, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(20, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // ngang
        WS2812B_reset();
        WS2812B_set_colour_on_channel(30, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(15, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(4, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(0, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(9, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(22, colour_red, colour_green, colour_blue);
        delay_ms(200);

        // cheo trai duoi
        WS2812B_reset();
        WS2812B_set_colour_on_channel(1, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(24, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(5, colour_red, colour_green, colour_blue);
        WS2812B_set_colour_on_channel(32, colour_red, colour_green, colour_blue);
        delay_ms(200);

    }
  }
  else
  {
  }

  */
}


void round_1 ()
{
    WS2812B_set_colour_on_channel(0, 100, 0, 0);
    WS2812B_set_colour_on_channel(1, 100,100, 0);
    WS2812B_set_colour_on_channel(2, 0, 100, 100);
    WS2812B_set_colour_on_channel(3, 0, 0, 100);
    WS2812B_set_colour_on_channel(4, 100, 0, 100);
    WS2812B_set_colour_on_channel(5, 0, 100, 100);
    WS2812B_set_colour_on_channel(6, 0, 100, 0);
    WS2812B_set_colour_on_channel(7, 100, 100, 100);
}

void round_2 ()
{
    WS2812B_set_colour_on_channel(8, 100, 0, 0);
    WS2812B_set_colour_on_channel(9, 100,100, 0);
    WS2812B_set_colour_on_channel(10, 0, 100, 100);
    WS2812B_set_colour_on_channel(11, 0, 0, 100);
    WS2812B_set_colour_on_channel(12, 100, 0, 100);
    WS2812B_set_colour_on_channel(13, 0, 100, 100);
    WS2812B_set_colour_on_channel(14, 0, 100, 0);
    WS2812B_set_colour_on_channel(15, 100, 100, 100);
    WS2812B_set_colour_on_channel(16, 100, 0, 100);
    WS2812B_set_colour_on_channel(17, 0, 100, 100);
    WS2812B_set_colour_on_channel(18, 0, 100, 0);
    WS2812B_set_colour_on_channel(19, 100, 100, 100);
}

void round_3 ()
{
    WS2812B_set_colour_on_channel(20, 100, 0, 0);
    WS2812B_set_colour_on_channel(21, 100,100, 0);
    WS2812B_set_colour_on_channel(22, 0, 100, 100);
    WS2812B_set_colour_on_channel(23, 0, 0, 100);
    WS2812B_set_colour_on_channel(24, 100, 0, 100);
    WS2812B_set_colour_on_channel(25, 0, 100, 100);
    WS2812B_set_colour_on_channel(26, 0, 100, 0);
    WS2812B_set_colour_on_channel(27, 100, 100, 100);
    WS2812B_set_colour_on_channel(28, 100, 0, 100);
    WS2812B_set_colour_on_channel(29, 0, 100, 100);
    WS2812B_set_colour_on_channel(30, 0, 100, 0);
    WS2812B_set_colour_on_channel(31, 100, 100, 100);
    WS2812B_set_colour_on_channel(32, 100, 0, 100);
    WS2812B_set_colour_on_channel(33, 0, 100, 100);
    WS2812B_set_colour_on_channel(34, 0, 100, 0);
    WS2812B_set_colour_on_channel(35, 100, 100, 100);
}

void into_inout(inout_type inout, uint8_t number_repeat )
{
    uint8_t index;
    if(inout == IN)
    {
      for (index = 0; index <number_repeat; index ++)
      {
        WS2812B_reset();
        round_3();
        delay_ms(1000);
        WS2812B_reset();
        round_2();
        delay_ms(1000);
        WS2812B_reset();
        round_1();
        delay_ms(1000);
      }
    }
    else if (inout == OUT)
    {
      for (index = 0; index <number_repeat; index ++)
      {
        WS2812B_reset();
        round_1();
        delay_ms(1000);
        WS2812B_reset();
        round_2();
        delay_ms(1000);
        WS2812B_reset();
        round_3();
        delay_ms(1000);
      }
    }
    else
    {
      /* Do not nothing */
    }
}

void into_inout_keep(inout_type inout, uint8_t number_repeat )
{
    uint8_t index;
    if(inout == IN)
    {
      for (index = 0; index <number_repeat; index ++)
      {
        WS2812B_reset();
        round_3();
        delay_ms(1000);
        round_2();
        delay_ms(1000);
        round_1();
        delay_ms(1000);
      }
    }
    else if (inout == OUT)
    {
      for (index = 0; index <number_repeat; index ++)
      {
        WS2812B_reset();
        round_1();
        delay_ms(1000);
        round_2();
        delay_ms(1000);
        round_3();
        delay_ms(1000);
      }
    }
    else
    {
      /* Do not nothing */
    }
}


void one_led_keep_inout(inout_type inout, uint8_t number_repeat)
{
  int8_t index =0;
  int8_t count = 0;
    if (inout == IN)
    {
      for (count = 0; count < number_repeat; count++)
      {
        WS2812B_reset();
        for(index = number_of_LEDs - 1; index >=0 ; index--)
        {
          WS2812B_set_colour_on_channel(index,light_red, light_green, light_blue);
          delay_ms(160);
        }
      }
    }
    else if (inout == OUT)
    {
      for (count = 0; count < number_repeat; count++)
      {
        WS2812B_reset();
        for(index = 0; index < number_of_LEDs; index++)
        {
          WS2812B_set_colour_on_channel(index,light_red, light_green, light_blue);
          delay_ms(160);
        }
      }
    }
    else
    {
      /* Do not nothing */
    }

}

void fireball (inout_type inout, uint8_t number_repeat)
{
   int8_t index =0;
   int8_t count = 0;
   if (inout == IN)
    {
      for (count = 0; count < number_repeat; count++)
      {
        for(index = number_of_LEDs - 1; index >=0 ; index--)
        {
          WS2812B_reset();
          WS2812B_set_colour_on_channel(index,light_red, light_green, light_blue);
          WS2812B_set_colour_on_channel(index-1,light_red, light_green, light_blue);
          WS2812B_set_colour_on_channel(index-2,light_red, light_green, light_blue);
          WS2812B_set_colour_on_channel(index-3,light_red, light_green, light_blue);
          delay_ms(200);
        }
      }
    }
    else if (inout == OUT)
    {
      for (count = 0; count < number_repeat; count++)
      {
        for(index = 0; index < number_of_LEDs; index++)
        {
          WS2812B_reset();
          WS2812B_set_colour_on_channel(index,light_red, light_green, light_blue);
          WS2812B_set_colour_on_channel(index+1,light_red, light_green, light_blue);
          WS2812B_set_colour_on_channel(index+2,light_red, light_green, light_blue);
          WS2812B_set_colour_on_channel(index+3,light_red, light_green, light_blue);
          delay_ms(200);
        }
      }
    }
    else
    {
      /* Do not nothing */
    }
}

/*
void one_round_center(uint8_t number_repeat)
{
  uint8_t index = 0;
  uint8_t i = 0;
   for (index =0; index <number_repeat; index++)
   {
      WS2812B_reset();
		for(i = 0; i < 4; i++)
		{
			WS2812B_set_colour_on_channel(0, 0, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 0, 0, 100);
			WS2812B_set_colour_on_channel(7, 0, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 0, 0, 100);
			WS2812B_set_colour_on_channel(6, 0, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 0, 0, 100);
			WS2812B_set_colour_on_channel(5, 0, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(4, 0, 0, 100);
			delay_ms(440);

			WS2812B_set_colour_on_channel(4, 0, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 0, 100, 0);
			WS2812B_set_colour_on_channel(5, 0, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 0, 100, 0);
			WS2812B_set_colour_on_channel(6, 0, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 0, 100, 0);
			WS2812B_set_colour_on_channel(7, 0, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(0, 0, 100, 0);
			delay_ms(440);

			WS2812B_set_colour_on_channel(0, 100, 0, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 100, 0, 0);
			WS2812B_set_colour_on_channel(7, 100, 0,0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 100, 0, 0);
			WS2812B_set_colour_on_channel(6, 100, 0, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 100, 0, 0);
			WS2812B_set_colour_on_channel(5, 100, 0, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(4, 100, 0, 0);
			delay_ms(440);

			WS2812B_set_colour_on_channel(4, 0, 0, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 0, 0, 0);
			WS2812B_set_colour_on_channel(5, 0, 0, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 0, 0, 0);
			WS2812B_set_colour_on_channel(6, 0, 0, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 0, 0, 0);
			WS2812B_set_colour_on_channel(7, 0, 0, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(0, 0, 0, 0);
			delay_ms(440);
		}

		WS2812B_reset();
		for(i = 0; i < 4; i++)
		{
			WS2812B_set_colour_on_channel(0, 0, 100, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(0, 0, 0, 0);
			WS2812B_set_colour_on_channel(1, 0, 100, 100);
			WS2812B_set_colour_on_channel(7, 0, 100, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 0, 0, 0);
			WS2812B_set_colour_on_channel(7, 0, 0, 0);
			WS2812B_set_colour_on_channel(2, 0, 100, 100);
			WS2812B_set_colour_on_channel(6, 0, 100, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 0, 0, 0);
			WS2812B_set_colour_on_channel(6, 0, 0, 0);
			WS2812B_set_colour_on_channel(3, 0, 100, 100);
			WS2812B_set_colour_on_channel(5, 0, 100, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 0, 0, 0);
			WS2812B_set_colour_on_channel(5, 0, 0, 0);
			WS2812B_set_colour_on_channel(4, 0, 100, 100);
			delay_ms(440);

			WS2812B_set_colour_on_channel(4, 100, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(4,0, 0, 0);
			WS2812B_set_colour_on_channel(3, 100, 100, 0);
			WS2812B_set_colour_on_channel(5, 100, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 0, 0, 0);
			WS2812B_set_colour_on_channel(5, 0, 0, 0);
			WS2812B_set_colour_on_channel(2, 100, 100, 0);
			WS2812B_set_colour_on_channel(6, 100, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 0, 0, 0);
			WS2812B_set_colour_on_channel(6, 0, 0, 0);
			WS2812B_set_colour_on_channel(1, 100, 100, 0);
			WS2812B_set_colour_on_channel(7, 100, 100, 0);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 0, 0, 0);
			WS2812B_set_colour_on_channel(7, 0, 0, 0);
			WS2812B_set_colour_on_channel(0, 100, 100, 0);
			delay_ms(440);

			WS2812B_set_colour_on_channel(0, 100, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(0, 0, 0, 0);
			WS2812B_set_colour_on_channel(1, 100, 0, 100);
			WS2812B_set_colour_on_channel(7, 100, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 0, 0, 0);
			WS2812B_set_colour_on_channel(7, 0, 0, 0);
			WS2812B_set_colour_on_channel(2, 100, 0, 100);
			WS2812B_set_colour_on_channel(6, 100, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 0, 0, 0);
			WS2812B_set_colour_on_channel(6, 0, 0, 0);
			WS2812B_set_colour_on_channel(3, 100, 0, 100);
			WS2812B_set_colour_on_channel(5, 100, 0, 100);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 0, 0, 0);
			WS2812B_set_colour_on_channel(5, 0, 0, 0);
			WS2812B_set_colour_on_channel(4, 100, 0, 100);
			delay_ms(440);

			WS2812B_set_colour_on_channel(4, 60, 60, 60);
			delay_ms(220);
			WS2812B_set_colour_on_channel(4,0, 0, 0);
			WS2812B_set_colour_on_channel(3, 60, 60, 60);
			WS2812B_set_colour_on_channel(5, 60, 60, 60);
			delay_ms(220);
			WS2812B_set_colour_on_channel(3, 0, 0, 0);
			WS2812B_set_colour_on_channel(5, 0, 0, 0);
			WS2812B_set_colour_on_channel(2, 60, 60, 60);
			WS2812B_set_colour_on_channel(6, 60, 60, 60);
			delay_ms(220);
			WS2812B_set_colour_on_channel(2, 0, 0, 0);
			WS2812B_set_colour_on_channel(6, 0, 0, 0);
			WS2812B_set_colour_on_channel(1, 60, 60, 60);
			WS2812B_set_colour_on_channel(7, 60, 60, 60);
			delay_ms(220);
			WS2812B_set_colour_on_channel(1, 0, 0, 0);
			WS2812B_set_colour_on_channel(7, 0, 0, 0);
			WS2812B_set_colour_on_channel(0, 160, 160, 160);
			delay_ms(440);
		}
   }
}

*/

/*
void control_motor()
{
    // motor 1
    GPIO_WriteHigh(GPIOD, GPIO_PIN_2);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);
    // motor 2
    GPIO_WriteHigh(GPIOB, GPIO_PIN_4);
    GPIO_WriteLow(GPIOB, GPIO_PIN_5);
    // motor 3
    GPIO_WriteHigh(GPIOD, GPIO_PIN_4);
    GPIO_WriteLow(GPIOA, GPIO_PIN_3);
    // motor 4
    GPIO_WriteHigh(GPIOA, GPIO_PIN_1);
    GPIO_WriteLow(GPIOA, GPIO_PIN_2);
    delay_ms(15000);

    GPIO_WriteLow(GPIOD, GPIO_PIN_2);
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
    // motor 2
    GPIO_WriteLow(GPIOB, GPIO_PIN_4);
    GPIO_WriteHigh(GPIOB, GPIO_PIN_5);
    // motor 3
    GPIO_WriteLow(GPIOD, GPIO_PIN_4);
    GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
    // motor 4
    GPIO_WriteLow(GPIOA, GPIO_PIN_1);
    GPIO_WriteHigh(GPIOA, GPIO_PIN_2);
    delay_ms(15000);

}

*/

void delay_us(unsigned int value)
{
	register unsigned int loops = dly_const * value ;

	while(loops)
	{
	        asm("nop");
		loops--;
	};
}

void delay_ms(unsigned int value)
{
	while(value)
	{
		delay_us(1000);
		value--;
	};
}