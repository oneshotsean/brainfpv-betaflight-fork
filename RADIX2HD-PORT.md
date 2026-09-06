# RADIX 2 HD — Betaflight 2026.6.1 port

This fork adds a `RADIX2HD` target to current Betaflight (2026.6.1) for the
BrainFPV RADIX 2 HD.

BrainFPV's own Betaflight fork stops at 4.5.1 (`brainfpv-4.5-maintenance`).
That branch predates two large upstream changes — the removal of the legacy
per-board target format and the move to `src/platform/<PLATFORM>/` — so the
old target could not be carried over as-is.

## Build

```
make brainfpv_bin TARGET=RADIX2HD
```

This produces `obj/betaflight_<version>_RADIX2HD_brainfpv.bin`. Copy that file
to the USB drive that appears when the board is connected in bootloader mode
(hold BOOT while plugging in USB), then safely eject. Plain `make TARGET=RADIX2HD`
produces only the ELF/HEX, which the bootloader cannot consume.

Packing needs the [BrainFPV firmware packer](https://github.com/BrainFPV/brainfpv_fw_packer):

```
pip install https://github.com/BrainFPV/brainfpv_fw_packer/archive/main.zip
```

## What this port changes

The board needs very little beyond a normal Betaflight target, because the
RADIX 2 HD is an HD (digital) board: it drives its OSD over MSP DisplayPort
using stock Betaflight code, and needs none of the analog video/OSD stack that
BrainFPV's RADIX, RADIX 2 and BRAINRE1 targets carry.

Added:

- `src/platform/STM32/target/RADIX2HD/` — the target: pin/peripheral config,
  the bootloader header, the RGB status LED driver and its timer channels.
- `src/platform/STM32/link/stm32_ram_h750_brainfpv.ld` — BrainFPV's RAM
  execution layout, carried over unchanged.
- `src/platform/STM32/startup/startup_stm32h750xx_brainfpv.s` — stock H7
  startup with BrainFPV's one change: the `.data`/`.bss` address words and
  `Reset_Handler` move into `.text.Reset_Handler` so the linker keeps them in
  the same loaded block as the vector table.

Modified upstream files (2, both small):

- `src/main/drivers/light_led.c` — routes the two status LEDs to the RGB LED.
- `src/platform/STM32/mk/STM32H7.mk` — `STARTUP_SRC ?=` instead of `=` for
  H750, so a target can supply its own startup code.

## How it boots

The H750's single 128K internal flash sector holds the BrainFPV bootloader, so
the firmware runs from RAM. The bootloader reads a header embedded in the image
(`brainfpv_bootloader.c`, placed by the `.bl_header` section directly after the
vector table), checks `target_magic`, loads each section to its address, and
jumps to `isr_vector_base` (`0x24000000`). Nothing in the firmware sets `VTOR`;
the bootloader does that.

Because of this the packer is invoked differently than for ArduPilot: `-b` is
the *address of the embedded header*, and `--noheader` is not passed.

## Verified

- Builds clean from scratch (GCC 13.2.1 and Betaflight's pinned 13.3.1).
- Section addresses land within the regions the bootloader accepts for this
  device, and the packer produces a valid image.
- Bootloader header contains the correct magic (`0x785E9A14`) and vector base.
- All 11 `TIMER_PIN_MAP` entries re-checked against 2026.6.1's
  `fullTimerHardware` table — motors, servos and LED strip resolve to the same
  timers and channels as the 4.5 target.

## NOT verified — read before flying

**None of this has run on hardware.** It has never been flashed, powered, armed
or flown. Treat it as untested firmware:

- Flash it only if you can recover the board (the BrainFPV bootloader is in
  internal flash and is not touched by this image, so a bad image should still
  leave you able to reflash).
- Bench-test with props off: check IMU orientation, motor order and direction,
  RX, OSD, battery voltage/current scaling and the RGB status LED before arming.

Specific things most likely to need attention:

- The RGB status LED path is a straight port; `pwmOutputConfig()` now starts the
  timer itself, so the old manual `HAL_TIM_Base_Start()` was dropped. Worth
  confirming the LED actually lights.
- The bootloader header's offset shifts with the size of `Reset_Handler`. If the
  bootloader expects it at a fixed offset rather than locating it by the address
  the packer is given, this needs checking.
- ChibiOS was **not** carried over (see below).

## Deliberate differences from BrainFPV's 4.5 fork

**ChibiOS is not used.** BrainFPV's fork runs Betaflight's scheduler as a
ChibiOS thread and uses ChibiOS sync primitives in the SPI and gyro drivers.
That integration touches `scheduler.c`, `bus_spi.c`, `main.c` and the gyro
drivers, all of which changed substantially upstream since 4.5.1. This target
runs bare-metal like every other current Betaflight board. It builds, but the
consequences on hardware are untested, and this is the largest single deviation
from BrainFPV's firmware.

**Analog OSD stack omitted** — `video_quadspi.c`, fonts, images, `osd_utils`,
`spectrograph`, `ir_transponder`, `cms_menu_brainfpv` and the FPGA driver are
for the analog boards. RADIX2HD's target never enabled them.

## Memory

`CODE_RAM` sits at ~98% (505,733 of 516,096 bytes). Current Betaflight is
considerably larger than 4.5, and the RAM execution budget is fixed by the
bootloader's loadable regions. Adding features will overflow the region; the
link will fail loudly rather than produce a broken image.

`D2_RAM` (224K at `0x30000000`) is entirely unused — BrainFPV reserved it for
video RAM on the analog boards. It is within the bootloader's loadable regions,
so it is the obvious place to reclaim space from if more room is needed.
