#!/bin/bash

Clear="\033c"
Black="\x1b[30m"
NoStyle="\x1b[0m"
NoColor="\x1b[39m"
Bg_White="\x1b[47m"

echo -e "$Clear"

echo "Argomenti: $@"
echo " "

if [ $1 = "add" ]; then
    risultato=$(($2 + $3))
    echo -e "${Black}${Bg_White}Il risultato della somma e' $risultato"
elif [ $1 = "sot" ]; then
    risultato=$(($2 - $3))
    echo -e "${Black}${Bg_White}Il risultato della sottrazione e' $risultato"
elif [ $1 = "mol" ]; then
    risultato=$(($2 * $3))
    echo -e "${Black}${Bg_White}Il risultato della moltiplicazione e' $risultato"
elif [ $1 = "div" ]; [ $3 -ne 0 ]; then
    risultato=$(($2 / $3))
    echo -e "${Black}${Bg_White}Il risultato della divisione e' $risultato"
elif [ $1 = "div" ]; [ $3 -eq 0 ]; then
    echo -e "${Black}${Bg_White}Non puoi dividere per 0"
fi

echo -e "$NoColor$NoStyle"

exit 0