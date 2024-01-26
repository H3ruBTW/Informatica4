.model small

    .stack 100h
    
    .data
    
    ;contatore
    cont db 30h
    
    ;variabile dei caratteri
    car1 db ?

    ;variabile per indicare il numero di lettere maiuscole/minuscole
    nmai db 30h
    nmin db 30h
    
    ;sezione delle frasi da visualizzare
    dom1 db 'Massimo inseribile: 9 lettere','$'
    dom2 db 'Numero di lettere inserite: ','$'
    dom3 db 'Per uscire dal programma premere spazio',13,10,'$'
    dom4 db 'Inserisci una lettera dell alfabeto: ','$'
    ris1 db 'Il numero di lettere maiuscole e ','$'
    ris2 db 'Il numero di lettere minuscole e ', '$'
    acapo db ,13,10,'$'
    
    .code
    
        ;muovere il .data in DS
         mov ax, @data
         mov ds, ax
         
         ;visualizzare dom1
         mov ah, 09H
         mov dl, offset dom1
         int 21h
         
         ;visualizzare acapo
         inizio:
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;visualizzare dom2
         mov ah, 09H
         mov dl, offset dom2
         int 21h
         
         ;visualizzare la variabile cont
         mov ah, 02H
         mov dl, cont
         int 21h
         
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;visualizzare dom3
         mov ah, 09H
         mov dx, offset dom3
         int 21h
         
         ;visualizzare dom4
         mov ah, 09H
         mov dx, offset dom4
         int 21h
         
         ;far scrivere la lettera all utente
         mov ah, 01h
         int 21h
         
         mov car1, al
         
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;cmp per visuallizare se il carattere inserito e' una lettera
         mov al, car1
         
         cmp al, 'A'
         jge VERO1
         jmp FINE1
         
            ;sezione VERO1
            VERO1:
            cmp al, 'Z'
            jle VERO2
            jmp FALSO2
            
                ;sezione VERO2
                VERO2:
                inc nmai
                inc cont
                jmp FINE1
                
                ;sezione FALSO2
                FALSO2:
                cmp al, 'a'
                jge VERO3
                jmp FINE1
                
                    ;sezione VERO3
                    VERO3:
                    cmp al, 'z'
                    jle VERO4
                    jmp FINE1
                    
                        ;sezione VERO4
                        VERO4:
                        inc nmin
                        inc cont
                        jmp FINE1
         
         FINE1:     
         nop
         
         ;controllo per vedere se l'utente abbia inserito piu di 9 lettere
         mov al, cont
         
         cmp al, '9'
         jl inizio1
         jmp fine 
         
         ;controllo per vedere se l'utente vuole finire di eseguire il programma
         inizio1:
         cmp car1, ' '
         je fine
         jmp inizio
         
         fine:
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;visualizzare ris1    
         mov ah, 09H
         mov DX, offset ris1
         int 21h
         
         ;visualizzazione della variabile nmai
         mov ah, 02h
         mov dl, nmai
         int 21h
                      
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;visualizzare ris2
         mov ah, 09H
         mov DX, offset ris2
         int 21h
         
         ;visualizzazione della variabile nmin
         mov ah, 02h
         mov dl, nmin
         int 21h
                      
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;ridare il controllo al sistema operativo
         mov ah, 4ch
         int 21h
         
         end