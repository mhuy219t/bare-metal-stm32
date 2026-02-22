#include <stdint.h>

#define LED_PIN 13

/*Base addresses */
#define PERIPHERAL_BASE     (0x40000000U)
#define APB2_BASE           (PERIPHERAL_BASE + 0x10000U)
#define AHB_BASE            (PERIPHERAL_BASE + 0x20000U)

/* RCC */
#define RCC_AHB_BASE        (AHB_BASE + 0x1000U)
#define RCC_APB2ENR_OFFSET  (0x18U)
#define RCC_APB2ENR         ((volatile uint32_t*)(RCC_AHB_BASE + RCC_APB2ENR_OFFSET))

/* GPIO */
#define GPIOC_BASE          (APB2_BASE + 0x1000U)
#define GPIOC_CRH_OFFSET    (0x04U)
#define GPIOC_CRH           ((volatile uint32_t*)(GPIOC_BASE + GPIOC_CRH_OFFSET))
#define GPIOC_ODR_OFFSET    (0x0CU)
#define GPIOC_ODR           ((volatile uint32_t*)(GPIOC_BASE + GPIOC_ODR_OFFSET))

/* OTHERS */
#define RCC_IOPC_BIT_POSITION (4U)


int main(void)
{
    /* Enable GPIOC clock by setting the appropriate bit in RCC_APB2ENR */
    *RCC_APB2ENR |= (1 << RCC_IOPC_BIT_POSITION);

    /* Configure GPIOC pin 13 as output */
    *GPIOC_CRH &= ~(0xFU << 20U);   // Clear the configuration bits for pin 13
    *GPIOC_CRH |= (0x2U << 20U);    // Set pin 13 as output with MODE = 0b10, CNF = 0b00

    while (1)
    {
        *GPIOC_ODR &= ~(1U << LED_PIN); // Turn on the LED (active low)
        for (volatile int i = 0; i < 100000; i++);
        *GPIOC_ODR |= (1U << LED_PIN); // Turn off the LED (active low)
        for (volatile int i = 0; i < 100000; i++);
    }
}