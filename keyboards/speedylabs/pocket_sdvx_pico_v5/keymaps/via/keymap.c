// Copyright 2023 Nick G (@speedypotato)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *              ┌─────┐   
     *              │ ESC │
     * ┌──────────┬─┴─────┴─┬──────────┐
     * │   Q / W  │  ENTER  │  O / P   │
     * ├───────┬──┴────┬────┴──┬───────┤
     * │   D   │   F   │   J   │   K   │
     * ├───────┴───────┼───────┴───────┤
     * │       C       │       M       │
     * └───────────────┴───────────────┘
     */
    [0] = LAYOUT(
        KC_ESC,  KC_ENTER,
        KC_D,    KC_F,    KC_J,    KC_K,
        KC_C,    KC_M
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_Q, KC_W), ENCODER_CCW_CW(KC_O, KC_P)  }
};
#endif
