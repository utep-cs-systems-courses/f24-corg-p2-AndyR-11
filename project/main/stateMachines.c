#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "siren.h"

// Helper function to create a siren-like effect
void play_siren() {
  static char state = 0;
  if (state) {
    buzzer_set_period(1000);  // High pitch
  } else {
    buzzer_set_period(2000);  // Low pitch
  }
  state = !state;
}

// Siren variables for gradual tone change
static int siren_frequency = 1000;  // Initial frequency
static int siren_direction = 1;    // Direction: 1 = increasing, -1 = decreasing

void switch_state_advance() {
  static char toggle = 0;
  
  switch (switch_state) {
  case 1:
    buzzer_set_period(1300); // Fixed tone
    red_on = 0;
    green_on = toggle;
    led_changed = 1;
    toggle ^= 1;  // Toggle state
    led_update();
    break;
  case 2:
    play_siren(); // Siren effect
    red_on = !toggle;
    green_on = toggle;
    led_changed = 1;
    toggle ^= 1;  // Toggle state
    led_update();
    break;
  case 3:
    buzzer_set_period(update_siren_frequency()); // Use siren module
    red_on = toggle;
    green_on = 0;
    led_changed = 1;
    toggle ^= 1;  // Toggle state
    led_update();
    break;
  case 4:
    buzzer_off();           // No sound
    red_on = 1;             // Both LEDs on
    green_on = 1;
    led_changed = 1;
    led_update();
    break;
  }
}
