#!/bin/sh

while read input_text
do
    case $input_text in
		fixedValue)     echo BoundaryContiditions ;;
        ddt)            echo TimeSchemes ;;
        div)            echo SpaceSchemes;;
        *)              echo Unknown $input_text  ;;    
    esac         
done < schemes.txt
