#!/bin/bash
set -e
echo "$1 db.dat c"
$1 db.dat c

echo ""
echo "$1 db.dat s 1 zed zed@zedshaw.com"
$1 db.dat s 1 zed zed@zedshaw.com
echo "$1 db.dat s 2 frank frank@zedshaw.com"
$1 db.dat s 2 frank frank@zedshaw.com
echo "$1 db.dat s 3 joe joe@zedshaw.com"
$1 db.dat s 3 joe joe@zedshaw.com
echo "$1 db.dat l"
$1 db.dat l

echo ""
echo "$1 db.dat f @"
$1 db.dat f @
echo "$1 db.dat f joe"
$1 db.dat f joe

echo ""
echo "$1 db.dat d 3"
$1 db.dat d 3
echo "$1 db.dat l"
$1 db.dat l

echo ""
echo "$1 db.dat g 2"
$1 db.dat g 2
rm db.dat
