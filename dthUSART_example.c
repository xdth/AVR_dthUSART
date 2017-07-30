
/*
* UART echo demo
* Using dthUSART C library for AVR microcontrollers (beta)
* dthlabs.com - July 30, 2017
*/


/*
* CPU frequency
*/
#define F_CPU    1000000UL // CPU frequency is 1 Mhz


/*
* Includes
*/
#include <avr/io.h>
#include <string.h>          // strcmp()
#include <util/delay.h>
#include "dthUSART.h"        // dthUSART C library


/*
* Main
*/
int main(void){

  // Initialize USART
  USART_init();
  _delay_ms(1000); // delay for a second

  // Send hello strings
  string_print("\r\n");
  string_print("+--------------------------------+ \r\n");
  string_print("|        dthlabs.com             +\r\n");
  string_print("+--------------------------------+ \r\n");
  string_print("\r\n");
  string_print("\r\n");
  string_print("\r\n");
  string_print("Type string to be echoed >\r\n");

  // declare buffer
  char data[100];

  // Loop forever
  for(;;) {
    // Read data
    string_read(data,100);

    // Echo data back
    string_print(data);
    string_print("\r\n");
   }

    // the program executed successfully
    return 0;
}
