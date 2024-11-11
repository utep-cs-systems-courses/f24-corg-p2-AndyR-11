#include <msp430.h>
#include "led.h"
#include "stateMachines.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

void led_init() {
  P1DIR |= LEDS;  // Set LEDs as outputs
  led_changed = 1;
  led_update();
}

void led_update() {
  if (led_changed) {
    char ledFlags = 0;
    ledFlags |= red_on ? LED_RED : 0;
    ledFlags |= green_on ? LED_GREEN : 0;

    P1OUT &= (0xff ^ LEDS) | ledFlags; // Clear unused LEDs
    P1OUT |= ledFlags;                // Set active LEDs
    led_changed = 0;
  }
}
