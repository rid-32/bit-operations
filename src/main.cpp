#include <Arduino.h>

void setHighPin(volatile uint8_t &port, uint8_t pin) {
  if (pin > 7) return;

  port |= (1<<pin);
}

void setLowPin(volatile uint8_t &port, uint8_t pin) {
  if (pin > 7) return;

  port &= ~(1<<pin);
}

void togglePin(volatile uint8_t &port, uint8_t pin) {
  if (pin > 7) return;

  port ^= (1<<pin);
}

void setup() {
  DDRA = 0xFF;
  PORTA = 0b00011100;
}

void loop() {
  if (~PINA & (1<<0)) {
    PORTA |= (1<<0);
  }

  if (~PINA & (1<<1)) {
    PORTA |= (1<<1);
  }
}