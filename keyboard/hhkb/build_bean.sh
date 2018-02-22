#!/usr/bin/env bash

# NOTES TO SELF
# -- Only works with dfu-programmer 0.6.2 (does NOT work with 0.7.x)
# -- requires avr-gcc and avr-libc
make clean
make KEYMAP=bean
sudo make KEYMAP=bean dfu
