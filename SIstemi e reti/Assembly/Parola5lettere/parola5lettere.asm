.model SMALL

    .stack 100H
    
        .data
        
        ;variabili
        car1 db ?
        car2 db ?
        car3 db ?
        car4 db ?
        car5 db ?
        
        ;stringhe
        dom db 'Scrivi un carattere: ', '$'
        ris db 'La parola inserita e: ', '$' 
        acapo db ,13,10, '$'
        
        .code
            
            ;muovere ,data in DS
            mov ax, @data
            mov ds, ax
            
            ;stampa della stringa dom
            mov ah, 09h
            mov dx, offset dom
            int 21H
            
            ;inserimento da tastiera della variabile car1
            mov ah, 01H
            int 21H
            
            mov car1, al
            
            ;stampa della stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21H 
            
            ;stampa della stringa dom
            mov ah, 09h
            mov dx, offset dom
            int 21H
            
            ;inserimento da tastiera della variabile car2
            mov ah, 01H
            int 21H
            
            mov car2, al
            
            ;stampa della stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21H
            
            ;stampa della stringa dom
            mov ah, 09h
            mov dx, offset dom
            int 21H
            
            ;inserimento da tastiera della variabile car3
            mov ah, 01H
            int 21H
            
            mov car3, al
            
            ;stampa della stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21H
            
            ;stampa della stringa dom
            mov ah, 09h
            mov dx, offset dom
            int 21H
            
            ;inserimento da tastiera della variabile car4
            mov ah, 01H
            int 21H
            
            mov car4, al
            
            ;stampa della stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21H
            
            ;stampa della stringa dom
            mov ah, 09h
            mov dx, offset dom
            int 21H
            
            ;inserimento da tastiera della variabile car5
            mov ah, 01H
            int 21H
            
            mov car5, al
            
            ;stampa della stringa acapo
            mov ah, 09h
            mov dx, offset acapo
            int 21H
            
                ;stampa della stringa ris
                mov ah, 09h
                mov dx, offset ris
                int 21H
                
                ;visualizzazione delle variabili
                mov ah, 02h
                mov dl, car1
                int 21H
                
                mov ah, 02h
                mov dl, car2
                int 21H
                
                mov ah, 02h
                mov dl, car3
                int 21H
                
                mov ah, 02h
                mov dl, car4
                int 21H
                
                mov ah, 02h
                mov dl, car5
                int 21H
                
                ;ridare il controllo al sistema operativo
                mov ah, 4ch
                int 21h
                
                end
                
             