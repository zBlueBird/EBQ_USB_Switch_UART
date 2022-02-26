
#include "led.h"
#include "stm32f10x_pwr.h"
#include "stm32f10x_gpio.h"

/*
 * 函数名：LED_GPIO_Config
 * 描述  ：配置LED用到的I/O口
 * 输入  ：无
 * 输出  ：无
 */
void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_ResetBits(GPIOC, GPIO_Pin_13 );   // turn off all led
	
		  //PWR_BackupAccessCmd(ENABLE);//????RTC ??????
    //RCC_LSEConfig(RCC_LSE_OFF);
	 //PWR_BackupAccessCmd(DISABLE);//????RTC ??????
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	  

}


/******************* (C) COPYRIGHT 2011 野火嵌入式开发工作室 *****END OF FILE****/
