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
chown 20:100 /home
chown 10:100 /home/dir1
chown 30:100 /home/dir1/file
chmod 0100 /home
chmod 0000 /home/dir1
chmod 0000 /home/dir1/file

chown 20:50 /home
chown 10:50 /home/dir2
chown 30:50 /home/dir2/file
chmod 0100 /home
chmod 0000 /home/dir2
chmod 0000 /home/dir2/file
