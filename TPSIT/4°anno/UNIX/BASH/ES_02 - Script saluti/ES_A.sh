#!/bin/bash

read -p "Inserisci il tuo nome: " nome
read -p "Inserisci l'orario: " orario

if [ $orario -lt 0 ] || [ $orario -gt 24 ]
then
    echo "Orario non disponibile"
elif [ $orario -ge 7 ] && [ $orario -lt 21 ]
then
    echo "Buongiorno $nome, sono le $orario"
else
    echo "Buonasera $nome, sono le $orario"
fi

exit 0