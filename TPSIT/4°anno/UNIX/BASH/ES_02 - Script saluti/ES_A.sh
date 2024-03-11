read -p "Inserisci il tuo nome: " nome
read -p "Inserisci l'orario: " orario

if [$orario > 7 && $orario < 21]
then
    echo "Buongiorno $nome, sono le $orario"
else
    echo "Buonasera $nome, sono le $orario"
fi

exit [0]