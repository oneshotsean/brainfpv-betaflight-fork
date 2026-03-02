/*
 * BrainFPV HAL compatibility shim for Betaflight 2025.x (no ChibiOS).
 * Replaces the old ChibiOS hal.h with Betaflight-native includes.
 */

#ifndef BRAINFPV_HAL_H
#define BRAINFPV_HAL_H

#include "platform.h"
#include "drivers/io.h"
#include "drivers/time.h"

/*
 * ChibiOS binary semaphore replacement using a volatile flag.
 * Signal is set from ISR context; wait polls with a timeout.
 */
typedef volatile bool binary_semaphore_t;

static inline void chBSemObjectInit(binary_semaphore_t *sem, bool taken)
{
    *sem = !taken; // true = available
}

static inline void chSysLockFromISR(void) {}
static inline void chSysUnlockFromISR(void) {}

/* Signal from ISR: mark semaphore as available */
static inline void chBSemSignalI(binary_semaphore_t *sem)
{
    *sem = true;
}

/* Wait with timeout in ms; returns 0 on success, non-zero on timeout */
static inline int chBSemWaitTimeout(binary_semaphore_t *sem, uint32_t timeout_ms)
{
    uint32_t start = millis();
    while (!(*sem)) {
        if ((millis() - start) >= timeout_ms) {
            return 1; // MSG_TIMEOUT
        }
    }
    *sem = false;
    return 0; // MSG_OK
}

#define MSG_TIMEOUT 1
#define MSG_OK      0

/* Convert milliseconds to ticks (1:1 mapping since we use millis()) */
#define TIME_MS2I(ms) ((uint32_t)(ms))

#endif /* BRAINFPV_HAL_H */
