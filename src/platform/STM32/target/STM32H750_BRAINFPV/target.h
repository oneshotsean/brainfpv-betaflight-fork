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

/*
 * Platform target for BrainFPV boards using STM32H750 (RADIX2, RADIX2HD).
 * Self-contained — inlines the STM32H750 base definitions plus BrainFPV
 * additions so no cross-target #include is needed.
 */

#pragma once

// ---------------------------------------------------------------------------
// STM32H750 base capabilities (inlined from STM32H750/target.h)
// ---------------------------------------------------------------------------

#ifndef TARGET_BOARD_IDENTIFIER
#define TARGET_BOARD_IDENTIFIER "H750"
#endif

#ifndef USBD_PRODUCT_STRING
#define USBD_PRODUCT_STRING     "Betaflight STM32H750"
#endif

#if !defined(USE_I2C)
#define USE_I2C
#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3
#define USE_I2C_DEVICE_4
#define I2C_FULL_RECONFIGURABILITY
#endif

#if !defined(USE_SPI)
#define USE_SPI
#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3
#define USE_SPI_DEVICE_4
#define USE_SPI_DEVICE_5
#define USE_SPI_DEVICE_6
#define SPI_FULL_RECONFIGURABILITY
#endif

#define USE_SPI_DMA_ENABLE_LATE

#define QUADSPIDEV_COUNT 1

#define USE_VCP

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6
#define USE_UART7
#define USE_UART8
#define USE_LPUART1

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

#define USE_BEEPER
#define USE_USB_DETECT
#define USE_ESCSERIAL
#define USE_ADC

// BrainFPV boards always boot from external flash — override the H750 default
#define CONFIG_IN_EXTERNAL_FLASH

#define USE_EXTI
#define USE_TIMER_UP_CONFIG

#define FLASH_PAGE_SIZE ((uint32_t)0x10000) // 64K sectors for BrainFPV QSPI flash

#if defined(USE_LED_STRIP) && !defined(USE_LED_STRIP_CACHE_MGMT)
#define USE_LED_STRIP_CACHE_MGMT
#endif

// ---------------------------------------------------------------------------
// BrainFPV-specific additions
// ---------------------------------------------------------------------------

// Firmware executes from external QSPI flash via BrainFPV bootloader
#define USE_FIRMWARE_PARTITION
#define VECT_TAB_BASE 0x24000000
#define USE_BRAINFPV_BOOTLOADER

// BrainFPV analog OSD system — only on boards with QSPI video output (e.g. RADIX2)
#if defined(INCLUDE_VIDEO_QUADSPI)
#define USE_BRAINFPV_OSD
#define BRAINFPV_OSD_CMS_BG_BOX
#define BRAINFPV_OSD_CMS_CURSOR_HIGHLIGHT
#define BRAINFPV_OSD_CMS_FANCY_TITLE_FONT 2
#endif

#if defined(INCLUDE_VIDEO_QUADSPI)
// BrainFPV OSD provides its own max7456 stub implementations
#define VIDEO_BITS_PER_PIXEL 4
#else
#define USE_MAX7456
#endif

#define USE_OSD
#define USE_CMS
#define OSD_CALLS_CMS

// BrainFPV RGB status LED
#define USE_BRAINFPV_RGB_STATUS_LED
#define USE_BRAINFPV_RGB_LED_TIMER

#define USE_PINIO
#define USE_PINIOBOX

#define VBUS_SENSING_ENABLED
#define USE_USB48MHZ_PLL

#define USE_MAG
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define USE_MAG_LIS3MDL
#define USE_MAG_AK8963
#define USE_MAG_AK8975

#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1

#define USE_FLASH_M25P16
#define USE_FLASH_QUADSPI
#define FLASH_QUADSPI_INSTANCE QUADSPI
#define USE_FLASHFS

#define USE_GYRO
#define USE_ACC
#undef USE_MULTI_GYRO
#define USE_MPU_DATA_READY_SIGNAL
#define USE_GYRO_EXTI
#define USE_SPI_GYRO
#define USE_GYRO_SPI_BMI270
#define USE_ACCGYRO_BMI270
#undef USE_GYRO_DLPF_EXPERIMENTAL
#undef USE_GYRO_REGISTER_DUMP

#define USE_BARO

#define USE_ADC_INTERNAL
#define BOARD_HAS_VOLTAGE_DIVIDER
#define ADC_VOLTAGE_REFERENCE_MV 3285
#define DEFAULT_VOLTAGE_METER_SCALE   176
#define DEFAULT_CURRENT_METER_SCALE   200
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC

#define DEFAULT_FEATURES        (FEATURE_OSD)
#define SERIALRX_UART           SERIAL_PORT_USART3
#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF

#define USE_TIMER_UP_CONFIG

#undef USE_DSHOT_BITBANG
#undef USE_BRUSHED_ESC_AUTODETECT
