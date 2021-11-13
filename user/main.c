/**
  ******************************************************************************
  * @file    Project/main.c
  * @author  Minh Nguyen
  * @version V2.2.0
  * @date    22-March-2020
  * @brief   Main program body
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */



/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_uart1.h"
#include "WS2812B.h"
#include "effect.h"
#include "stm8s_it.h"

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void CLK_Cofiguration(void);
void GPIO_Configuration(void);
void UART1_Config(void);
void Timer1_int_Configuration(void);
void delay_us(unsigned int value);
void delay_ms(unsigned int value);
/* Private functions ---------------------------------------------------------*/
volatile char receive_data=0, buffer_data=0;




void main(void)
{

   CLK_Cofiguration(); // if function not call - the system CLK is 2MHz - if it call - the system CLK is 16MHz
   GPIO_Configuration(); // Config Blink PB5 and Pin PC3 to control led WS2812B
   UART1_Config();       // Config UART if single form HC05
   Timer1_int_Configuration();   // set up timer to blink led


  while (1)
  {
    pinwheel(RIGHT, 10);

  }
}

void Timer1_int_Configuration(void)
{
    TIM1_DeInit();						// reset all resgister timer1
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, ENABLE);	// provide clock for timer1
    TIM1_TimeBaseInit(15999,TIM1_COUNTERMODE_UP,1000,0);      // config frequency interrupt PSC= 15999+1 =16000, ARR = 1000 => F_interrupt = 16*10^6 / 16000/1000 = 1Hz = 1s
    TIM1_ARRPreloadConfig(ENABLE);				// enable register auto reload active -  over counter -> reset counter
    TIM1_ITConfig(TIM1_IT_UPDATE,ENABLE);		        // ennable over inerrupt
    TIM1_ClearFlag(TIM1_FLAG_UPDATE);	                        // clear flag over counter for firttime run
    TIM1_Cmd(ENABLE);						// enable timer active
    enableInterrupts();						// enable global interrupt
}

void UART1_Config(void)
{
   UART1_Init(9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
                    UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);

   UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);

   UART1_Cmd(ENABLE);

   enableInterrupts();
}

void CLK_Cofiguration(void)
{
  CLK_DeInit();																	// reset tat ca cac nguon clock
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);//config clock HSI with devide 1 - 16Mhz/1=16Mhz
}

void GPIO_Configuration(void)
{
  GPIO_DeInit(GPIOB); // reset all register port B
  // two pin for motor 2
  GPIO_Init(GPIOB,GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST); //config pin PD2 of portD with mode push pull speed 10Mhz
  GPIO_Init(GPIOB,GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);

  GPIO_DeInit(GPIOD); // reset all register port D
  // two pin for motor 1
  GPIO_Init(GPIOD,GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST); //config pin PD2 of portD with mode push pull speed 10Mhz
  GPIO_Init(GPIOD,GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);

  GPIO_DeInit(GPIOA); // reset all register port A
  // two pin for motor 4
  GPIO_Init(GPIOA,GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_FAST); //config pin PD2 of portD with mode push pull speed 10Mhz
  GPIO_Init(GPIOA,GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);

  // two pin for motor 3
  GPIO_Init(GPIOD,GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST); //config pin PD2 of portD with mode push pull speed 10Mhz
  GPIO_Init(GPIOA,GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);

  // pin for control led
  GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_WriteLow(GPIOC, GPIO_PIN_3);
}


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
