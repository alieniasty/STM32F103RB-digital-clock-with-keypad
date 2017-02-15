#ifndef MAIN_H_
#define MAIN_H_

#define ROW_1_PA                ((uint16_t)0x1000)
#define ROW_2_PA                ((uint16_t)0x0800)
#define ROW_3_PB                ((uint16_t)0x1000)
#define ROW_4_PB                ((uint16_t)0x0800)

#define COLUMN_1_PB             ((uint16_t)0x8000)
#define COLUMN_2_PB             ((uint16_t)0x4000)
#define COLUMN_3_PB             ((uint16_t)0x2000)

#define PIN_1					((uint16_t)0x0400)
#define PIN_2					((uint16_t)0x0200)
#define PIN_3					((uint16_t)0x0020)
#define PIN_4					((uint16_t)0x0100)

#define PIN_a					((uint16_t)0x0020)
#define PIN_b					((uint16_t)0x0040)
#define PIN_c					((uint16_t)0x0080)
#define PIN_d					((uint16_t)0x0040)
#define PIN_e					((uint16_t)0x0080)
#define PIN_f					((uint16_t)0x0200)
#define PIN_g					((uint16_t)0x0100)
#define PIN_dp					((uint16_t)0x0400)

#define RECEIVE_BUFFER_LEN 		128
#define SEND_BUFFER_LEN 		256
#define TIME_BUFFER_LEN			4
#define SECONDS_BUFFER_LEN 		2
#define MIN_BUTTON_PRESSED		150

char receiveBuffer[RECEIVE_BUFFER_LEN];
short receiveBufferTail;
short receiveBufferCount;

char sendBuffer[SEND_BUFFER_LEN];
short sendBufferTail;
short sendBufferCount;

short cmdStart;
short cmdEnd;
short cmdRange;

char timeBuffer[TIME_BUFFER_LEN];
char secondsBuffer[SECONDS_BUFFER_LEN];
short timeBufferTail;

short allowSet;
short timeIsCorrect;
short allTimeHasBeenSet;

int TenMiliSeconds;

char transmitChar;

short buttonsBuffer[3][4];
short clockStarted;

#endif /* MAIN_H_ */
