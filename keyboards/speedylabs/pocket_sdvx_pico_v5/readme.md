# Speedy Labs Pocket SDVX Pico V5

![Pocket SDVX](https://i0.wp.com/www.speedylabs.us/wp-content/uploads/2021/10/20220909_172612-scaled.jpg?fit=640%2C480)

The Pocket SDVX Pico V5 by Speedy Labs is a miniature controller for the game [SOUND VOLTEX](https://p.eagate.573.jp/game/sdvx/vi/index.html).

* Keyboard Maintainer: [speedypotato](https://github.com/speedypotato)
* Hardware Supported: [Pocket SDVX Pico v5](https://www.speedylabs.us/product/pocket-sdvx-pico-assembled/)
* Hardware Designer: [speedypotato](https://github.com/speedypotato)
* Hardware Availability: Available from [speedylabs.us](https://www.speedylabs.us/product/pocket-sdvx-pico-assembled/)


Make example for this gamepad (after setting up your build environment):

    make speedylabs/pocket_sdvx_pico_v5:default

Flashing example for this keyboard:

    make speedylabs/pocket_sdvx_pico_v5:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Enter the bootloader in 3 ways:

* **Bootmagic reset / Physical reset button**: Hold down either button on the back, and plug in the gamepad
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
