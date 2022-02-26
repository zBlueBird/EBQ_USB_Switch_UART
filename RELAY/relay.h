#ifndef _RELAY_H_
#define _RELAY_H_

typedef enum
{
    ENTER_DISABLE,
    ENTER_ENABLE,
} enter_state;


#define RELAY_ACTION(a) if (a)  \
        GPIO_SetBits(GPIOB, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);\
    else        \
        GPIO_ResetBits(GPIOB, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

void relay_module_init(void);

#endif
