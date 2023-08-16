#!/bin/bash

echo "what's your name `whoami`"
read myname
[ -z "$myname" ] && myname=`whoami`
echo "your name is $myname"
