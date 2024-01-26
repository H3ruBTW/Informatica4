@echo off
rem comunicazione con l'utente
echo Costruzione dei file richiesti...
echo;
rem fermare il programma prima di eseguire le istruzioni
pause
rem costruzione delle directory
md casa
md esami
md varie
rem costruzione file
type nul> casa/ricorda.txt
rem spostamento in un altra directory
cd casa
rem costruzione delle directory
md spese
rem costruzione file
type nul> spese/luglio.xls
type nul> spese/giugno.xls
type nul> spese/agosto.xls
rem costruzione delle directory
md entrate
rem spostamento in un altra directory
cd ../esami
rem costruzione file
type nul> elenco.doc
type nul> voti.xls
rem spostamento in un altra directory
cd ../esami
rem costruzione delle directory
md analisi
rem costruzione file
type nul> analisi/tesina.doc
type nul> analisi/testi.doc
rem costruzione delle directory
md fisica
rem costruzione file
type nul> fisica/tesina.doc
type nul> fisica/testi.doc
rem spostamento in un altra directory
cd ../
rem costruzione file
type nul> varie/telefono.xls
type nul> varie/amici.txt
echo Spostamento completato