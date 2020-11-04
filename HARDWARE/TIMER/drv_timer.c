/**
  ******************************************************************************
  * @file    drv_time.c
  * @author  xjc
  * @version v1.0
  * @date    20-09-17
  * @brief   �жϺ�����it��
							TIM2_Init()
  ******************************************************************************
  */
#include "drv_timer.h"

void TIM2_Init(uint16_t arr, uint16_t psc)   //1ms 8399,9
{
	//arr�Զ���װ��ֵ
	//pscԤ��Ƶֵ
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef         NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //��ʱ��2ʱ��ʹ��

	/*��ʱ��2��ʼ��*/
	TIM_TimeBaseStructure.TIM_Period = arr;              //��������ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = psc;           //���÷�Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //���÷�Ƶ����
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //��������ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);             //���ṹ�������ڳ�ʼ����ʱ��2

	TIM_ITConfig(TIM2, TIM_IT_Update,ENABLE );           //ʹ�ܶ�ʱ��2�����ж�

	/*�����жϲ���*/
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;            //��ʱ��2�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIMER2_PreemptionPriority;  //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIMER2_SubPriority;         //��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //ʹ���ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);                            //��ʼ���ж�
	TIM_Cmd(TIM2, ENABLE);  //ʹ�ܶ�ʱ��

}

void TIM3_Init(uint16_t arr, uint16_t psc)   //1ms 8399,9
{
	//arr�Զ���װ��ֵ
	//pscԤ��Ƶֵ
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef         NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //��ʱ��2ʱ��ʹ��

	/*��ʱ��2��ʼ��*/
	TIM_TimeBaseStructure.TIM_Period = arr;              //��������ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = psc;           //���÷�Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //���÷�Ƶ����
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //��������ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);             //���ṹ�������ڳ�ʼ����ʱ��2

	TIM_ITConfig(TIM3, TIM_IT_Update,ENABLE );           //ʹ�ܶ�ʱ��2�����ж�

	/*�����жϲ���*/
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;            //��ʱ��2�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIMER3_PreemptionPriority;  //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIMER3_SubPriority;         //��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //ʹ���ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);                            //��ʼ���ж�
	TIM_Cmd(TIM3, ENABLE);  //ʹ�ܶ�ʱ��

}

