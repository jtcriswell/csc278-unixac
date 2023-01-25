# csc278-unixac
Files for the CSC278/478 Unix Access Control Project

This repository contains skeleton source code and helper scripts for the Unix
ACcess Control Project.

Students will need the OpenWRT hard disk image. The getfiles.sh script will download and unpack these files from the course web page. In case students want to get the files by hand, the information is below:

o The OpenWRT image that we use for our virtual machine is at http://www.cs.rochester.edu/courses/256/fall2015/QDGL/openwrt-15.05-x86-generic-combined-ext4.img

The runqemu.sh script will launch QEMU with the needed command-line options. With no arguments, it will boot the OpenWRT disk image with the default kernel residing on the image. Alternatively, students can provide the pathname to a Linux kernel, and runqemu.sh will boot that kernel instead.

You should boot QEMU with the bzImage kernel provided in the repository.  This kernel has MS-DOS file system and floppy disk device support enabled.  To boot this kernel, use:

o sh runqemu.sh ./bzImage

Files in the floppy directory will appear as a hard disk within the virtual machine. To mount the hard disk, use the command:

o mount -t msdos /dev/sdb1 /mnt

The contents of hard disk should appear in /mnt.

Be sure to use the following command to unmount the hard disk device before shutting down the virtual machine with the poweroff command:

o umount /mnt

o poweroff

Students should note that the virtual machine does not include a compiler; this is to keep the disk image small.  Students should compile their code on the host machine; they can do this by changing into the floppy directory and typing make:

o cd floppy

o make

