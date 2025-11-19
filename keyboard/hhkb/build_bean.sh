#!/usr/bin/env bash

# Prerequisite packages
git submodule update --init
sudo dnf install avr-gcc avr-libc libusb1-devel automake

# NOTES TO SELF
# -- Used to only work with dfu-programmer 0.6.2 (does NOT work with 0.7.x)
# -- Now works with latest compiled from source (c204739)
cd ~/repos
git clone git@github.com:dfu-programmer/dfu-programmer.git
cd dfu-programmer
./bootstrap.sh
./configure
make
sudo make install

cd ~/repos/bean_keyboard/keyboard/hhkb
make clean
make KEYMAP=bean
sudo make KEYMAP=bean dfu
