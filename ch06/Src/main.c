// 1: Include the stm32f4 header file
#include "stm32f4xx.h"

// 2: Bit mask for enabling GPIOD (bit 3)
#define GPIODEN (1U << 3)
// 3: Bit mask for GPIOD pin 13
#define PIN13 (1U << 13)
// 4: Alias for PIN5 representing LED pin
#define LED_PIN PIN13

int main(void) {
  //  5: Enable clock access to GPIOD
  RCC->AHB1ENR |= GPIODEN;

  //  6: Set PA5 to output mode
  GPIOD->MODER |= (1U << 26);
  GPIOD->MODER &= ~(1U << 27);

  while (1) {
    //  7: Set PD13(LED_PIN) high
    GPIOD->ODR ^= LED_PIN;

    // 8: Simple delay
    for (int i = 0; i < 100000; i++) {
    }
  }
}