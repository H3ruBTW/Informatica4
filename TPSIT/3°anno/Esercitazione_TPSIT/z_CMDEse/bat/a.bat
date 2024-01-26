@echo off
echo Creazione dei file...
pause
md test1
md test2
type nul>test1\ciao.txt
type nul>test1\ciao1.txt
type nul>test1\ciao2.txt
type nul>test1\ciao3.txt
copy test1\*.txt test2
del test1\*.txt
echo Operazione completata
pause

