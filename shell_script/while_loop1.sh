#!/bin/sh

INPUT_STRING=openfoam

while [ $INPUT_STRING != "bye" ]
do
    echo "Please input a string (bye by quit)"
    read INPUT_STRING
    echo "you typed is $INPUT_STRING"
done
