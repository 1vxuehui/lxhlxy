#ifndef __duoji_H_
#define __duoji_H_

/*
TIM2CH1 Ô²ÅÌ
TIM2CH3 4ºÅ
TIM4CH1 1ºÅ
TIM4CH2 2ºÅ
TIM4CH3 3ºÅ
TIM4CH4 5ºÅ
TIM2CH2 Ì§Éý
TIM10CH1  PB8 ºóÓÒ
TIM5CH1  PA0 ºó×ó


*/

//void DISC_Rotate_Anticlockwise(int time);			//500
//void DISC_Rotate_Clockwise(int time);		//900
void MG_RISE();
void MG_DOWN();
void DISC_Rotate(int pwm_t);
void MG90S_Rotate_down1(void);
void MG90S_Rotate_up1(void);

void MG90S_Rotate_down2(void);
void MG90S_Rotate_up2(void);
     
void MG90S_Rotate_down3(void);		//ÈýºÅ¶æ»ú£»
void MG90S_Rotate_up3(void);
     
void MG90S_Rotate_down4(void);    //ËÄºÅ
void MG90S_Rotate_up4(void);
     
void MG90S_Rotate_down5(void);
void MG90S_Rotate_up5(void);

void MG90S_Rotate_OPEN7(void);
void MG90S_Rotate_CLOSE7(void);

void MG90S_Rotate_OPEN6(void);
void MG90S_Rotate_CLOSE6(void);

#endif
