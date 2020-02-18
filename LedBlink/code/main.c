#define __AVR_ATmega32U4__
#define F_CPU 8000000
// Includes --------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
// Private Typedef -------------------------------------------------------------

// Private Macro ---------------------------------------------------------------
#define LED_PORT PORTC
#define LED_PIN  PIN7
// Private Variables -----------------------------------------------------------

// Private Function prototypes -------------------------------------------------

// Functions -------------------------------------------------------------------
int main(void)
{
  DDRC |= 1 << DDC7;

  while (1)
  {
    _delay_ms(300);
    LED_PORT |= 1 << LED_PIN;
    _delay_ms(1000);
    LED_PORT &= ~(1 << LED_PIN);
  }
}

