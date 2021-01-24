
// Includes --------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
// Private Typedef -------------------------------------------------------------
typedef struct
{
  volatile uint8_t PORTA;
  volatile uint8_t DDRA;
  volatile uint8_t PINA;
} POTRTA_t;

#define PORTA ((POTRTA_t*)&PORTB)

// Private Macro ---------------------------------------------------------------
#define LED_PORT PORTC
#define LED_PIN  PIN7
// Private Variables -----------------------------------------------------------

char*   str    = "12345";
uint8_t str1[] = "12345";
// Private Function prototypes -------------------------------------------------

// Functions -------------------------------------------------------------------
int main(void)
{
  DDRC |= 1 << DDC7;

  if (PINB & (1 << PIN2))
  {
    PORTB       = str1[5];
    PORTC       = *(str + 2);
    PORTA->DDRA = 5;
    // str1[5] = 'f';
    // str[0] = 'f';
  }

  while (1)
  {
    _delay_ms(3000);
    LED_PORT |= 1 << LED_PIN;
    _delay_ms(1000);
    LED_PORT &= ~(1 << LED_PIN);
  }
}

void Tim0Init()
{
  DDRB |= (1 << DD3);  
}
