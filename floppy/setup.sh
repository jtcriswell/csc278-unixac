#!/bin/sh

#
# Script: setup.sh
#
# Description:
#	This script will set up the files needed as input for MP3.
#

#
# First create the directories and files.
#
mkdir -p /home/dir1
mkdir -p /home/dir2
touch /home/dir1/file
touch /home/dir2/file

#
# Next, set the owners, groups, and permissions of the directories and files
#
chown 20:101 /home
chown 10:101 /home/dir1
chown 30:101 /home/dir1/file
chmod 0100 /home
chmod 0000 /home/dir1
chmod 0000 /home/dir1/file

chown 10:50 /home/dir2
chown 30:50 /home/dir2/file
chmod 0100 /home
chmod 0000 /home/dir2
chmod 0000 /home/dir2/file

#
# Add entries to /etc/passwd and /etc/group to make output readable
#
echo "john:*:20:101:john:/:/bin/false" >> /etc/passwd
echo "jim:*:10:101:jim:/:/bin/false" >> /etc/passwd
echo "judy:*:30:101:judy:/:/bin/false" >> /etc/passwd

echo "faculty:x:50:" >> /etc/group
