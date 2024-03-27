#!/bin/bash

Clear="\033c"
Black="\x1b[30m"
NoStyle="\x1b[0m"
NoColor="\x1b[39m"
Bg_White="\x1b[47m"
risultato=0

echo -e "$Clear"

echo "Argomenti: $@"
echo " "

for ((i=1; i<=$#; i++)); do 
    ((risultato+=${!i}))
done

echo -e "${Black}${Bg_White}Il risultato della somma e' $risultato"

echo -e "$NoColor$NoStyle"

exit 0