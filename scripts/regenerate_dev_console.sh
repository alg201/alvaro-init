#!/bin/sh
#source https://www.kernel.org/doc/Documentation/admin-guide/devices.txt
sudo mknod initramfs/rootfs/dev/console c 5 1
echo "Created initramfs/rootfs/dev/console as character device for kernel"
sudo chmod -v 600 initramfs/rootfs/dev/console
sudo mknod initramfs/rootfs/dev/kmsg c 1 11
echo "Created initramfs/rootfs/dev/kmsg as character device for printk ring buffer"
sudo chmod -v 600 initramfs/rootfs/dev/kmsg
sudo mknod initramfs/rootfs/dev/null c 1 3
echo "Created initramfs/rootfs/dev/null as character device for null output"
sudo chmod -v 600 initramfs/rootfs/dev/null