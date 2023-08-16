#!/bin/sh

while read input_text
do
    if [ "$input_text" != "q" ]
    then
        case $input_text in
		    fixedValue)     echo BoundaryContiditions ;;
            ddt)            echo TimeSchemes ;;
            div)            echo SpaceSchemes;;
            *)              echo Unknown $input_text  ;;    
        esac
    else
        echo "Script completed successfully."
        exit 0
    fi
done 
