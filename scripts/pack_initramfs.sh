#!/bin/sh
allcwd=$(pwd)
cwd=$(pwd | awk -F'/' '{printf $NF}')

if [ "$cwd" = "scripts" ]; then
    cd ..
fi

cd initramfs/rootfs

if [ $? != 0 ]; then
    return 1
fi

sudo sh -c 'find . -print0 | cpio --null -o --format=newc --owner=0:0 | gzip -9 > ../initramfs.cpio.gz'
#find . -print0 : prints all the files separated by null character.
# cpio --null -o --format=newc --owner=0:0 generates an archive from the input on the format newc (used tipically on filesystems) with ownership of root (id 0) and reads separates each file with the null character.
# gzip -9 generates the zip file on the slowest compression method but that occupies the less, then redirects the generated gzip archive to the file.
echo "Packed initramfs succesfully"

cd $allcwd