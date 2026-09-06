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
 * Header consumed by the BrainFPV bootloader.
 *
 * The bootloader validates target_magic to confirm the image belongs to this
 * board, then jumps to the vector table at isr_vector_base after copying the
 * packed sections into RAM. The header must live at a fixed offset directly
 * after the vector table, which the .bl_header section in the target's linker
 * script guarantees.
 */

#include <stdint.h>

#include "platform.h"

#if defined(USE_BRAINFPV_BOOTLOADER)

#include "drivers/io.h"

typedef struct __attribute__((packed)) {
    uint32_t target_magic;
    uint32_t isr_vector_base;
} brainFpvBlHeader_t;

const brainFpvBlHeader_t __attribute__((section(".bl_header_section"))) __attribute__((used)) BRAINFPV_BL_HEADER = {
    .target_magic = BOOTLOADER_TARGET_MAGIC,
    .isr_vector_base = VECT_TAB_BASE,
};

#endif /* USE_BRAINFPV_BOOTLOADER */

#if defined(CUSTOM_RESET_PIN)
/*
 * The RADIX 2 HD cannot reset itself with a plain NVIC system reset: the
 * external QSPI flash keeps its state across a core reset, so the bootloader
 * is re-entered in an inconsistent state. Pulling the dedicated reset pin low
 * resets the whole board instead.
 */
void CustomSystemReset(void)
{
    IO_t resetPin = IOGetByTag(IO_TAG(CUSTOM_RESET_PIN));
    IOInit(resetPin, OWNER_PULLDOWN, 0);
    IOConfigGPIO(resetPin, IOCFG_OUT_OD);

    __DSB(); // ensure buffered writes complete before the reset takes effect

    IOLo(resetPin);
    while (true) {
        __NOP(); // wait for the external reset to take the board down
    }
}
#endif /* CUSTOM_RESET_PIN */
