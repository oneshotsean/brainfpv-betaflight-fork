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

#include <stdint.h>

#include "platform.h"

#include "drivers/dma.h"
#include "drivers/io.h"
#include "drivers/timer.h"
#include "timer_def.h"

#if defined(USE_BRAINFPV_RGB_LED_TIMER)
#include "brainfpv_rgb_led_timer.h"

/*
 * The status LED is a single RGB LED driven by three timer channels rather than
 * the plain on/off GPIOs Betaflight expects, so the channels are declared here
 * and consumed by brainfpv_rgb_led_timer.c.
 */
const timerHardware_t timerHardwareRgbLed[3] = {
    DEF_TIM(TIM15, CH1, PE5, TIMER_OUTPUT_INVERTED, 0, 0), // R
    DEF_TIM(TIM15, CH2, PE6, TIMER_OUTPUT_INVERTED, 0, 0), // G
    DEF_TIM(TIM14, CH1, PA7, TIMER_OUTPUT_INVERTED, 0, 0), // B
};
#endif
