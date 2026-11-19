#!/bin/sh

qemu-system-x86_64 \
    -m 512M \
    -kernel kernels/vmlinuz \
    -initrd initramfs/initramfs.cpio.gz \
    -append "console=ttyS0 rdinit=/init" \
    -nographic 