#include "siren.h"

static int siren_frequency = 1000;  // Initial frequency
static int siren_direction = 1;    // Direction: 1 = increasing, -1 = decreasing

int update_siren_frequency() {
  if (siren_direction == 1) {
    siren_frequency += 50;
    if (siren_frequency >= 2000) {
      siren_direction = -1;  // Reverse direction
    }
  } else {
    siren_frequency -= 50;
    if (siren_frequency <= 500) {
      siren_direction = 1;  // Reverse direction
    }
  }
  return siren_frequency;
}
