TARGET_MCU        := STM32H750xx
TARGET_MCU_FAMILY := STM32H7

HSE_VALUE          = 16000000

# The H750 has a single 128K internal flash sector, which holds the BrainFPV
# bootloader. The bootloader copies this image into RAM and executes it there,
# so link for RAM execution using BrainFPV's memory layout.
TARGET_FLASH_SIZE  := 1024
LD_SCRIPT           = $(LINKER_DIR)/stm32_ram_h750_brainfpv.ld

TARGET_SRC += \
              brainfpv_bootloader.c \
              brainfpv_rgb_led_timer.c \
              target.c \
              config.c

# RAM-boot startup: keeps Reset_Handler alongside the vector table so the
# bootloader's first loaded block contains both.
STARTUP_SRC         = STM32/startup/startup_stm32h750xx_brainfpv.s
