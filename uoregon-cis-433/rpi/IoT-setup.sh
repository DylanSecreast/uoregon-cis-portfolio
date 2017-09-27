#!/bin/bash

sudo -i

# GET & SET SUDO
apt-get install sudo -y
cp src/sudoers /etc/sudoers

# GET & SET GIT
apt-get install git -y
# TODO RSA key exchange
git clone git@github.com:DylanSecreast/IoT-Turtle-Rock.git

# WIFI NETWORK
cp src/wpa_supplicant.conf /etc/wpa_supplicant/wpa_supplicant.conf



# SET BOOT TO CMD
cp src/grub /etc/default/grub
update-grub
systemctl set-default multi-user.target



# reboot
