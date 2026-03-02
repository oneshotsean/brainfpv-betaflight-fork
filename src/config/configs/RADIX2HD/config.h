/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Maps to src/platform/STM32/target/STM32H750_BRAINFPV/
#define FC_TARGET_MCU     STM32H750_BRAINFPV

#define BOARD_NAME        RADIX2HD
#define MANUFACTURER_ID   BFPV

#define TARGET_BOARD_IDENTIFIER "RDX2HD"
#define USBD_PRODUCT_STRING     "BrainFPV RADIX 2 HD"

#define SYSTEM_HSE_MHZ  16

#define BOOTLOADER_TARGET_MAGIC 0x785E9A14

// Custom reset pin
#define CUSTOM_RESET_PIN PC13

// RGB LED timers
#define BRAINFPV_RGB_LED_TIMERS (TIM_N(14) | TIM_N(15))
#define LED0_PIN                PA7
#define LED0_INVERTED
#define LED1_PIN                PE5
#define LED1_INVERTED

#define BEEPER_PIN              PE4
#define BEEPER_INVERTED

#define PINIO1_PIN              PC14 // VREG HD

// UART pin assignments
#define UART1_RX_PIN            PB15
#define UART1_TX_PIN            PB14

#define UART2_RX_PIN            PD6
#define UART2_TX_PIN            PD5

#define UART3_RX_PIN            PB11
#define UART3_TX_PIN            PD8

#define UART4_RX_PIN            PB8
#define UART4_TX_PIN            PA0

#define UART5_RX_PIN            PB12
#define UART5_TX_PIN            PB13

#define UART6_RX_PIN            PC7
#define UART6_TX_PIN            PC6

#define UART7_RX_PIN            PA8
#define UART7_TX_PIN            NONE

#define VBUS_SENSING_PIN        PA9
#define SERIAL_PORT_COUNT       8

// SPI device 1 - Gyro
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN           PA5
#define SPI1_SDI_PIN           PB4
#define SPI1_SDO_PIN           PD7

// I2C device 1 - Magnetometer
#define I2C1_SCL_PIN           PB6
#define I2C1_SDA_PIN           PB7
#define I2C_DEVICE             (I2CDEV_1)
#define MAG_I2C_INSTANCE       I2C_DEVICE

// QSPI - External flash (config storage and OSD video)
#define QUADSPI1_SCK_PIN       PB2
#define QUADSPI1_BK1_IO0_PIN   PD11
#define QUADSPI1_BK1_IO1_PIN   PD12
#define QUADSPI1_BK1_IO2_PIN   PE2
#define QUADSPI1_BK1_IO3_PIN   PA1
#define QUADSPI1_BK1_CS_PIN    PB10
#define QUADSPI1_BK2_IO0_PIN   NONE
#define QUADSPI1_BK2_IO1_PIN   NONE
#define QUADSPI1_BK2_IO2_PIN   NONE
#define QUADSPI1_BK2_IO3_PIN   NONE
#define QUADSPI1_BK2_CS_PIN    NONE
#define QUADSPI1_CS_FLAGS (QUADSPI_BK1_CS_HARDWARE | QUADSPI_BK2_CS_NONE | QUADSPI_CS_MODE_LINKED)

#define M25P16_FIRST_SECTOR     64
#define M25P16_SECTORS_SPARE_END 3
#define EEPROM_SIZE 8192

// SD card via SDIO
#define SDCARD_DETECT_PIN      PD9
#define SDCARD_DETECT_INVERTED
#define SDIO_DEVICE            SDIODEV_1
#define SDIO_USE_4BIT          true
#define SDIO_USE_PULLUP
#define SDIO_CK_PIN            PC12
#define SDIO_CMD_PIN           PD2
#define SDIO_D0_PIN            PC8
#define SDIO_D1_PIN            PC9
#define SDIO_D2_PIN            PC10
#define SDIO_D3_PIN            PC11

#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD

// Gyro - BMI270 on SPI1
#define GYRO_1_EXTI_PIN        PB3
#define GYRO_1_CS_PIN          PD3
#define GYRO_1_SPI_INSTANCE    SPI1
#define GYRO_1_ALIGN           CW0_DEG

// Barometer - DPS310

// ADC
#define ADC1_INSTANCE ADC1
#define ADC2_INSTANCE ADC2
#define ADC3_INSTANCE ADC3
#define ADC_RSSI_PIN            PC1
#define ADC_VBAT_PIN            PC0
#define ADC_CURR_PIN            PA6
#define ADC1_DMA_OPT 8
#define ADC3_DMA_OPT 9

#define LIGHT_WS2811_INVERTED
#define USE_LED_STRIP_CACHE_MGMT

// Motor/servo/LED outputs
#define MOTOR1_PIN           PE11  // TIM1 CH2
#define MOTOR2_PIN           PE13  // TIM1 CH3
#define MOTOR3_PIN           PA15  // TIM2 CH1
#define MOTOR4_PIN           PA2   // TIM2 CH3
#define MOTOR5_PIN           PB5   // TIM3 CH2
#define MOTOR6_PIN           PB0   // TIM3 CH3
#define MOTOR7_PIN           PD13  // TIM4 CH2
#define MOTOR8_PIN           PD14  // TIM4 CH3
#define SERVO1_PIN           PC6   // TIM8 CH1, also UART6_TX
#define SERVO2_PIN           PC7   // TIM8 CH2, also UART6_RX
#define LED_STRIP_PIN        PA3   // TIM5 CH4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PE11, 1,  0) \
    TIMER_PIN_MAP( 1, PE13, 1,  1) \
    TIMER_PIN_MAP( 2, PA15, 1,  2) \
    TIMER_PIN_MAP( 3, PA2,  1,  3) \
    TIMER_PIN_MAP( 4, PB5,  1,  4) \
    TIMER_PIN_MAP( 5, PB0,  2,  5) \
    TIMER_PIN_MAP( 6, PD13, 1,  6) \
    TIMER_PIN_MAP( 7, PD14, 1,  7) \
    TIMER_PIN_MAP( 8, PC6,  2, -1) \
    TIMER_PIN_MAP( 9, PC7,  2, -1) \
    TIMER_PIN_MAP(10, PA3,  2, 15)
