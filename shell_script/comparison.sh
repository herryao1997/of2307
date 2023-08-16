#!/bin/sh
echo "Please guess the magic number"
read X
echo $X | grep "[^0-9]" > /dev/null 2>&1
if [ "$?" -eq "0" ]; then
        echo "Sorry wanted a number"
else
        if [ "$X" -eq "6" ]; then
            echo "you got it"
        fi
fi
