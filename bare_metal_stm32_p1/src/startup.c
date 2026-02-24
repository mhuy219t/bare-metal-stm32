#include <stdint.h>

#define SRAM_START_ADDRESS      0x20000000U
#define SRAM_SIZE               (20 * 1024U) // 20 KB
#define SRAM_END_ADDRESS        (SRAM_START_ADDRESS + SRAM_SIZE)
#define STACK_START_ADDRESS     (SRAM_END_ADDRESS)
#define ISR_VECTOR_TABLE_SIZE   (16 + 43)

void reset_handler(void);
void default_handler(void);

/* Cortex-M3 core exceptions */
void nmi_handler(void)              __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void)       __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void)       __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void)        __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void)      __attribute__((weak, alias("default_handler")));
void svcall_handler(void)           __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void)    __attribute__((weak, alias("default_handler")));
void pendsv_handler(void)           __attribute__((weak, alias("default_handler")));
void systick_handler(void)          __attribute__((weak, alias("default_handler")));

/* STM32F103 peripheral interrupts */
void wwdg_handler(void)             __attribute__((weak, alias("default_handler")));
void pvd_handler(void)              __attribute__((weak, alias("default_handler")));
void tamper_handler(void)           __attribute__((weak, alias("default_handler")));
void rtc_handler(void)              __attribute__((weak, alias("default_handler")));
void flash_handler(void)            __attribute__((weak, alias("default_handler")));
void rcc_handler(void)              __attribute__((weak, alias("default_handler")));
void exti0_handler(void)            __attribute__((weak, alias("default_handler")));
void exti1_handler(void)            __attribute__((weak, alias("default_handler")));
void exti2_handler(void)            __attribute__((weak, alias("default_handler")));
void exti3_handler(void)            __attribute__((weak, alias("default_handler")));
void exti4_handler(void)            __attribute__((weak, alias("default_handler")));
void dma1_channel1_handler(void)    __attribute__((weak, alias("default_handler")));
void dma1_channel2_handler(void)    __attribute__((weak, alias("default_handler")));
void dma1_channel3_handler(void)    __attribute__((weak, alias("default_handler")));
void dma1_channel4_handler(void)    __attribute__((weak, alias("default_handler")));
void dma1_channel5_handler(void)    __attribute__((weak, alias("default_handler")));
void dma1_channel6_handler(void)    __attribute__((weak, alias("default_handler")));
void dma1_channel7_handler(void)    __attribute__((weak, alias("default_handler")));
void adc1_2_handler(void)           __attribute__((weak, alias("default_handler")));
void usb_hp_can_tx_handler(void)    __attribute__((weak, alias("default_handler")));
void usb_lp_can_rx0_handler(void)   __attribute__((weak, alias("default_handler")));
void can_rx1_handler(void)          __attribute__((weak, alias("default_handler")));
void can_sce_handler(void)          __attribute__((weak, alias("default_handler")));
void exti9_5_handler(void)          __attribute__((weak, alias("default_handler")));
void tim1_brk_handler(void)         __attribute__((weak, alias("default_handler")));
void tim1_up_handler(void)          __attribute__((weak, alias("default_handler")));
void tim1_trg_com_handler(void)     __attribute__((weak, alias("default_handler")));
void tim1_cc_handler(void)          __attribute__((weak, alias("default_handler")));
void tim2_handler(void)             __attribute__((weak, alias("default_handler")));
void tim3_handler(void)             __attribute__((weak, alias("default_handler")));
void tim4_handler(void)             __attribute__((weak, alias("default_handler")));
void i2c1_ev_handler(void)          __attribute__((weak, alias("default_handler")));
void i2c1_er_handler(void)          __attribute__((weak, alias("default_handler")));
void i2c2_ev_handler(void)          __attribute__((weak, alias("default_handler")));
void i2c2_er_handler(void)          __attribute__((weak, alias("default_handler")));
void spi1_handler(void)             __attribute__((weak, alias("default_handler")));
void spi2_handler(void)             __attribute__((weak, alias("default_handler")));
void usart1_handler(void)           __attribute__((weak, alias("default_handler")));
void usart2_handler(void)           __attribute__((weak, alias("default_handler")));
void usart3_handler(void)           __attribute__((weak, alias("default_handler")));
void exti15_10_handler(void)        __attribute__((weak, alias("default_handler")));
void rtc_alarm_handler(void)        __attribute__((weak, alias("default_handler")));
void usb_wakeup_handler(void)       __attribute__((weak, alias("default_handler")));

/* ISR Vector Table */
uint32_t isr_vector[ISR_VECTOR_TABLE_SIZE] __attribute__((section(".isr_vector"))) = {
    /* Refer Table 61. Vector table for connectivity line devices in RM0008 */
    STACK_START_ADDRESS,            // Initial Stack Pointer
    (uint32_t)&reset_handler,        // Reset Handler
    (uint32_t)&nmi_handler,          // NMI Handler
    (uint32_t)&hard_fault_handler,   // Hard Fault Handler
    (uint32_t)&mem_manage_handler,   // MPU Fault Handler
    (uint32_t)&bus_fault_handler,    // Bus Fault Handler
    (uint32_t)&usage_fault_handler,  // Usage Fault Handler
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    (uint32_t)&svcall_handler,       // SVCall Handler
    (uint32_t)&debug_monitor_handler, // Debug Monitor Handler
    0,                              // Reserved
    (uint32_t)&pendsv_handler,       // PendSV Handler
    (uint32_t)systick_handler,      // SysTick Handler
    /* External IRQs (the rest auto-fill weak handlers) */
    (uint32_t)&wwdg_handler,
    (uint32_t)&pvd_handler,
    (uint32_t)&tamper_handler,
    (uint32_t)&rtc_handler,
    (uint32_t)&flash_handler,
    (uint32_t)&rcc_handler,
    (uint32_t)&exti0_handler,
    (uint32_t)&exti1_handler,
    (uint32_t)&exti2_handler,
    (uint32_t)&exti3_handler,
    (uint32_t)&exti4_handler,
    (uint32_t)&dma1_channel1_handler,
    (uint32_t)&dma1_channel2_handler,
    (uint32_t)&dma1_channel3_handler,
    (uint32_t)&dma1_channel4_handler,
    (uint32_t)&dma1_channel5_handler,
    (uint32_t)&dma1_channel6_handler,
    (uint32_t)&dma1_channel7_handler,
    (uint32_t)&adc1_2_handler,
    (uint32_t)&usb_hp_can_tx_handler,
    (uint32_t)&usb_lp_can_rx0_handler,
    (uint32_t)&can_rx1_handler,
    (uint32_t)&can_sce_handler,
    (uint32_t)&exti9_5_handler,
    (uint32_t)&tim1_brk_handler,
    (uint32_t)&tim1_up_handler,
    (uint32_t)&tim1_trg_com_handler,
    (uint32_t)&tim1_cc_handler,
    (uint32_t)&tim2_handler,
    (uint32_t)&tim3_handler,
    (uint32_t)&tim4_handler,
    (uint32_t)&i2c1_ev_handler,
    (uint32_t)&i2c1_er_handler,
    (uint32_t)&i2c2_ev_handler,
    (uint32_t)&i2c2_er_handler,
    (uint32_t)&spi1_handler,
    (uint32_t)&spi2_handler,
    (uint32_t)&usart1_handler,
    (uint32_t)&usart2_handler,
    (uint32_t)&usart3_handler,
    (uint32_t)&exti15_10_handler,
    (uint32_t)&rtc_alarm_handler,
    (uint32_t)&usb_wakeup_handler
};

/* Linker symbols */
extern uint32_t _sdata; // Start of .data section in RAM
extern uint32_t _edata; // End of .data section in RAM
extern uint32_t _la_data; // Load address of .data section in Flash
extern uint32_t _sbss; // Start of .bss section in RAM
extern uint32_t _ebss; // End of .bss section in RAM
void main (void); // Forward declaration of main()

void reset_handler(void) {
    /* Copy .data section from Flash to SRAM */
    uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t *flash_data = (uint8_t*)&_la_data;
    uint8_t *sram_data = (uint8_t*)&_sdata;

    for (uint32_t i = 0; i< data_size; i++){
        sram_data[i] = flash_data[i];
    }

    /* Set zeros to entire .bss section in SRAM */
    uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    uint8_t *sram_bss = (uint8_t*)&_sbss;

    for (uint32_t i = 0; i < bss_size;i++){
        sram_bss[i] = 0;
    }
    main ();
}

void default_handler(void) {
    while (1);
}