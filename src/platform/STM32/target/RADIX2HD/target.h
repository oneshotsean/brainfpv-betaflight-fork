/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdbool.h>

#define TARGET_BOARD_IDENTIFIER "RDX2HD"
#define USBD_PRODUCT_STRING "BrainFPV RADIX 2 HD"

#define USE_BRAINFPV_BOOTLOADER
#define BOOTLOADER_TARGET_MAGIC 0x785E9A14
// RAM address the bootloader loads this image to and jumps into.
#define VECT_TAB_BASE 0x24000000

#define CUSTOM_RESET_PIN PC13

#define USE_TARGET_CONFIG

// Status "LEDs" are the colours of a single RGB LED driven by TIM14/TIM15;
// see target.c for the channel mapping.
#define USE_BRAINFPV_RGB_STATUS_LED
#define USE_BRAINFPV_RGB_LED_TIMER
#define BRAINFPV_RGB_LED_TIMERS (TIM_N(14) | TIM_N(15))
#define LED0_PIN                PA7
#define LED0_INVERTED
#define LED1_PIN                PE5
#define LED1_INVERTED

#define USE_BEEPER
#define BEEPER_PIN              PE4
#define BEEPER_INVERTED

#define USE_PINIO
#define PINIO1_PIN              PC14 // VREG HD
#define USE_PINIOBOX

#define USE_UART

#define USE_UART1
#define UART1_RX_PIN            PB15
#define UART1_TX_PIN            PB14

#define USE_UART2
#define UART2_RX_PIN            PD6
#define UART2_TX_PIN            PD5

#define USE_UART3
#define UART3_RX_PIN            PB11
#define UART3_TX_PIN            PD8

#define USE_UART4
#define UART4_RX_PIN            PB8
#define UART4_TX_PIN            PA0

#define USE_UART5
#define UART5_RX_PIN            PB12
#define UART5_TX_PIN            PB13

#define USE_UART6
#define UART6_RX_PIN            PC7
#define UART6_TX_PIN            PC6

#define USE_UART7
#define UART7_RX_PIN            PA8
#define UART7_TX_PIN            NONE

#define USE_VCP
#define VBUS_SENSING_PIN        PA9
#define VBUS_SENSING_ENABLED

// SERIAL_PORT_COUNT is derived by io/serial.h in current Betaflight and must
// not be set by the target.

#define USE_SPI
#define USE_SPI_DMA_ENABLE_LATE

#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN           PA5
#define SPI1_SDI_PIN           PB4
#define SPI1_SDO_PIN           PD7

#define USE_I2C
#define I2C_FULL_RECONFIGURABILITY
#define USE_I2C_DEVICE_1
#undef I2C1_OVERCLOCK
#define I2C1_SCL_PIN           PB6
#define I2C1_SDA_PIN           PB7
#define I2C_DEVICE             (I2CDEV_1)

#define USE_MAG
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define USE_MAG_LIS3MDL
#define USE_MAG_AK8963
#define USE_MAG_AK8975
#define MAG_I2C_INSTANCE      I2C_DEVICE

#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define QUADSPI1_SCK_PIN PB2
#define QUADSPI1_BK1_IO0_PIN PD11
#define QUADSPI1_BK1_IO1_PIN PD12
#define QUADSPI1_BK1_IO2_PIN PE2
#define QUADSPI1_BK1_IO3_PIN PA1
#define QUADSPI1_BK1_CS_PIN PB10

#define QUADSPI1_BK2_IO0_PIN NONE
#define QUADSPI1_BK2_IO1_PIN NONE
#define QUADSPI1_BK2_IO2_PIN NONE
#define QUADSPI1_BK2_IO3_PIN NONE
#define QUADSPI1_BK2_CS_PIN NONE

#define QUADSPI1_MODE QUADSPI_MODE_BK1_ONLY
#define QUADSPI1_CS_FLAGS (QUADSPI_BK1_CS_HARDWARE | QUADSPI_BK2_CS_NONE | QUADSPI_CS_MODE_LINKED)

// Supplied by the STM32H750 base target in stock Betaflight; this target
// replaces that header, so the MCU-level counts/features are declared here.
#define QUADSPIDEV_COUNT 1
#define USE_USB_DETECT
#define USE_ESCSERIAL

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_QUADSPI
#define FLASH_QUADSPI_INSTANCE QUADSPI
#define USE_FLASHFS
#define CONFIG_IN_EXTERNAL_FLASH
#define EEPROM_SIZE 8192

// Config uses one 64 kB flash sector
#define FLASH_PAGE_SIZE 0x10000

#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDCARD_DETECT_PIN PD9
#define SDCARD_DETECT_INVERTED
#define SDIO_DEVICE             SDIODEV_1
#define SDIO_USE_4BIT           true
#define SDIO_USE_PULLUP
#define SDIO_CK_PIN             PC12
#define SDIO_CMD_PIN            PD2
#define SDIO_D0_PIN             PC8
#define SDIO_D1_PIN             PC9
#define SDIO_D2_PIN             PC10
#define SDIO_D3_PIN             PC11

#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD

#define USE_EXTI
#define USE_GYRO
#define USE_ACC
#undef USE_MULTI_GYRO

#define USE_GYRO_EXTI
#define USE_SPI_GYRO
#define USE_GYRO_SPI_BMI270
#define USE_ACC_SPI_BMI270
#define USE_ACCGYRO_BMI270
#undef USE_GYRO_DLPF_EXPERIMENTAL
#undef USE_GYRO_REGISTER_DUMP

#define GYRO_1_EXTI_PIN           PB3
#define GYRO_1_CS_PIN             PD3
#define GYRO_1_SPI_INSTANCE       SPI1
#define GYRO_1_ALIGN              CW0_DEG

#define USE_BARO
#define USE_BARO_DPS310

#define USE_ADC
#define USE_ADC_INTERNAL // ADC3

#define ADC1_INSTANCE ADC1
#define ADC2_INSTANCE ADC2 // not used
#define ADC3_INSTANCE ADC3 // ADC3 only for core temp and vrefint
#define ADC_RSSI_PIN            PC1
#define ADC_VBAT_PIN            PC0
#define ADC_CURR_PIN            PA6

#define BOARD_HAS_VOLTAGE_DIVIDER
#define ADC_VOLTAGE_REFERENCE_MV 3285
#define DEFAULT_VOLTAGE_METER_SCALE   176
#define DEFAULT_CURRENT_METER_SCALE   200
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC

#define ADC1_DMA_OPT 8
#define ADC3_DMA_OPT 9

#define USE_LED_STRIP
#define USE_LED_STRIP_CACHE_MGMT

#define DEFAULT_FEATURES        (FEATURE_OSD)
#define SERIALRX_UART           SERIAL_PORT_USART3
#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff
#define TARGET_IO_PORTG 0xffff

// Timers and outputs
#define USE_TIMER_UP_CONFIG

#define MOTOR1_PIN           PE11  // TIM1 CH2
#define MOTOR2_PIN           PE13  // TIM1 CH3
#define MOTOR3_PIN           PA15  // TIM2 CH1
#define MOTOR4_PIN           PA2   // TIM2 CH3
#define MOTOR5_PIN           PB5   // TIM3 CH2
#define MOTOR6_PIN           PB0   // TIM3 CH3
#define MOTOR7_PIN           PD13  // TIM4 CH2
#define MOTOR8_PIN           PD14  // TIM4 CH3
#define SERVO1_PIN           PC6   // TIM8 CH1, Also TX6
#define SERVO2_PIN           PC7   // TIM8 CH2, Also RX6
#define LED_STRIP_PIN        PA3   // TIM5 CH4

// TIMER_PIN_MAPPING(index, pin, occurence in fullTimerHardware, dma opt)
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

#undef USE_DSHOT_BITBANG
#undef USE_BRUSHED_ESC_AUTODETECT

void CustomSystemReset(void);
