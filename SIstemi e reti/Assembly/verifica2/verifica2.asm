.model small

    .stack 100h
    
    .data
    
    ;variabili
    cusc db ?
        
    ;stringhe
    dom1 db 'Inserire il carattere con cui uscire dal programma: ','$'
    dom2 db 'Inserire una frase',13,10,'$' 
    
    acapo db ,13,10, '$'
    
        .code
            
            ;spostare il .data in ds
            mov ax, @data
            mov ds, ax
            
            ;visualizzare la stringa dom2
            mov ah, 09h
            mov dx, offset dom1
            int 21h
            
            ;lettura di un carattere speciale che finisce in carusc
            mov ah, 01h
            int 21h
            
            mov cusc, al
            
            ;visualizzare la stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21h
            
            ;visualizzare la stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21h 
            
                    ;visualizzare la stringa dom2
                    mov ah, 09h
                    mov dx, offset dom2
                    int 21h
                    
                    ;visualizzare la stringa acapo
                    mov ah, 09h
                    mov dx, offset acapo
                    int 21h 
            
                    ciclo:
                    ;lettura da tastiera di un carattere
                    mov ah, 01h
                    int 21h
                    
                    cmp al, 0Dh
                    je vero
                    jmp falso
                    
                    vero:
                    mov ah, 09h
                    mov dx, offset acapo
                    int 21h
                    
                    falso:
                    ;cmp per controllare se stato inserito il carattere speciale
                    cmp al, cusc
                    je fine
                    jmp ciclo
            
            fine:
            ;ridare il controllo al sistema operativo
            mov ah, 4ch
            int 21h
            
            end
            
           