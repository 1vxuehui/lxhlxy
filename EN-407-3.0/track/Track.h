#ifndef __TRACK_H_
#define __TRACK_H_

#include "main.h"
typedef struct {
	uint16_t id;
	GPIO_TypeDef *huidu11;
	uint16_t GPIO_Pin;
}huidu_t;

uint8_t huidu_check(huidu_t* sensor);

void Tracking_Init(void);

extern void Tracking(void);////////////////��ʼѲ��
extern void Tracking1(void);
extern void Tracking2(void);//////////////���˵�����
extern void Tracking3(void);
extern void Tracking4(void);
extern void Tracking5(void);//////////Ѱһ������
extern void Tracking6(void);////////6.7Ϊץ���������;
extern void Tracking7(void);////////
extern void Trackinghou_transmit(void);
extern void Trackinghou(void);
extern void Trackinghou2(void);
extern void Trackinghou3(void);
extern void zuozhuan1(void);
extern void zuozhuan2(void);
extern void zuozhuan3(void);
extern void youzhuan1(void);
extern void youzhuan2(void);
extern void youzhuan3(void);
extern void tuituitui(void);
#endif
