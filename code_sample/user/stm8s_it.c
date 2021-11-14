/**
  ******************************************************************************
  * @file     stm8s_it.c
  * @author   MCD Application Team
  * @version  V2.2.0
  * @date     30-September-2014
  * @brief    Main Interrupt Service Routines.
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
#include "stm8s_it.h"
#include "WS2812B.h"
#include "effect.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

// Motor 1
#define IA1_Pos                         GPIO_WriteHigh(GPIOD, GPIO_PIN_2)
#define IA1_Nega                        GPIO_WriteLow(GPIOD, GPIO_PIN_2)
#define IB1_Pos                         GPIO_WriteHigh(GPIOD, GPIO_PIN_3)
#define IB1_Nega                        GPIO_WriteLow(GPIOD, GPIO_PIN_3)

// Motor 2
#define IA2_Pos                         GPIO_WriteHigh(GPIOB, GPIO_PIN_4)
#define IA2_Nega                        GPIO_WriteLow(GPIOB, GPIO_PIN_4)
#define IB2_Pos                         GPIO_WriteHigh(GPIOB, GPIO_PIN_5)
#define IB2_Nega                        GPIO_WriteLow(GPIOB, GPIO_PIN_5)

// Motor 3
#define IA3_Pos                         GPIO_WriteHigh(GPIOA, GPIO_PIN_3)
#define IA3_Nega                        GPIO_WriteLow(GPIOA, GPIO_PIN_3)
#define IB3_Pos                         GPIO_WriteHigh(GPIOD, GPIO_PIN_4)
#define IB3_Nega                        GPIO_WriteLow(GPIOD, GPIO_PIN_4)

// Motor 4
#define IA4_Pos                         GPIO_WriteHigh(GPIOA, GPIO_PIN_1)
#define IA4_Nega                        GPIO_WriteLow(GPIOA, GPIO_PIN_1)
#define IB4_Pos                         GPIO_WriteHigh(GPIOA, GPIO_PIN_2)
#define IB4_Nega                        GPIO_WriteLow(GPIOA, GPIO_PIN_2)
/* Private variables ---------------------------------------------------------*/
  extern char receive_data, buffer_data;
  extern bool state;
  int stt = 0;
  extern void Dir_Forward ();
  extern void Dir_Back();
  extern void delay_ms(unsigned int value);
  extern void Dir_Right ();
  extern void Dir_Left ();


   uint8_t order =0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/** @addtogroup GPIO_Toggle
  * @{
  */
#ifdef _COSMIC_
/**
  * @brief  Dummy interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(NonHandledInterrupt, 25)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*_COSMIC_*/

/**
  * @brief  TRAP interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  Top Level Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TLI_IRQHandler, 0)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Auto Wake Up Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(AWU_IRQHandler, 1)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Clock Controller Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(CLK_IRQHandler, 2)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTA Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTB Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTC Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTD Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  External Interrupt PORTE Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#ifdef STM8S903
/**
  * @brief  External Interrupt PORTF Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(EXTI_PORTF_IRQHandler, 8)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S903*/

#if defined (STM8S208) || defined (STM8AF52Ax)
/**
  * @brief CAN RX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_RX_IRQHandler, 8)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  CAN TX Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_TX_IRQHandler, 9)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208 || STM8AF52Ax */

/**
  * @brief  SPI Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(SPI_IRQHandler, 10)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer1 Update/Overflow/Trigger/Break Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
 */
      GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
      TIM1_ClearITPendingBit(TIM1_IT_UPDATE); // clear flag update interrup(TIM1_SR1)
}

/**
  * @brief  Timer1 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#ifdef STM8S903
/**
  * @brief  Timer5 Update/Overflow/Break/Trigger Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_UPD_OVF_BRK_TRG_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief  Timer5 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_CAP_COM_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */
/**
  * @brief  Timer2 Update/Overflow/Break Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer2 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S903*/

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S105) || \
    defined(STM8S005) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8AF626x)
/**
  * @brief Timer3 Update/Overflow/Break Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_UPD_OVF_BRK_IRQHandler, 15)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief  Timer3 Capture/Compare Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_CAP_COM_IRQHandler, 16)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208, STM8S207 or STM8S105 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S103) || \
    defined(STM8S003) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8S903)
/**
  * @brief  UART1 TX Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART1_TX_IRQHandler, 17)
{
  if (UART1_GetITStatus(UART1_IT_RXNE))
  {
    receive_data=UART1_ReceiveData8();
    if (receive_data != 'F')
    {
      buffer_data = 2;
    }
  }
}

/**
  * @brief  UART1 RX Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
{
  if (UART1_GetITStatus(UART1_IT_RXNE))
  {
    receive_data=UART1_ReceiveData8();

    switch (receive_data)
    {
      case 'F':
          if (stt !=1 )
          {
            WS2812B_reset();
            stt = 1;
          }
          Dir_Forward();
          break;
       case 'B':
          if (stt !=2)
          {
            WS2812B_reset();
            stt = 2;
          }
          Dir_Back ();
          break;
       case 'R':
          if (stt != 3)
          {
            WS2812B_reset();
            stt =3;
          }
          Dir_Right ();
          break;
       case 'L':
          if (stt != 4)
          {
            WS2812B_reset();
            stt =4;
          }
          Dir_Left ();
          break;
       case 'W':
          if (stt != 5)
          {
            WS2812B_reset();
            stt =5;
          }
          into_inout (IN, 3);
          break;
        case 'w':
          if (stt != 6)
          {
            WS2812B_reset();
            stt =6;
          }
          into_inout (OUT, 3);
          break;
        case 'X':
          if (stt != 7)
          {
            WS2812B_reset();
            stt =7;
          }
          into_inout_keep (IN, 3);
          break;
        case 'x':
          if (stt != 8)
          {
            WS2812B_reset();
            stt =8;
          }
          into_inout_keep (OUT, 3);
          break;
        case 'U':
          if (stt != 9)
          {
            WS2812B_reset();
            stt =9;
          }
          one_led_keep_inout (IN, 3);
          break;
        case 'u':
          if (stt != 10)
          {
            WS2812B_reset();
            stt =10;
          }
          one_led_keep_inout (OUT, 3);
          break;
        case 'V':
          if (stt != 11)
          {
            WS2812B_reset();
            stt =11;
          }
          fireball(IN,3);
          break;
        case 'v':
          if (stt != 12)
          {
            WS2812B_reset();
            stt =12;
          }
          fireball(OUT,1);
          break;
       case '0':
         light_red = 10;
         light_blue = 0;
         light_green = 0;
         break;
       case '1':
         light_red = 0;
         light_blue = 10;
         light_green = 0;
         break;
       case '2':
         light_red = 10;
         light_blue = 10;
         light_green = 00;
         break;
       case '4':
         light_red = 10;
         light_blue = 00;
         light_green = 10;
         break;
       case '5':
         light_red = 0;
         light_blue = 10;
         light_green = 10;
         break;
       case '6':
         light_red = 10;
         light_blue = 10;
         light_green = 10;
         break;
       case '7':
         light_red = 5;
         light_blue = 5;
         light_green = 5;
         break;
       case '8':
         light_red = 2;
         light_blue = 21;
         light_green = 42;
         break;
       case '9':
         light_red = 2;
         light_blue = 82;
         light_green = 22;
         break;
       case 'q':
         light_red = 22;
         light_blue = 4;
         light_green = 29;
         break;
       case 'S':
          stt =0;
          break;
       default:
          stt = 0;
          break;
    }

    UART1_SendData8(receive_data);

  }


}
#endif /*STM8S105*/

/**
  * @brief  I2C Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(I2C_IRQHandler, 19)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#if defined(STM8S105) || defined(STM8S005) ||  defined (STM8AF626x)
/**
  * @brief  UART2 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_TX_IRQHandler, 20)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }

/**
  * @brief  UART2 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_RX_IRQHandler, 21)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }
#endif /* STM8S105*/

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief  UART3 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_TX_IRQHandler, 20)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }

/**
  * @brief  UART3 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_RX_IRQHandler, 21)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  }
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief  ADC2 interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(ADC2_IRQHandler, 22)
{

    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
    return;

}
#else /*STM8S105, STM8S103 or STM8S903 or STM8AF626x */
/**
  * @brief  ADC1 interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(ADC1_IRQHandler, 22)
{

    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
    return;

}
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#ifdef STM8S903
/**
  * @brief  Timer6 Update/Overflow/Trigger Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM6_UPD_OVF_TRG_IRQHandler, 23)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */
/**
  * @brief  Timer4 Update/Overflow Interrupt routine
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S903*/

/**
  * @brief  Eeprom EEC Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
