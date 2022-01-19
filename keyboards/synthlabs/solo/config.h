/* Copyright 2022 Aaron Hong (Nostril)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x534E // "SN"
#define PRODUCT_ID      0x3031 // "01"
#define DEVICE_VER      0x0001
#define MANUFACTURER    Synth Labs
#define PRODUCT         Solo

#define ENCODER_RESOLUTION 4.5

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 7

/* Pins D0 and D2 are actually unused, but are included in DIRECT_PINS to fill space in the keyboard matrix to hold CW and CCW keycodes */
#define DIRECT_PINS { { C6, D6, B5, B4, D7, B6, D4 }, { D0, B7, D2 }, { F0, F7, F4, F5, F6, F1, C7 } }
#define UNUSED_PINS { D0, D1, D2, D3, D5, B0, B1 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 17

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */

#define FORCE_NKRO

/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 1

#define JOYSTICK_BUTTON_COUNT 8
#define JOYSTICK_AXES_COUNT 1
#define JOYSTICK_AXES_RESOLUTION 16
