#!/bin/bash

Clear="\033c"

echo -e "$Clear"

for((i=1; i<=$1; i++)); do
    for((j=1; j<=i; j++)); do
        echo -n "*"
    done
    echo " "
done

exit 0