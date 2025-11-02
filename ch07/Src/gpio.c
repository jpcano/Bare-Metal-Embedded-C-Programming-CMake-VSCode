#include "gpio.h"

#define GPIOAEN (1U << 0)
#define GPIODEN (1U << 3)

#define LED_BS5 (1U << 13) /*Bit Set Pin 13*/
#define LED_BR5 (1U << 29) /*Bit Reset Pin 13*/
#define BTN_PIN (1U << 0)

void led_init(void) {
  /*Enable clock access to GPIOD*/
  RCC->AHB1ENR |= GPIODEN;

  /*Set PD13 mode to output mode*/
  GPIOD->MODER |= (1U << 26);
  GPIOD->MODER &= ~(1U << 27);
}

void led_on(void) {
  /*Set PD13 high*/
  GPIOD->BSRR |= LED_BS5;
}

void led_off(void) {
  /*Set PD13 high*/
  GPIOD->BSRR |= LED_BR5;
}

void button_init(void) {
  /*Enable clock access to PORTA*/
  RCC->AHB1ENR |= GPIOAEN;

  /*Set PA0 as an input pin*/
  GPIOA->MODER &= ~(1U << 0);
  GPIOA->MODER &= ~(1U << 1);
}

bool get_btn_state(void) {
  /*Note : BTN is active high*/

  /*Check if button is pressed*/
  if (GPIOA->IDR & BTN_PIN) {
    return true;
  } else {
    return false;
  }
}