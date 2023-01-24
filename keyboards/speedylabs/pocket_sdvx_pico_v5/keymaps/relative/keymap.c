// Copyright 2023 Nick G (@speedypotato)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *              ┌─────┐   
     *              │ JS6 │
     * ┌──────────┬─┴─────┴─┬──────────┐
     * │  AXIS0   │   JS8   │   AXIS2  │
     * ├───────┬──┴────┬────┴──┬───────┤
     * │  JS0  │  JS1  │  JS2  │  JS3  │
     * ├───────┴───────┼───────┴───────┤
     * │      JS4      │      JS5      │
     * └───────────────┴───────────────┘
     */
    [0] = LAYOUT(
        JS_6, JS_8,
        JS_3, JS_2, JS_0, JS_1,
        JS_4, JS_5
    )
};

#if defined(JOYSTICK_ENABLE) && defined(ENCODER_ENABLE)

int16_t axis_position[JOYSTICK_AXIS_COUNT] = { 0, 0, 0, 0 };
int16_t sensitivity = 3;                        // 1 sensitivity is equivalent to 1 full turn of the encoder traversing the whole range of the axis. Due to having decay, higher sensitivity is recommended.
int16_t pulses_per_revolution = 24;             // Depends on encoder model. Usually 18ppr or 24ppr for Bourns EC11s.
int16_t full_joystick_value = 32767;            // Equivalent to max value of int16. +full_joystick_value is +1.0 axis output. -full_joystick_value is -1.0 axis output.
uint8_t encoder_to_axis_map[NUM_ENCODERS] = {   // Mapping of the encoder to the joystick axis it controls. Can be reconfigured depending on usecase.
    [0] = 0, 
    [1] = 3
};
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL,
    [2] = JOYSTICK_AXIS_VIRTUAL,
    [3] = JOYSTICK_AXIS_VIRTUAL
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    uint8_t axis_idx = encoder_to_axis_map[index];

    // Check for overflow/underflow, and if so, cap the joystick value at the max value instead of looping around
    int16_t delta_position = sensitivity * (clockwise ? 2 : -2) * (full_joystick_value / pulses_per_revolution);
    int16_t new_position = axis_position[axis_idx] + delta_position;
    if (clockwise && axis_position[axis_idx] > 0 && new_position < 0) {
        axis_position[axis_idx] = full_joystick_value;
    } else if (!clockwise && axis_position[axis_idx] < 0 && new_position > 0) {
        axis_position[axis_idx] = -full_joystick_value;
    } else {
        axis_position[axis_idx] = new_position;
    }

    joystick_set_axis(axis_idx, axis_position[axis_idx]);
    return true;
}

uint16_t axis_last_time[JOYSTICK_AXIS_COUNT] = { 0, 0, 0, 0 };
uint16_t decay_rate = 100;  // Apply this amount of recentering per MS elapsed since the last encoder update. This starts off as a gentle decay, but compounds quickly if no input is detected.

void housekeeping_task_user(void) {
    uint16_t current_time = timer_read();
   
    for (uint8_t i=0; i< JOYSTICK_AXIS_COUNT; i++) {
        uint16_t elapsed_time = current_time - axis_last_time[i];
        uint16_t decay = decay_rate * elapsed_time;

        if (axis_position[i] > 0) {
            axis_position[i] -= decay;

            // Don't decay past center
            if (axis_position[i] < 0) {
                axis_position[i] = 0;
            }
        } else if (axis_position[i] < 0) {
            axis_position[i] += decay;

            // Don't decay past center
            if (axis_position[i] > 0) {
                axis_position[i] = 0;
            }
        }

        joystick_set_axis(i, axis_position[i]);

        axis_last_time[i] = timer_read();
    }
}

#endif
