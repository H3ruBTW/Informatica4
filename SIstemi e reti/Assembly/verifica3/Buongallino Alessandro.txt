.model small

    .stack 100h
    
    .data
    
    ;variabili
    cusc db ?
    somma db 30h 
        
    ;stringhe
    dom1 db 'Inserire un numero: ','$'
    dom2 db 'Inserire il carattere con cui uscire dal programma: ','$'
    dom3 db 'Inserire una frase',13,10,'$' 
    
    acapo db ,13,10, '$' 
    
        .code
        
            ;spostare il .data in ds
            mov ax, @data
            mov ds, ax
            
            ;visualizzare la stringa dom1
            mov ah, 09h
            mov dx, offset dom1
            int 21h
            
            ;lettura del carattere
            mov ah, 01h 
            int 21h
            
            sub al, 30h
            
            add somma, al
            
            ;visualizzare la stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21h 
            
            ;visualizzare la stringa dom1
            mov ah, 09h
            mov dx, offset dom1
            int 21h
            
            ;lettura del carattere
            mov ah, 01h 
            int 21h
            
            sub al, 30h
            
            add somma, al 
            
            ;visualizzare la stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21h
            
            ;visualizzare la stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21h
            
                ;cmp per vedere se la somma dei due numeri inseriti e' compreso tra 0 e 9
                mov al, somma
                
                cmp al, '0' 
                jge vero1
                jmp fine
                
                    vero1:
                    ;sezione vero1
                    cmp al, '9'
                    jle vero2
                    jmp fine
                    
                        vero2:
                        ;visualizzare la stringa dom2
                        mov ah, 09h
                        mov dx, offset dom2
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
                        mov dx, offset dom3
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
                        
                        
                        
                        
                        