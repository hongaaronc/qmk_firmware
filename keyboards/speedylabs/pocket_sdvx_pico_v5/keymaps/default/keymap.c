// Copyright 2023 Nick G (@speedypotato)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *              ┌─────┐   
     *              │ JS6 │
     * ┌──────────┬─┴─────┴─┬──────────┐
     * │  AXIS0   │   JS8   │   AXIS1  │
     * ├───────┬──┴────┬────┴──┬───────┤
     * │  JS0  │  JS1  │  JS2  │  JS3  │
     * ├───────┴───────┼───────┴───────┤
     * │      JS4      │      JS5      │
     * └───────────────┴───────────────┘
     */
    [0] = LAYOUT(
        JS_6, JS_8,
        JS_0, JS_1, JS_2, JS_3,
        JS_4, JS_5
    )
};

#if defined(JOYSTICK_ENABLE) && defined(ENCODER_ENABLE)

int16_t pulses_per_revolution = 24;             // Depends on encoder model. Usually 18ppr or 24ppr for Bourns EC11s.
int16_t full_joystick_value = 32767;            // Equivalent to max value of int16. +full_joystick_value is +1.0 axis output. -full_joystick_value is -1.0 axis output.
uint8_t encoder_to_axis_map[NUM_ENCODERS] = {   // Mapping of the encoder to the joystick axis it controls. Can be reconfigured depending on usecase.
    [0] = 0, 
    [1] = 1
};
int16_t axis_position[JOYSTICK_AXIS_COUNT] = { 0, 0 };
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    uint8_t axis_idx = encoder_to_axis_map[index];

    axis_position[axis_idx] += (clockwise ? 2 : -2) * (full_joystick_value / pulses_per_revolution);  // +2 and -2 are used, since +1.0 and -1.0 axis output refers to positions at half of a full rotation
    joystick_set_axis(axis_idx, axis_position[axis_idx]);

    return true;
}

#endif
