

#include "stm32f10x.h"
#include "led.h"

#include "relay.h"
#include  "keyscan.h"

void Delay(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

typedef enum{
	STATE_IDLE,
	STATE_PRESSED,
	STATE_RELEASE,
}key_state;
int triggle_flag = 0;
key_state state = STATE_IDLE;
key_state state_pre = STATE_IDLE;
/**************************************
 * Entrance main
 *************************************/
int main(void)
{
    /* 配置系统时钟为72M */
    SystemInit();

	
	  relay_module_init();
	  LED_GPIO_Config();	
    keyscan_module_init();

	  while(1)
		{
#if 1			  
			  if (keyscan_check()) 
				{
					   state = STATE_PRESSED;
				}
				else
				{
					   state = STATE_RELEASE;
				}
				
				if ((state_pre == STATE_RELEASE) && (state == STATE_PRESSED))
				{						 
					   triggle_flag ^= 0x01;
				}
				
				
				if (triggle_flag)
				{
					  LED1(ON);
					  RELAY_ACTION(1);
				}
			  else
				{
			      LED1(OFF);
					  RELAY_ACTION(0);
				}
				
				state_pre = state;
#endif
		};


}


/******************* (C) COPYRIGHT 2011 野火嵌入式开发工作室 *****END OF FILE****/
