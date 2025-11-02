//  1: Define base address for peripherals
#define PERIPH_BASE (0x40000000UL)
//  2: Offset for AHB1 peripheral bus
#define AHB1PERIPH_OFFSET (0x00020000UL)
//  3: Base address for AHB1 peripherals
#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)
//  4: Offset for GPIOD
#define GPIOD_OFFSET (0x00000C00UL)
//  5: Base address for GPIOD
#define GPIOD_BASE (AHB1PERIPH_BASE + GPIOD_OFFSET)
//  6: Offset for RCC
#define RCC_OFFSET (0x3800UL)
//  7: Base address for RCC
#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET)
//  8: Offset for AHB1EN register
#define AHB1EN_R_OFFSET (0x30UL)
//  9: Address of AHB1EN register
#define RCC_AHB1EN_R (*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))
//  10: Offset for mode register
#define MODE_R_OFFSET (0x00UL)
//  11: Address of GPIOD mode register
#define GPIOD_MODE_R (*(volatile unsigned int*)(GPIOD_BASE + MODE_R_OFFSET))
//  12: Offset for output data register
#define OD_R_OFFSET (0x14UL)
//  13: Address of GPIOD output data register
#define GPIOD_OD_R (*(volatile unsigned int*)(GPIOD_BASE + OD_R_OFFSET))
//  14: Bit mask for enabling GPIOD (bit 3)
#define GPIODEN (1U << 3)
//  15: Bit mask for GPIOD pin 13
#define PIN13 (1U << 13)
//  16: Alias for PIN13 representing LED pin
#define LED_PIN PIN13

//  17: Start of main function
int main(void) {
  //  18: Enable clock access to GPIOD
  RCC_AHB1EN_R |= GPIODEN;

  GPIOD_MODE_R |= (1U << 26);   //  19: Set bit 10 to 1
  GPIOD_MODE_R &= ~(1U << 27);  //  20: Set bit 11 to 0

  //  21: Start of infinite loop
  while (1) {
    //  22: Toggle PA5(LED_PIN)
    GPIOD_OD_R ^= LED_PIN;
    for (int i = 0; i < 1000000; i++) {
    }

  }  //  23: End of infinite loop

}  //  24: End of main function