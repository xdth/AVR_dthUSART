
/*
* dthUSART C library for AVR microcontrollers (beta)
* dthlabs.com - July 30, 2017
*/


/*
* Includes
*/
#include <avr/io.h>
#include "dthUSART.h"


/*
* USART_init
*/
void USART_init(void) {

  // Set baud rate
  UBRRH = (unsigned char)(BAUD>>8);
  UBRRL = (unsigned char)BAUD;

  // Set U2X
  #if USE_2X
    UCSRA |= (1 << U2X);
  #else
    UCSRA &= ~(1 << U2X);
  #endif
  
  // Enable receiver and transmitter
  UCSRB = (1 << RXEN) | (1 << TXEN);


  // Set frame format
  UCSRC = (1 << UCSZ1) | (1 << UCSZ0); // 8 data bits, 1 stop bit
}


/*
* byte_transmit
*/
void byte_transmit(unsigned char data) {
 // Wait for empty transmit buffer
 while ( !( UCSRA & (1<<UDRE)) );
 // Put data into buffer, sends the data
 UDR = data;
}


/*
* byte_receive
*/
unsigned char byte_receive(void) {
 // Wait for data to be received
 while ( !(UCSRA & (1 << RXC)) );
 // Get and return received data from buffer
 return UDR;
}


/*
* string_print
*/
void string_print(const char myString[]) {
  uint8_t i = 0;
  while (myString[i]) {
    byte_transmit(myString[i]);
    i++;
  }
}


/*
* string_read
*/
void string_read(char myString[], uint8_t maxLength) {
  char response;
  uint8_t i;
  i = 0;
  while (i < (maxLength - 1)) {       // avoid overun
    response = byte_receive();
    byte_transmit(response);
    if (response == '\r') {           // enter for ending
      break;
    }
    else {
      myString[i] = response;         // add char
      i++;
    }
  }
  myString[i] = 0;                    // end with terminal NULL char
}
