#include "stm32f10x.h"
#include "main.h"
#include "string.h"

char resetCMD[7] = ".reset;";
char keypadCMD[6] = ".keys;";
char infoCMD[6] = ".info;";
char setCMD[5] = ".set;";
char getTimeCMD[5] = ".get;";

void initGPIO()
{
	GPIO_InitTypeDef gpio;
	USART_InitTypeDef uart;
	TIM_TimeBaseInitTypeDef tim1;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	GPIO_StructInit(&gpio);


	//----------------Buttons---------------------

	//Column 1,2,3
	gpio.GPIO_Pin = COLUMN_1_PB | COLUMN_2_PB | COLUMN_3_PB;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);

	//Row 1, 2
	gpio.GPIO_Pin = ROW_1_PA | ROW_2_PA;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &gpio);

	//Row 3, 4
	gpio.GPIO_Pin = ROW_3_PB | ROW_4_PB;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &gpio);

	tim1.TIM_Prescaler = 720 - 1;
	tim1.TIM_Period = 100 - 1;
	tim1.TIM_ClockDivision = TIM_CKD_DIV1;
	tim1.TIM_RepetitionCounter = 0;
	tim1.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM1, &tim1);

	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM1, ENABLE);


	//----------------Display---------------------

	gpio.GPIO_Pin = PIN_2 | PIN_3 | PIN_d | PIN_dp | PIN_4;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);

	gpio.GPIO_Pin =  PIN_1 | PIN_a | PIN_b | PIN_c | PIN_f | PIN_g;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio);

	gpio.GPIO_Pin = PIN_e;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio);

	//------------------USART---------------------

	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_2;
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &gpio);

	gpio.GPIO_Pin = GPIO_Pin_3;
	gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &gpio);

	USART_StructInit(&uart);
	uart.USART_BaudRate = 115200;
	USART_Init(USART2, &uart);

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);

	//---------------------------------------------

	GPIO_SetBits(GPIOB, COLUMN_1_PB);
	GPIO_SetBits(GPIOB, COLUMN_2_PB);
	GPIO_SetBits(GPIOB, COLUMN_3_PB);

	SysTick_Config(SystemCoreClock / 10000);
}

void NVIC_Configuration()
{
	NVIC_InitTypeDef nvic;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	nvic.NVIC_IRQChannel = USART2_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0;
	nvic.NVIC_IRQChannelSubPriority = 0;
	nvic.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&nvic);

	nvic.NVIC_IRQChannel = TIM1_UP_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 1;
	nvic.NVIC_IRQChannelSubPriority = 1;
	nvic.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&nvic);
}

void sendString(char * string)
{
	int id = sendBufferCount;

	while(*string)
	{
		sendBuffer[id++] = *string++;
	}

	sendBufferTail = id;

	USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
}

void info()
{
	sendString("\r"
				   "Set correct time with keypad or command '.set H1H1m1m2;'\r"
				   "To allow 'set' command type '.set;'\r"
				   "Legend [H1H2:m1m2]\r"
				   "\r"
				   "In case H1 = 0 or 1 -> H2 range is 0-9\r"
				   "In case H1 = 2 -> H2 range is 0-3\r"
				   "\r"
				   "H1 range is 0-2\r"
				   "m1 range is 0-5\r"
				   "m2 range is 0-9\r");
}

void returnTime(char time[])
{
	if (time[0] == NULL)
	{
		sendString("No time has been set\r");
	}
	else
	{
		char timeTable[4];
		int i;
		for (i = 0; i < 4; i++)
		{
			timeTable[i] = time[i];
		}
		sendString(timeTable);
	}
}

void validateInputNumber(char keypadNumber)
{
	if (allowSet == 1)
	{
		if (keypadNumber != 35 && keypadNumber != 42) // 35 - #, 42 - *
			{
				int button = keypadNumber - '0';
				int set = 0;
				timeIsCorrect = 0;

				if (timeBufferTail == 0 && set == 0)
				{
					if (button <= 2)
					{
						timeBuffer[timeBufferTail] = keypadNumber;
						set = 1;
					}
				}

				if (timeBufferTail == 1 && set == 0)
				{
					if (timeBuffer[timeBufferTail-1] == '2')
					{
						if (button <= 3)
						{
							timeBuffer[timeBufferTail] = keypadNumber;
							set = 1;
						}
					}
					else
					{
						timeBuffer[timeBufferTail] = keypadNumber;
						set = 1;
					}
				}

				if (timeBufferTail == 2 && set == 0)
				{
					if (button <= 5)
					{
						timeBuffer[timeBufferTail] = keypadNumber;
						set = 1;
					}
				}

				if (timeBufferTail == 3 && set == 0)
				{
					if (button <= 9)
					{
						timeBuffer[timeBufferTail] = keypadNumber;
						set = 1;
						timeIsCorrect = 1;
						clockStarted = 1;
					}

					allTimeHasBeenSet = 1;
				}

				if (set == 1)
				{
					timeBufferTail++;
				}
				else
				{
					allTimeHasBeenSet = 1;
					timeIsCorrect = 0;
					return;
				}
			}
	}
}

void validateCommand()
{
	char c = receiveBuffer[receiveBufferCount];

	if (c != NULL)
	{
		if (c == '.')
		{
			cmdStart = receiveBufferCount;
		}

		if (c == ';')
		{
			cmdEnd = receiveBufferCount+1;
		}

		if (cmdEnd != 0)
		{
			cmdRange = (cmdEnd - cmdStart) % RECEIVE_BUFFER_LEN;

			char cmd[cmdRange];
			int i;
			int cmdIndex = 0;

			for (i = cmdStart; i  <= cmdEnd; i++)
			{
				cmd[cmdIndex] = receiveBuffer[i];
				cmdIndex++;
			}

			if (strcmp(cmd, keypadCMD) == 0)
			{
				allowSet = 1;
			}

			if (strstr(cmd, ".set ") != NULL)
			{
				allowSet = 1;

				if (allTimeHasBeenSet == 0)
				{
					int i;
					for (i = 5; i < 9; i++)
					{
						char time = cmd[i];
						validateInputNumber(time);
					}
				}
			}

			if (strcmp(cmd, resetCMD) == 0)
			{
				timeBufferTail = 0;
				timeIsCorrect = 1;
				allTimeHasBeenSet = 0;
				clockStarted = 0;
				TenMiliSeconds = 0;
				memset(timeBuffer, 0, TIME_BUFFER_LEN);
			}

			if (strcmp(cmd, infoCMD) == 0)
			{
				info();
			}

			if (strcmp(cmd, getTimeCMD) == 0)
			{
				returnTime(timeBuffer);
			}

			cmdEnd = 0;
			memset(receiveBuffer, 0, RECEIVE_BUFFER_LEN);

		}

		receiveBufferCount++;

		if (receiveBufferCount == 128)
		{
			receiveBufferCount = 0;
		}
	}

}

int main(void)
{
	cmdEnd = 0;
	cmdStart = 0;
	cmdRange = 0;
	receiveBufferTail = 0;
	receiveBufferCount = 0;
	timeBufferTail = 0;
	allowSet = 0;
	timeIsCorrect = 1;
	allTimeHasBeenSet = 0;

	initGPIO();
	NVIC_Configuration();

	info();

	int i,j;

	while (1)
	{
		if (allTimeHasBeenSet == 0)
		{
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (buttonsBuffer[i][j] == MIN_BUTTON_PRESSED)
					{
						validateInputNumber(transmitChar);
						buttonsBuffer[i][j] = 0;
					}
				}
			}
		}

		validateCommand();
	}


}
