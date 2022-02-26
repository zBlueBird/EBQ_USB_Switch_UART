/**
*  keyscan module
*  ROW0  PC6
*  ROW1  PC7
*  ROW2  PC8
*  ROW   PC9
*  COLUMN   PB12
*  COLUMN   PB13
*  COLUMN   PB14
*  COLUMN   PB15
*
*    Step1. keyscan �ж�
*    Step2. ���жϣ�������ʱ������ʱ����
*    Step3. ������ʱ����ʱ���ٴμ�ⰴ����
*    Step4. �ٴμ�ⰴ���а������µĻ�������������ɨ�����̣������ֵ��
*
**/


#include "keyscan.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "misc.h"


/*=================================================================
*               Local Variables
==================================================================*/
/*=================================================================
*               Local Function
==================================================================*/
void keyscan_row_gpio_Config(void);

Key_ValueTypeDef key_scan(void);

void keyscan_module_init(void)
{
    keyscan_row_gpio_Config();
}

void key_debounce(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

int keyscan_check(void)
{
    /*2. check all row status*/
    if (Bit_SET == GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3))     
    {		
				key_debounce(6000);
				if(Bit_SET == GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3))
				{
						return 1;
				}
	  }
		
		return 0;
}


void keyscan_row_gpio_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* config the extiline clock and AFIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

    /* EXTI line gpio config(PC6~PC9) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  // ��������
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    //keyscan_interrupt_config(TRUE);
	  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
}




