/*
 * Copyright (c) 2022 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This file is derivative of CMSIS V5.9.0 startup_ARMCM33.c
 * Git SHA: 2b7495b8535bdcb306dac29b9ded4cfb679d7e5c
 */

#include "cmsis.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern void __PROGRAM_START(void) __NO_RETURN;

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
void Reset_Handler  (void) __NO_RETURN;

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
#define DEFAULT_IRQ_HANDLER(handler_name)  \
void __WEAK handler_name(void) __NO_RETURN; \
void handler_name(void) { \
    while(1); \
}

/* Exceptions */
DEFAULT_IRQ_HANDLER(NMI_Handler)
DEFAULT_IRQ_HANDLER(HardFault_Handler)
DEFAULT_IRQ_HANDLER(MemManage_Handler)
DEFAULT_IRQ_HANDLER(BusFault_Handler)
DEFAULT_IRQ_HANDLER(UsageFault_Handler)
DEFAULT_IRQ_HANDLER(SecureFault_Handler)
DEFAULT_IRQ_HANDLER(SVC_Handler)
DEFAULT_IRQ_HANDLER(DebugMon_Handler)
DEFAULT_IRQ_HANDLER(PendSV_Handler)
DEFAULT_IRQ_HANDLER(SysTick_Handler)

DEFAULT_IRQ_HANDLER(NONSEC_WATCHDOG_RESET_Handler)
DEFAULT_IRQ_HANDLER(NONSEC_WATCHDOG_Handler)
DEFAULT_IRQ_HANDLER(S32K_TIMER_Handler)
DEFAULT_IRQ_HANDLER(TFM_TIMER0_IRQ_Handler)
DEFAULT_IRQ_HANDLER(TIMER1_Handler)
DEFAULT_IRQ_HANDLER(DUALTIMER_Handler)
DEFAULT_IRQ_HANDLER(MHU0_Handler)
DEFAULT_IRQ_HANDLER(MHU1_Handler)
DEFAULT_IRQ_HANDLER(MPC_Handler)
DEFAULT_IRQ_HANDLER(PPC_Handler)
DEFAULT_IRQ_HANDLER(MSC_Handler)
DEFAULT_IRQ_HANDLER(BRIDGE_ERROR_Handler)
DEFAULT_IRQ_HANDLER(INVALID_INSTR_CACHE_Handler)
DEFAULT_IRQ_HANDLER(SYS_PPU_Handler)
DEFAULT_IRQ_HANDLER(CPU0_PPU_Handler)
DEFAULT_IRQ_HANDLER(CPU1_PPU_Handler)
DEFAULT_IRQ_HANDLER(CPU0_DBG_PPU_Handler)
DEFAULT_IRQ_HANDLER(CPU1_DBG_PPU_Handler)
DEFAULT_IRQ_HANDLER(CRYPT_PPU_Handler)
DEFAULT_IRQ_HANDLER(RAM0_PPU_Handler)
DEFAULT_IRQ_HANDLER(RAM1_PPU_Handler)
DEFAULT_IRQ_HANDLER(RAM2_PPU_Handler)
DEFAULT_IRQ_HANDLER(RAM3_PPU_Handler)
DEFAULT_IRQ_HANDLER(DBG_PPU_Handler)
DEFAULT_IRQ_HANDLER(CPU0_CTI_Handler)
DEFAULT_IRQ_HANDLER(CPU1_CTI_Handler)

DEFAULT_IRQ_HANDLER(UARTRX0_Handler)
DEFAULT_IRQ_HANDLER(UARTTX0_Handler)
DEFAULT_IRQ_HANDLER(UARTRX1_Handler)
DEFAULT_IRQ_HANDLER(UARTTX1_Handler)
DEFAULT_IRQ_HANDLER(UARTRX2_Handler)
DEFAULT_IRQ_HANDLER(UARTTX2_Handler)
DEFAULT_IRQ_HANDLER(UARTRX3_Handler)
DEFAULT_IRQ_HANDLER(UARTTX3_Handler)
DEFAULT_IRQ_HANDLER(UARTRX4_Handler)
DEFAULT_IRQ_HANDLER(UARTTX4_Handler)
DEFAULT_IRQ_HANDLER(UART0_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART1_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART2_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART3_Combined_Handler)
DEFAULT_IRQ_HANDLER(UART4_Combined_Handler)
DEFAULT_IRQ_HANDLER(UARTOVF_Handler)
DEFAULT_IRQ_HANDLER(ETHERNET_Handler)
DEFAULT_IRQ_HANDLER(I2S_Handler)
DEFAULT_IRQ_HANDLER(TOUCH_SCREEN_Handler)
DEFAULT_IRQ_HANDLER(SPI_ADC_Handler)
DEFAULT_IRQ_HANDLER(SPI_SHIELD0_Handler)
DEFAULT_IRQ_HANDLER(SPI_SHIELD1_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_Combined_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_Combined_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_Combined_Handler)
DEFAULT_IRQ_HANDLER(GPIO3_Combined_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_0_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_1_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_2_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_3_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_4_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_5_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_6_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_7_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_8_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_9_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_10_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_11_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_12_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_13_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_14_Handler)
DEFAULT_IRQ_HANDLER(GPIO0_15_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_0_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_1_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_2_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_3_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_4_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_5_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_6_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_7_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_8_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_9_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_10_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_11_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_12_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_13_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_14_Handler)
DEFAULT_IRQ_HANDLER(GPIO1_15_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_0_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_1_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_2_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_3_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_4_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_5_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_6_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_7_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_8_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_9_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_10_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_11_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_12_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_13_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_14_Handler)
DEFAULT_IRQ_HANDLER(GPIO2_15_Handler)
DEFAULT_IRQ_HANDLER(GPIO3_0_Handler)
DEFAULT_IRQ_HANDLER(GPIO3_1_Handler)
DEFAULT_IRQ_HANDLER(GPIO3_2_Handler)
DEFAULT_IRQ_HANDLER(GPIO3_3_Handler)
DEFAULT_IRQ_HANDLER(UARTRX5_Handler)
DEFAULT_IRQ_HANDLER(UARTTX5_Handler)
DEFAULT_IRQ_HANDLER(UART5_Handler)
DEFAULT_IRQ_HANDLER(HDLCD_Handler)

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[];
       const VECTOR_TABLE_Type __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),            /*      Initial Stack Pointer */
  Reset_Handler,                     /*      Reset Handler */
  NMI_Handler,                       /* -14: NMI Handler */
  HardFault_Handler,                 /* -13: Hard Fault Handler */
  MemManage_Handler,                 /* -12: MPU Fault Handler */
  BusFault_Handler,                  /* -11: Bus Fault Handler */
  UsageFault_Handler,                /* -10: Usage Fault Handler */
  SecureFault_Handler,               /*  -9: Secure Fault Handler */
  0,                                 /*  -8: Reserved */
  0,                                 /*  -7: Reserved */
  0,                                 /*  -6: Reserved */
  SVC_Handler,                       /*  -5: SVCall Handler */
  DebugMon_Handler,                  /*  -4: Debug Monitor Handler */
  0,                                 /*  -3: Reserved */
  PendSV_Handler,                    /*  -2: PendSV Handler */
  SysTick_Handler,                   /*  -1: SysTick Handler */

  NONSEC_WATCHDOG_RESET_Handler,     /*   0: Non-Secure Watchdog Reset Request Handler */
  NONSEC_WATCHDOG_Handler,           /*   1: Non-Secure Watchdog Interrupt Handler */
  S32K_TIMER_Handler,                /*   2: S32K Timer Handler */
  TFM_TIMER0_IRQ_Handler,            /*   3: TIMER 0 Handler */
  TIMER1_Handler,                    /*   4: TIMER 1 Handler */
  DUALTIMER_Handler,                 /*   5: Dual Timer Handler */
  MHU0_Handler,                      /*   6: Message Handling Unit 0 */
  MHU1_Handler,                      /*   7: Message Handling Unit 1 */
  0,                                 /*   8: Reserved */
  MPC_Handler,                       /*   9: MPC Combined (Secure) Handler */
  PPC_Handler,                       /*  10: PPC Combined (Secure) Handler */
  MSC_Handler,                       /*  11: MSC Combined (Secure) Handler */
  BRIDGE_ERROR_Handler,              /*  12: Bridge Error (Secure) Handler */
  INVALID_INSTR_CACHE_Handler,       /*  13: CPU Instruction Cache Invalidation Handler */
  0,                                 /*  14: Reserved */
  SYS_PPU_Handler,                   /*  15: SYS PPU Handler */
  CPU0_PPU_Handler,                  /*  16: CPU0 PPU Handler */
  CPU1_PPU_Handler,                  /*  17: CPU1 PPU Handler */
  CPU0_DBG_PPU_Handler,              /*  18: CPU0 DBG PPU_Handler */
  CPU1_DBG_PPU_Handler,              /*  19: CPU1 DBG PPU_Handler */
  CRYPT_PPU_Handler,                 /*  20: CRYPT PPU Handler */
  0,                                 /*  21: Reserved */
  RAM0_PPU_Handler,                  /*  22: RAM0 PPU Handler */
  RAM1_PPU_Handler,                  /*  23: RAM1 PPU Handler */
  RAM2_PPU_Handler,                  /*  24: RAM2 PPU Handler */
  RAM3_PPU_Handler,                  /*  25: RAM3 PPU Handler */
  DBG_PPU_Handler,                   /*  26: DBG PPU Handler */
  0,                                 /*  27: Reserved */
  CPU0_CTI_Handler,                  /*  28: CPU0 CTI Handler */
  CPU1_CTI_Handler,                  /*  29: CPU1 CTI Handler */
  0,                                 /*  30: Reserved */
  0,                                 /*  31: Reserved */

  /* External interrupts */
  UARTRX0_Handler,                   /*  32: UART 0 RX Handler */
  UARTTX0_Handler,                   /*  33: UART 0 TX Handler */
  UARTRX1_Handler,                   /*  34: UART 1 RX Handler */
  UARTTX1_Handler,                   /*  35: UART 1 TX Handler */
  UARTRX2_Handler,                   /*  36: UART 2 RX Handler */
  UARTTX2_Handler,                   /*  37: UART 2 TX Handler */
  UARTRX3_Handler,                   /*  38: UART 3 RX Handler */
  UARTTX3_Handler,                   /*  39: UART 3 TX Handler */
  UARTRX4_Handler,                   /*  40: UART 4 RX Handler */
  UARTTX4_Handler,                   /*  41: UART 4 TX Handler */
  UART0_Combined_Handler,            /*  42: UART 0 Combined Handler */
  UART1_Combined_Handler,            /*  43: UART 1 Combined Handler */
  UART2_Combined_Handler,            /*  44: UART 2 Combined Handler */
  UART3_Combined_Handler,            /*  45: UART 3 Combined Handler */
  UART4_Combined_Handler,            /*  46: UART 4 Combined Handler */
  UARTOVF_Handler,                   /*  47: UART 0, 1, 2, 3, 4 & 5 Overflow Handler */
  ETHERNET_Handler,                  /*  48: Ethernet Handler */
  I2S_Handler,                       /*  49: Audio I2S Handler */
  TOUCH_SCREEN_Handler,              /*  50: Touch Screen Handler */
  0,                                 /*  51: Reserved */
  SPI_ADC_Handler,                   /*  52: SPI ADC Handler */
  SPI_SHIELD0_Handler,               /*  53: SPI (Shield 0) Handler */
  SPI_SHIELD1_Handler,               /*  54: SPI (Shield 0) Handler */
  0,                                 /*  55: Reserved */
  0,                                 /*  56: Reserved */
  0,                                 /*  57: Reserved */
  0,                                 /*  58: Reserved */
  0,                                 /*  59: Reserved */
  0,                                 /*  60: Reserved */
  0,                                 /*  61: Reserved */
  0,                                 /*  62: Reserved */
  0,                                 /*  63: Reserved */
  0,                                 /*  64: Reserved */
  0,                                 /*  65: Reserved */
  0,                                 /*  66: Reserved */
  0,                                 /*  67: Reserved */
  GPIO0_Combined_Handler,            /*  68: GPIO 0 Combined Handler */
  GPIO1_Combined_Handler,            /*  69: GPIO 1 Combined Handler */
  GPIO2_Combined_Handler,            /*  70: GPIO 2 Combined Handler */
  GPIO3_Combined_Handler,            /*  71: GPIO 3 Combined Handler */
  GPIO0_0_Handler,                   /*  72: GPIO0 Pin 0 Handler */
  GPIO0_1_Handler,                   /*  73: GPIO0 Pin 1 Handler */
  GPIO0_2_Handler,                   /*  74: GPIO0 Pin 2 Handler */
  GPIO0_3_Handler,                   /*  75: GPIO0 Pin 3 Handler */
  GPIO0_4_Handler,                   /*  76: GPIO0 Pin 4 Handler */
  GPIO0_5_Handler,                   /*  77: GPIO0 Pin 5 Handler */
  GPIO0_6_Handler,                   /*  78: GPIO0 Pin 6 Handler */
  GPIO0_7_Handler,                   /*  79: GPIO0 Pin 7 Handler */
  GPIO0_8_Handler,                   /*  80: GPIO0 Pin 8 Handler */
  GPIO0_9_Handler,                   /*  81: GPIO0 Pin 9 Handler */
  GPIO0_10_Handler,                  /*  82: GPIO0 Pin 10 Handler */
  GPIO0_11_Handler,                  /*  83: GPIO0 Pin 11 Handler */
  GPIO0_12_Handler,                  /*  84: GPIO0 Pin 12 Handler */
  GPIO0_13_Handler,                  /*  85: GPIO0 Pin 13 Handler */
  GPIO0_14_Handler,                  /*  86: GPIO0 Pin 14 Handler */
  GPIO0_15_Handler,                  /*  87: GPIO0 Pin 15 Handler */
  GPIO1_0_Handler,                   /*  88: GPIO1 Pin 0 Handler */
  GPIO1_1_Handler,                   /*  89: GPIO1 Pin 1 Handler */
  GPIO1_2_Handler,                   /*  90: GPIO1 Pin 2 Handler */
  GPIO1_3_Handler,                   /*  91: GPIO1 Pin 3 Handler */
  GPIO1_4_Handler,                   /*  92: GPIO1 Pin 4 Handler */
  GPIO1_5_Handler,                   /*  93: GPIO1 Pin 5 Handler */
  GPIO1_6_Handler,                   /*  94: GPIO1 Pin 6 Handler */
  GPIO1_7_Handler,                   /*  95: GPIO1 Pin 7 Handler */
  GPIO1_8_Handler,                   /*  96: GPIO1 Pin 8 Handler */
  GPIO1_9_Handler,                   /*  97: GPIO1 Pin 9 Handler */
  GPIO1_10_Handler,                  /*  98: GPIO1 Pin 10 Handler */
  GPIO1_11_Handler,                  /*  99: GPIO1 Pin 11 Handler */
  GPIO1_12_Handler,                  /*  100: GPIO1 Pin 12 Handler */
  GPIO1_13_Handler,                  /*  101: GPIO1 Pin 13 Handler */
  GPIO1_14_Handler,                  /*  102: GPIO1 Pin 14 Handler */
  GPIO1_15_Handler,                  /*  103: GPIO1 Pin 15 Handler */
  GPIO2_0_Handler,                   /*  104: GPIO2 Pin 0 Handler */
  GPIO2_1_Handler,                   /*  105: GPIO2 Pin 1 Handler */
  GPIO2_2_Handler,                   /*  106: GPIO2 Pin 2 Handler */
  GPIO2_3_Handler,                   /*  107: GPIO2 Pin 3 Handler */
  GPIO2_4_Handler,                   /*  108: GPIO2 Pin 4 Handler */
  GPIO2_5_Handler,                   /*  109: GPIO2 Pin 5 Handler */
  GPIO2_6_Handler,                   /*  110: GPIO2 Pin 6 Handler */
  GPIO2_7_Handler,                   /*  111: GPIO2 Pin 7 Handler */
  GPIO2_8_Handler,                   /*  112: GPIO2 Pin 8 Handler */
  GPIO2_9_Handler,                   /*  113: GPIO2 Pin 9 Handler */
  GPIO2_10_Handler,                  /*  114: GPIO2 Pin 10 Handler */
  GPIO2_11_Handler,                  /*  115: GPIO2 Pin 11 Handler */
  GPIO2_12_Handler,                  /*  116: GPIO2 Pin 12 Handler */
  GPIO2_13_Handler,                  /*  117: GPIO2 Pin 13 Handler */
  GPIO2_14_Handler,                  /*  118: GPIO2 Pin 14 Handler */
  GPIO2_15_Handler,                  /*  119: GPIO2 Pin 15 Handler */
  GPIO3_0_Handler,                   /*  120: GPIO3 Pin 0 Handler */
  GPIO3_1_Handler,                   /*  121: GPIO3 Pin 1 Handler */
  GPIO3_2_Handler,                   /*  122: GPIO3 Pin 2 Handler */
  GPIO3_3_Handler,                   /*  123: GPIO3 Pin 3 Handler */
  UARTRX5_Handler,                   /*  124: UART 5 RX Interrupt */
  UARTTX5_Handler,                   /*  125: UART 5 TX Interrupt */
  UART5_Handler,                     /*  126: UART 5 combined Interrupt */
  HDLCD_Handler,                     /*  127: HDCLCD interrupt */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __disable_irq();
#endif
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();                             /* CMSIS System Initialization */
    __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}
