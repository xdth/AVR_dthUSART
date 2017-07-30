
/*
* dthUSART C library for AVR microcontrollers (beta)
* dthlabs.com - July 30, 2017
*/


/*
* Defines
*/
#ifndef F_CPU
#define F_CPU	1000000UL // CPU frequency is 1 Mhz
#endif

#ifndef BAUD
#define BAUD	0x0C // or 12, for 9600.00 bit rate at 1.000 MHz, U2Xn = 1 (asynchronous), error 0.2%
#endif

#ifndef USE_2X
#define USE_2X  1
#endif


/*
* Functions prototypes
*/
// USART_init
void USART_init(void);

// byte_transmit
void byte_transmit(unsigned char);

// byte_receive
unsigned char byte_receive(void);

// string_print
void string_print(const char myString[]);

// string_read
void string_read(char myString[], uint8_t maxLength);
