#!/bin/bash
hour=`date +%I`
min=`date +%M`
ampm=`date +%p`
echo "$hour : $min $ampm"
if [ $ampm="AM" ]
then
echo "Good Morning"
else
if [ $hour -eq 12 -o $hour -lt 4]
then
echo "Good afternoon"
elif [ $hour -ge 4 -a $hour -le 8 ]
then
echo "Good evening"
fi
fi
