#!/bin/sh
sudo mknod initramfs/rootfs/dev/console c 5 1
sudo chmod 600 initramfs/rootfs/dev/console