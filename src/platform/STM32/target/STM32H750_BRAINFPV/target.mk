TARGET_MCU        := STM32H750xx
TARGET_MCU_FAMILY := STM32H7

HSE_VALUE          = 16000000
TARGET_FLASH_SIZE  = 1024

# BrainFPV custom bootloader: firmware executed from external QSPI flash mapped memory
LD_SCRIPT          = $(LINKER_DIR)/stm32_flash_h750_brainfpv.ld
STARTUP_SRC        = STM32/startup/startup_stm32h750xx_brainfpv.s

TARGET_SRC += \
              drivers/accgyro/accgyro_mpu.c \
              drivers/accgyro/accgyro_spi_bmi270.c \
              drivers/barometer/barometer_bmp388.c \
              drivers/barometer/barometer_2smpb_02b.c \
              drivers/barometer/barometer_dps310.c \
              $(addprefix drivers/compass/,$(notdir $(wildcard $(SRC_DIR)/drivers/compass/*.c))) \
              brainfpv/brainfpv_osd.c \
              brainfpv/brainfpv_system.c \
              brainfpv/brainfpv_rgb_led_timer.c \
              brainfpv/auto_sync_threshold.c \
              brainfpv/fonts_stm32h7xx.c \
              brainfpv/images.c \
              brainfpv/ir_transponder.c \
              brainfpv/osd_utils.c \
              brainfpv/spectrograph.c \
              brainfpv/video_quadspi.c \
              cms/cms_menu_brainfpv.c
