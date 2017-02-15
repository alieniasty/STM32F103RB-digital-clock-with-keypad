#include "stm32f1xx_it.h"
#include "stm32f10x_usart.h"
#include <main.h>

uint16_t DisplayPin[4] = {((uint16_t)0x0400), ((uint16_t)0x0200), ((uint16_t)0x0020), ((uint16_t)0x0100)};
uint8_t displayingSeconds = 0;

void USART2_IRQHandler()
{
	if(USART_GetFlagStatus(USART2, USART_IT_TXE) == RESET)
	{
		if(sendBufferCount != sendBufferTail)
		{
			USART_SendData(USART2, sendBuffer[sendBufferCount++]);
		}
		else
		{
			sendBufferCount = 0;
			USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
		}
	}

	if (USART_GetFlagStatus(USART2, USART_FLAG_RXNE))
	{
		receiveBuffer[receiveBufferTail++] = USART_ReceiveData(USART2);

		if(receiveBufferTail == RECEIVE_BUFFER_LEN)
		{
			receiveBufferTail = 0;
		}

	}
}

void resetSegments()
{
	GPIO_ResetBits(GPIOA, PIN_a);
	GPIO_ResetBits(GPIOA, PIN_b);
	GPIO_ResetBits(GPIOA, PIN_c);
	GPIO_ResetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_ResetBits(GPIOA, PIN_f);
	GPIO_ResetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);
}

void Display0(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_SetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_ResetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display1(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_ResetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_ResetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_ResetBits(GPIOA, PIN_f);
	GPIO_ResetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}
void Display2(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_ResetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_SetBits(GPIOC, PIN_e);
	GPIO_ResetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display3(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_ResetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display4(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_ResetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_ResetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display5(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_ResetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display6(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_ResetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_SetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display7(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_ResetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_ResetBits(GPIOA, PIN_f);
	GPIO_ResetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display8(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_SetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void Display9(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}


void DisplayE(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_ResetBits(GPIOA, PIN_b);
	GPIO_ResetBits(GPIOA, PIN_c);
	GPIO_SetBits(GPIOB, PIN_d);
	GPIO_SetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}


void DisplayR(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_SetBits(GPIOA, PIN_a);
	GPIO_SetBits(GPIOA, PIN_b);
	GPIO_SetBits(GPIOA, PIN_c);
	GPIO_ResetBits(GPIOB, PIN_d);
	GPIO_SetBits(GPIOC, PIN_e);
	GPIO_SetBits(GPIOA, PIN_f);
	GPIO_SetBits(GPIOA, PIN_g);
	GPIO_ResetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);

	resetSegments();
}

void DisplayDot(GPIO_TypeDef* gpio, uint16_t pin)
{
	GPIO_SetBits(gpio, pin);

	GPIO_ResetBits(GPIOA, PIN_a);
	GPIO_ResetBits(GPIOA, PIN_b);
	GPIO_ResetBits(GPIOA, PIN_c);
	GPIO_ResetBits(GPIOB, PIN_d);
	GPIO_ResetBits(GPIOC, PIN_e);
	GPIO_ResetBits(GPIOA, PIN_f);
	GPIO_ResetBits(GPIOA, PIN_g);
	GPIO_SetBits(GPIOB, PIN_dp);

	GPIO_ResetBits(gpio, pin);
}

void DisplayNumber(char number, uint16_t place)
{
	switch (place)
	{
		case ((uint16_t)0x0400):
			switch (number) {
				case '0':
					Display0(GPIOA, place);
					break;
				case '1':
					Display1(GPIOA, place);
					break;
				case '2':
					Display2(GPIOA, place);
					break;
				case '3':
					Display3(GPIOA, place);
					break;
				case '4':
					Display4(GPIOA, place);
					break;
				case '5':
					Display5(GPIOA, place);
					break;
				case '6':
					Display6(GPIOA, place);
					break;
				case '7':
					Display7(GPIOA, place);
					break;
				case '8':
					Display8(GPIOA, place);
					break;
				case '9':
					Display9(GPIOA, place);
					break;
				default:
					DisplayDot(GPIOA, place);
					break;
			}
			break;
			case ((uint16_t)0x0200):
				switch (number) {
					case '0':
						DisplayDot(GPIOB, place);
						Display0(GPIOB, place);
						break;
					case '1':
						DisplayDot(GPIOB, place);
						Display1(GPIOB, place);
						break;
					case '2':
						DisplayDot(GPIOB, place);
						Display2(GPIOB, place);
						break;
					case '3':
						DisplayDot(GPIOB, place);
						Display3(GPIOB, place);
						break;
					case '4':
						DisplayDot(GPIOB, place);
						Display4(GPIOB, place);
						break;
					case '5':
						DisplayDot(GPIOB, place);
						Display5(GPIOB, place);
						break;
					case '6':
						DisplayDot(GPIOB, place);
						Display6(GPIOB, place);
						break;
					case '7':
						DisplayDot(GPIOB, place);
						Display7(GPIOB, place);
						break;
					case '8':
						DisplayDot(GPIOB, place);
						Display8(GPIOB, place);
						break;
					case '9':
						DisplayDot(GPIOB, place);
						Display9(GPIOB, place);
						break;
					default:
						DisplayDot(GPIOB, place);
						break;
				}
			break;
			case ((uint16_t)0x0020):
				switch (number) {
					case '0':
						Display0(GPIOB, place);
						break;
					case '1':
						Display1(GPIOB, place);
						break;
					case '2':
						Display2(GPIOB, place);
						break;
					case '3':
						Display3(GPIOB, place);
						break;
					case '4':
						Display4(GPIOB, place);
						break;
					case '5':
						Display5(GPIOB, place);
						break;
					case '6':
						Display6(GPIOB, place);
						break;
					case '7':
						Display7(GPIOB, place);
						break;
					case '8':
						Display8(GPIOB, place);
						break;
					case '9':
						Display9(GPIOB, place);
						break;
					default:
						DisplayDot(GPIOB, place);
						break;
				}
			break;
			case ((uint16_t)0x0100):
				switch (number) {
					case '0':
						Display0(GPIOB, place);
						break;
					case '1':
						Display1(GPIOB, place);
						break;
					case '2':
						Display2(GPIOB, place);
						break;
					case '3':
						Display3(GPIOB, place);
						break;
					case '4':
						Display4(GPIOB, place);
						break;
					case '5':
						Display5(GPIOB, place);
						break;
					case '6':
						Display6(GPIOB, place);
						break;
					case '7':
						Display7(GPIOB, place);
						break;
					case '8':
						Display8(GPIOB, place);
						break;
					case '9':
						Display9(GPIOB, place);
						break;
					default:
						DisplayDot(GPIOB, place);
						break;
				}
			break;
		default:
			break;
	}
}

void SysTick_Handler()
{
	if (timeIsCorrect == 1 && allTimeHasBeenSet == 1 && clockStarted == 1)
	{
		uint8_t i;
		TenMiliSeconds++;

		if (TenMiliSeconds % 50000 == 0)
		{
			displayingSeconds = !displayingSeconds;
		}

		if (displayingSeconds == 0)
		{
			for (i = 0; i < 4; i++)
			{
				DisplayNumber(timeBuffer[i], DisplayPin[i]);
			}
		}
		else if (displayingSeconds == 1 && clockStarted == 1)
		{
			sprintf(secondsBuffer, "%d", TenMiliSeconds/10000);

			if (TenMiliSeconds > 100000)
			{
				for (i = 0; i < 2; i++)
				{
					DisplayNumber(secondsBuffer[i], DisplayPin[2+i]);
				}
			}
			else
			{
				DisplayNumber(secondsBuffer[0], DisplayPin[3]);
			}

		}

		if (TenMiliSeconds == 600000)
		{
			if (timeBuffer[3] == 57 && timeBuffer[2] != 53)
			{
				timeBuffer[3] = 48;
				timeBuffer[2]++;
			}
		    else if (timeBuffer[3] < 57 && timeBuffer[2] < 53)
			{
				timeBuffer[3]++;
			}
			else if (timeBuffer[1] == 57 && timeBuffer[0] == 49)
			{
				timeBuffer[0] = 50;
				timeBuffer[1] = 48;
				timeBuffer[2] = 48;
				timeBuffer[3] = 48;
			}
			else if (timeBuffer[1] == 51 && timeBuffer[0] == 50)
			{
				uint8_t i;
				for (i = 0; i < 4; i++)
				{
					timeBuffer[i] = '0';
				}
			}

			memset(secondsBuffer, 0, 2);
			TenMiliSeconds = 0;
		}
	}
	else if (timeIsCorrect == 0 && allTimeHasBeenSet == 1)
	{
		DisplayE(GPIOA, ((uint16_t)0x0400));
		DisplayR(GPIOB, ((uint16_t)0x0200));
		DisplayR(GPIOB, ((uint16_t)0x0020));
	}
}


void TIM1_UP_IRQHandler()
{
    if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM1, TIM_IT_Update);

		//---------------Check first column---------------

		GPIO_ResetBits(GPIOB, COLUMN_1_PB);

		if (GPIO_ReadInputDataBit(GPIOA, ROW_1_PA) == 0 && buttonsBuffer[0][0] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[0][0]++;
			transmitChar = '1';
		}else if(GPIO_ReadInputDataBit(GPIOA, ROW_1_PA) == 1){
			buttonsBuffer[0][0] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOA, ROW_2_PA) == 0 && buttonsBuffer[0][1] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[0][1]++;
			transmitChar = '4';
		}else if(GPIO_ReadInputDataBit(GPIOA, ROW_2_PA) == 1){
			buttonsBuffer[0][1] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOB, ROW_3_PB) == 0 && buttonsBuffer[0][2] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[0][2]++;
			transmitChar = '7';
		}else if(GPIO_ReadInputDataBit(GPIOB, ROW_3_PB) == 1){
			buttonsBuffer[0][2] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOB, ROW_4_PB) == 0 && buttonsBuffer[0][3] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[0][3]++;
			transmitChar = '*';
		}else if(GPIO_ReadInputDataBit(GPIOB, ROW_4_PB) == 1){
			buttonsBuffer[0][3] = 0;
		}

		GPIO_SetBits(GPIOB, COLUMN_1_PB);

		//---------------Check second column---------------

		GPIO_ResetBits(GPIOB, COLUMN_2_PB);

		if (GPIO_ReadInputDataBit(GPIOA, ROW_1_PA) == 0 && buttonsBuffer[1][0] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[1][0]++;
			transmitChar = '2';
		}else if(GPIO_ReadInputDataBit(GPIOA, ROW_1_PA) == 1){
			buttonsBuffer[1][0] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOA, ROW_2_PA) == 0 && buttonsBuffer[1][1] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[1][1]++;
			transmitChar = '5';
		}else if(GPIO_ReadInputDataBit(GPIOA, ROW_2_PA) == 1){
			buttonsBuffer[1][1] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOB, ROW_3_PB) == 0 && buttonsBuffer[1][2] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[1][2]++;
			transmitChar = '8';
		}else if(GPIO_ReadInputDataBit(GPIOB, ROW_3_PB) == 1){
			buttonsBuffer[1][2] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOB, ROW_4_PB) == 0 && buttonsBuffer[1][3] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[1][3]++;
			transmitChar = '0';
		}else if(GPIO_ReadInputDataBit(GPIOB, ROW_4_PB) == 1){
			buttonsBuffer[1][3] = 0;
		}

		GPIO_SetBits(GPIOB, COLUMN_2_PB);

		//---------------Check third column---------------

		GPIO_ResetBits(GPIOB, COLUMN_3_PB);

		if (GPIO_ReadInputDataBit(GPIOA, ROW_1_PA) == 0 && buttonsBuffer[2][0] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[2][0]++;
			transmitChar = '3';
		}else if(GPIO_ReadInputDataBit(GPIOA, ROW_1_PA) == 1){
			buttonsBuffer[2][0] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOA, ROW_2_PA) == 0 && buttonsBuffer[2][1] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[2][1]++;
			transmitChar = '6';
		}else if(GPIO_ReadInputDataBit(GPIOA, ROW_2_PA) == 1){
			buttonsBuffer[2][1] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOB, ROW_3_PB) == 0 && buttonsBuffer[2][2] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[2][2]++;
			transmitChar = '9';
		}else if(GPIO_ReadInputDataBit(GPIOB, ROW_3_PB) == 1){
			buttonsBuffer[2][2] = 0;
		}

		if (GPIO_ReadInputDataBit(GPIOB, ROW_4_PB) == 0 && buttonsBuffer[2][3] < MIN_BUTTON_PRESSED)
		{
			buttonsBuffer[2][3]++;
			transmitChar = '#';
		}else if(GPIO_ReadInputDataBit(GPIOB, ROW_4_PB) == 1){
			buttonsBuffer[2][3] = 0;
		}

		GPIO_SetBits(GPIOB, COLUMN_3_PB);
	}
}





