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

#define BOARD_NAME        RADIX2
#define MANUFACTURER_ID   BFPV

#define TARGET_BOARD_IDENTIFIER "RDX2"
#define USBD_PRODUCT_STRING     "BrainFPV RADIX 2"

#define SYSTEM_HSE_MHZ  16

#define BOOTLOADER_TARGET_MAGIC 0x65DF92FE

// BrainFPV FPGA
#define BRAINFPVFPGA_SPI_INSTANCE SPI3
#define BRAINFPVFPGA_SPI_DIVISOR  8
#define BRAINFPVFPGA_CS_PIN       PE1
#define BRAINFPVFPGA_RESET_PIN    PC4
#define BRAINFPVFPGA_CLOCK_PIN    PA8

// OSD video system
#define VIDEO_BITS_PER_PIXEL 4
#define INCLUDE_VIDEO_QUADSPI
#define VIDEO_QSPI_CLOCK_PIN PB2
#define VIDEO_QSPI_IO0_PIN   PD11
#define VIDEO_QSPI_IO1_PIN   PC10
#define VIDEO_QSPI_IO2_PIN   PE2
#define VIDEO_QSPI_IO3_PIN   PA1
#define VIDEO_VSYNC          PE3
#define VIDEO_HSYNC          PD5

#define USE_BRAINFPV_AUTO_SYNC_THRESHOLD
#define AUTO_SYNC_THRESHOLD_ADC_INSTANCE ADC2_INSTANCE
#define AUTO_SYNC_THRESHOLD_ADC_PIN PC3
#define AUTO_SYNC_THRESHOLD_ADC_CHANNEL ADC_CHANNEL_13

#define BRAINFPV_OSD_USE_STM32CMP
#define BRAINFPV_OSD_STM32CMP_DAC_INSTANCE DAC1
#define BRAINFPV_OSD_STM32CMP_CMP_INSTANCE COMP2
#define BRAINFPV_OSD_STM32CMP_CMP_INPUT_PIN PE9
#define BRAINFPV_OSD_STM32CMP_CMP_OUTPUT_PIN PE8

#define BRAINFPV_OSD_SYNC_TH_DEFAULT 150
#define BRAINFPV_OSD_SYNC_TH_MIN 0
#define BRAINFPV_OSD_SYNC_TH_MAX 255

// LEDs
#define LED0_PIN                PE6
#define LED0_INVERTED
#define LED1_PIN                PE7
#define LED1_INVERTED

#define BEEPER_PIN              PD14
#define BEEPER_INVERTED

#define PINIO1_PIN              PD15 // VTX power
#define PINIO2_PIN              PC15 // Video input select

#define VTXFAULT_PIN            PD10

// UARTs
#define UART1_RX_PIN            PB15
#define UART1_TX_PIN            PB6

#define UART2_RX_PIN            PA3
#define UART2_TX_PIN            PA2

#define UART3_RX_PIN            PB11
#define UART3_TX_PIN            PD8

#define UART4_RX_PIN            PD0
#define UART4_TX_PIN            PD1

#define UART5_RX_PIN            PB12
#define UART5_TX_PIN            PB13

#define UART6_RX_PIN            PC7
#define UART6_TX_PIN            PC6

#define VBUS_SENSING_PIN        PA9
#define SERIAL_PORT_COUNT       7

// SPI1 - Gyro
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PB4
#define SPI1_SDO_PIN            PD7

// SPI2 - Gyro (alt)
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PD3
#define SPI2_SDI_PIN            PC2
#define SPI2_SDO_PIN            PC1

// SPI3 - FPGA (disable DMA)
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            PB3
#define SPI3_SDI_PIN            PC11
#define SPI3_SDO_PIN            PC12
#define SPI3_NSS_PIN            PA15
#define SPI3_TX_DMA_OPT         -2
#define SPI3_RX_DMA_OPT         -2

// I2C1 - Magnetometer
#define I2C1_SCL_PIN             PB8
#define I2C1_SDA_PIN             PB7
#define I2C_DEVICE               (I2CDEV_1)
#define MAG_I2C_INSTANCE         I2C_DEVICE

// External flash (config + blackbox)
#define M25P16_FIRST_SECTOR     32
#define M25P16_SECTORS_SPARE_END 3
#define FLASH_CS_PIN            PE14
#define FLASH_SPI_INSTANCE      SPI1
#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH

// Gyro - BMI270 on SPI2
#define GYRO_1_EXTI_PIN         PE4
#define GYRO_1_CS_PIN           PE15
#define GYRO_1_SPI_INSTANCE     SPI2
#define GYRO_1_ALIGN            CW0_DEG

// ADC
#define ADC1_INSTANCE ADC1
#define ADC2_INSTANCE ADC2
#define ADC3_INSTANCE ADC3
#define ADC_RSSI_PIN  PC0
#define ADC_VBAT_PIN  PA6
#define ADC_CURR_PIN  PB0
#define ADC1_DMA_OPT 8
#define ADC3_DMA_OPT 9

// Motor/servo/LED outputs
#define MOTOR1_PIN           PA0   // TIM2 CH1
#define MOTOR2_PIN           PB5   // TIM3 CH2
#define MOTOR3_PIN           PD12  // TIM4 CH1
#define MOTOR4_PIN           PD13  // TIM4 CH2
#define MOTOR5_PIN           PC9   // TIM8 CH4
#define MOTOR6_PIN           PC8   // TIM8 CH3
#define MOTOR7_PIN           PE13  // TIM1 CH3
#define MOTOR8_PIN           PE11  // TIM1 CH2
#define SERVO1_PIN           PA2   // TIM15 CH1, also UART2_TX
#define SERVO2_PIN           PA3   // TIM15 CH2, also UART2_RX
#define RX_PPM_PIN           PB14  // TIM12 CH1
#define CAMERA_CONTROL_PIN   PA7   // TIM14 CH1

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA0,  1,  0) \
    TIMER_PIN_MAP( 1, PB5,  1,  1) \
    TIMER_PIN_MAP( 2, PD12, 1,  2) \
    TIMER_PIN_MAP( 3, PD13, 1,  3) \
    TIMER_PIN_MAP( 4, PC9,  2,  4) \
    TIMER_PIN_MAP( 5, PC8,  2,  5) \
    TIMER_PIN_MAP( 6, PE13, 1,  6) \
    TIMER_PIN_MAP( 7, PE11, 1,  7) \
    TIMER_PIN_MAP( 8, PA2,  3, -1) \
    TIMER_PIN_MAP( 9, PA3,  3, -1) \
    TIMER_PIN_MAP(10, PB14, 2, -1) \
    TIMER_PIN_MAP(11, PA7,  4, -1)
