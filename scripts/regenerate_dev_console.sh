#!/bin/sh
sudo mknod initramfs/rootfs/dev/console c 5 1
echo "Created initramfs/rootfs/dev/console as terminal for kernel"
sudo chmod -v 600 initramfs/rootfs/dev/console