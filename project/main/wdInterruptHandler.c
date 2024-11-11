#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT() {
  static char blink_count = 0;

  if (++blink_count == 25) { // Faster blinking interval
    switch_state_advance();  // Execute current state logic
    blink_count = 0;
  }
}
