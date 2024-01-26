.model small

    .stack 100h
    
    .data
    
    ;contatore
    cont db ?
    cont2 db 30h
    
    ;variabile dei caratteri
    car1 db ?

    ;variabile per indicare il numero di lettere maiuscole
    nmai db 30h
    
    ;sezione delle frasi da visualizzare
    dom1 db 'Numero di caratteri da inserire: ','$'
    dom2 db 'Numero di lettere inserite: ','$'
    dom3 db 'Inserisci una lettera dell alfabeto: ','$'
    ris1 db 'Non e stato inserito un numero...','$'
    ris2 db 'Il numero di lettere maiuscole e ', '$'
    acapo db ,13,10,'$'
    
    .code
    
         ;muovere il .data in DS
         mov ax, @data
         mov ds, ax
         
         ;visualizzare a schermo dom1
         inizio:
         mov ah, 09h
         mov dx, offset dom1
         int 21H
         
         ;far scrivere la lettera all utente
         mov ah, 01h
         int 21h
         
         mov cont, al
         
         ;visualizzare a schermo acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21H
         
         ;controlli per vedere se il numero inserito e' tra 0 e 9
         mov al, cont
         
         cmp al, '0'
         jge vero1
         jmp falso
         
             vero1:
             cmp al, '9'
             jle inizio2
             jmp falso
            
             falso:
             ;visualizzare a schermo ris1
             mov ah, 09h
             mov dx, offset ris1
             int 21h
            
             ;visualizzare a schermo acapo
             mov ah, 09h
             mov dx, offset acapo
             int 21H
         
             ;visualizzare a schermo acapo
             mov ah, 09h
             mov dx, offset acapo
             int 21H
            
             jmp inizio
         
         ;inizio ciclo del controllo delle lettere
         inizio2:
         
         mov al, cont2
         
         cmp al, cont
         jl ctrl
         jmp fine2
         
         ;controllo dei caratteri       
         ctrl:
         
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;visualizzare dom2
         mov ah, 09H
         mov dl, offset dom2
         int 21h
         
         ;visualizzare la variabile cont2
         mov ah, 02H
         mov dl, cont2
         int 21h
         
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;visualizzare dom3
         mov ah, 09H
         mov dx, offset dom3
         int 21h
         
         ;far scrivere la lettera all utente
         mov ah, 01h
         int 21h
         
         mov car1, al
         
         ;controllo per vedere se il carattere e minuscolo o maiuscolo
         mov al, car1
         
         cmp al, 'A'
         jge VERO21
         jmp Falso21
         
            ;sezione VERO21
            VERO21:
            cmp al, 'Z'
            jle VERO22
            jmp FALSO21
            
                ;sezione VERO22
                VERO22:
                inc nmai
                inc cont2
                jmp FINE
                
            
         
         falso21:
         inc cont2
         jmp fine            
         
         FINE:     
         nop
         
         jmp inizio2
         
         fine2:
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;visualizzare ris2    
         mov ah, 09H
         mov DX, offset ris2
         int 21h
         
         ;visualizzazione della variabile nmai
         mov ah, 02h
         mov dl, nmai
         int 21h
                      
         ;visualizzare acapo
         mov ah, 09h
         mov dx, offset acapo
         int 21h
         
         ;ridare il controllo al sistema operativo
         mov ah, 4ch
         int 21h
         
         end
         
         
         