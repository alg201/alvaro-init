# initramfs
When linux firstly executes needs to generate a small filesystem to properly boot the rest of the system, this is called `ramfs` or by it's literal translation `RAM FileSystem` and to make this work from the beginning there exists initramfs that generates the initial filesystem on the ram.

## How does files work?
Usually data is red from the device (a hard drive, ssd or else) and cached on memory and kept around if there is a futher use of them, but instantly mark as freeable when the Virtual Memory (VM) needs the memory. When is data written, the memory is marked as freeable when the memory is written to the device but kept around until VM makes reallocs.

## How does affect to ramfs?
Ramfs has no backing store (the origin of the data, the device) so, when files are written into ramfs allocates dentries and page cache but never is marked as freeable just because theres nowhere to write.

Ramfs only could be accessed by root because you can fill the memory until it's completly full and the VM is not able to free that memory.

## What is rootfs?
Rootfs is an special instance of ramfs that is always present on linux systems. The kernel uses nullfs (an empty immutable filesystem) as the true root of the Virtual File System, then mutable rootfs is mounted on top of it. 

## What is the initramfs?
Linux kernel (from 2.6 onwards) contains a gzipped `cpio` format archive which is extracted into rootfs when the kernel boots up. After that, the kernel checks to see if rootfs contains a file `init` on it. If so, it executes it as PID 1. And this is responsible to make the whole system to start properly. This includes locating and mounting the real root partition.

## Why we need the /dev/console at the beggining?
`/dev/console` is a special dispositive that represents the console of the system.
In order to work properly, there should be a place where inputs and outputs should be happening.
Imagine a case that something is wrong, a console should be able to print it out.
If this fails there are some workarounds to this.
- Can try to continue the boot if isn't a problem, just log what happen into throught writting onto `/dev/kmsg` or `/dev/log` and use `/dev/null` to the rest of the work.
- If this also fails, you can consider to trigger a kernel panic. 


# Reference
- https://www.kernel.org/doc/html/latest/filesystems/ramfs-rootfs-initramfs.html