#!/bin/bash

#Funzioni Caricamento
Caricamento() {
    local pmax=11
    local p=1

    while true; do

        if [ $p -ge $pmax ]; then 
            break
        fi

        echo -n "["
        
        for ((i=0; i<$p; i++)); do
            echo -n "#"
        done

        for ((i=$p; i<$pmax-1; i++)); do
            echo -n "-"
        done
        
        echo -n "]"

        ((p++))

        sleep 0.1

        echo -ne "\r"
    done

    echo
}
#FINE

Black="\x1b[30m"
Bg_White="\x1b[47m"
NoStyle="\x1b[0m"
NoColor="\x1b[39m"
Clear="\033c"

echo "1 - Scritta Nera, Background Bianco, Testo Normale"
echo "2 - Caricamento"
read -p "Inserire scelta: " scelta

echo -e "$Clear"

if [ $scelta -eq 1 ]; then
    echo -e "${Black}${Bg_White}Ciao, sono un testo!"
elif [ $scelta -eq 2 ]; then
    Caricamento
fi

echo -e "$NoColor$NoStyle"

exit 0