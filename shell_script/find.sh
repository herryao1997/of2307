#!/bin/bash
. ~/OpenFOAM/OpenFOAM-v2306/etc/bashrc    
FILES=`find $FOAM_SRC -type f -iname "*singlephase*"`
for i in $FILES
do
    echo $i | grep incompressible
done

