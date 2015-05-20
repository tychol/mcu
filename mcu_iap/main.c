/**
  ******************************************************************************
  * @file    Project/main.c 
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
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
#include "stdio.h"
#include "stm8s_uart1.h"

#define MAIN_USER_RESET_ADDR 0x9080ul

//iap
void iap_checking(void);
void iap_init_UART1_lib(void);


int _fctcpy(char);/* Define the prototypes of _fctcpy() function which is not yet defined by COSMIC*/

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



/**
 * at the beginning in main.o ?
 */
void main(void)
{
	u8 i;
	//used for printf
	UART3_Init(
					115200,
					UART3_WORDLENGTH_8D,
					UART3_STOPBITS_1,
					UART3_PARITY_NO,
					UART3_MODE_TXRX_ENABLE);

  //UART3_ClearITPendingBit(UART1_IT_RXNE);
	
	_fctcpy('F');
	
	iap_init_UART1_lib();
	
	printf("AAAA\r\n");
	
	while (1){
		iap_checking();
	}
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