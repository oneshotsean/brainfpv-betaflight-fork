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
 * Base platform target for BrainFPV boards using STM32H750.
 * Includes all STM32H750 capabilities plus BrainFPV-specific features.
 */

#pragma once

// Include the upstream H750 base target definitions
#include "platform/STM32/target/STM32H750/target.h"

// BrainFPV boards use a 16 MHz crystal
#define SYSTEM_HSE_MHZ 16

// BrainFPV boards boot from external QSPI flash
#undef CONFIG_IN_RAM
#define CONFIG_IN_EXTERNAL_FLASH
#define USE_FIRMWARE_PARTITION
#define FLASH_PAGE_SIZE 0x10000

// Vector table base in DTCM RAM (firmware placed here by bootloader)
#define VECT_TAB_BASE 0x24000000

// BrainFPV bootloader support
#define USE_BRAINFPV_BOOTLOADER

// BrainFPV RGB status LED
#define USE_BRAINFPV_RGB_STATUS_LED
#define USE_BRAINFPV_RGB_LED_TIMER

// BrainFPV OSD support
#define USE_BRAINFPV_OSD
#define BRAINFPV_OSD_CMS_BG_BOX
#define BRAINFPV_OSD_CMS_CURSOR_HIGHLIGHT
#define BRAINFPV_OSD_CMS_FANCY_TITLE_FONT 2

#define USE_MAX7456
#define USE_OSD
#define USE_CMS
#define OSD_CALLS_CMS

#define USE_BEEPER

#define USE_PINIO
#define USE_PINIOBOX

#define USE_UART

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6
#define USE_UART7
#define USE_UART8

#define USE_VCP
#define VBUS_SENSING_ENABLED
#define USE_USB48MHZ_PLL

#define USE_SPI
#define USE_SPI_DMA_ENABLE_LATE

#define USE_I2C
#define I2C_FULL_RECONFIGURABILITY
#define USE_I2C_DEVICE_1
#undef I2C1_OVERCLOCK

#define USE_MAG
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define USE_MAG_LIS3MDL
#define USE_MAG_AK8963
#define USE_MAG_AK8975

#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define QUADSPI1_MODE QUADSPI_MODE_BK1_ONLY

#define USE_FLASH_M25P16
#define USE_FLASH_QUADSPI
#define FLASH_QUADSPI_INSTANCE QUADSPI
#define USE_FLASHFS

#define USE_SDCARD
#define USE_SDCARD_SDIO

#define USE_EXTI
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
#define USE_BARO_DPS310

#define USE_ADC
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

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff
#define TARGET_IO_PORTG 0xffff

#define USE_TIMER_UP_CONFIG

#undef USE_DSHOT_BITBANG
#undef USE_BRUSHED_ESC_AUTODETECT

extern bool brainfpv_settings_updated_from_cms;
void brainFPVUpdateSettings(void);
