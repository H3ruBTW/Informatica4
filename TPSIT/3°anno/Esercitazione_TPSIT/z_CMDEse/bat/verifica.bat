ECHO off 
rem creare una cartella “verifica” nel desktop
md verifica
cd verifica
rem creare dei file con almeno 4 estensioni diverse, nello specifico 4 file per ogni estensione 
TYPE NUL> 1.txt
TYPE NUL> 2.txt
TYPE NUL> 3.txt
TYPE NUL> 4.txt
TYPE NUL> 1.c
TYPE NUL> 2.c
TYPE NUL> 3.c
TYPE NUL> 4.c
TYPE NUL> 1.xls
TYPE NUL> 2.xls
TYPE NUL> 3.xls
TYPE NUL> 4.xls
TYPE NUL> 1.docx
TYPE NUL> 2.docx
TYPE NUL> 3.docx
TYPE NUL> 4.docx
pause
rem creare 2 cartelle che prendano il nome dall’estensione dei file
md excel
md word
rem spostare i file dalla cartella verifica alle dovute sottocartelle in base all’estensione, i file che rimarranno senza cartella andranno spostati in una nuova cartella “varie” 
md varie
pause
move *.xls excel
move *.docx word
move *.c varie
move *.txt varie
pause
rem visualizzare il contenuto di una cartella che prende il nome dall’estensione, dopodichè visualizzarlo ancora ma con un ordine diverso
dir excel
pause
dir excel /d
pause
rem visualizzare il contenuto della seconda cartella impostando un filtro di ricerca in base ai nomi che state utilizzando nella vostra verifica
cd word
dir | find ".docx" 
cd ..
pause
rem cambiare le estensioni dei file all’interno di “varie” in modo che tutti i file (tranne uno) della cartella abbiano la stessa estensione
cd varie
ren "1.txt" "11.c"
ren "2.txt" "22.c"
ren "3.txt" "33.c"
pause
rem eliminare il file con estensione diversa
del *.txt
pause
rem rinominare cartella “varie” con l’estensione dei file come fatto per le prime due cartelle
cd ..
ren "varie" "codiceC"
rem creare una cartella “tutti” che vada a contenere una copia di tutti i file delle varie cartelle
md tutti
copy excel tutti
copy word tutti
copy codiceC tutti
pause
ECHO on

