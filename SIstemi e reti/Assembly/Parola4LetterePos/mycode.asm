;scelta del modello
.model SMALL
     
    ;scelta dello stack 
    .stack 100H
        
        ;segmento data
        .data
        
        ;variabili
        car1 db ?
        car2 db ?
        car3 db ?
        car4 db ?
        
        pos1 db 31h
        pos2 db 32h
        pos3 db 33h
        pos4 db 34h
        
        ;stringhe
        dom db 'Scrivi un carattere: ', '$'
        ris db 'La parola inserita e: ', '$'
        ris2 db 'Posizione:            ','$' 
        acapo db ,13,10, '$'
        
        ;segmento code
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
            
                ;cmp per vedere se la lettera inserita e' maggiore di 41H (A)
                mov al, car1
                                                    
                cmp al, 'A'
                jge vero1
                jmp falso1
                
                    ;sezione vero1
                    ;cmp per vedere se la lettera inserita e' minore di 5AH (Z)
                    vero1:
                    cmp al, 'Z'
                    jle fine
                    jmp falso2
                    
                    ;sezione falso1
                    ;rendere la variabile car1 uguale a space (20H)
                    falso1:
                    mov car1, 20H
                    jmp fine
                    
                        ;sezione falso2
                        ;cmp per vedere se la lettera inserita e' maggiore di 61H (a)
                        falso2:
                        cmp al, 'a'
                        jge vero3
                        jmp falso3
                        
                            ;sezione vero3
                            ;cmp per vedere se la lettera inserita e' minore di 7AH (z)
                            vero3:
                            cmp al, 'z'
                            jle fine
                            jmp falso4
                            
                            ;sezione falso 3
                            ;rendere la variabile car1 uguale a space (20H)
                            falso3:
                            mov car1, 20H
                            jmp fine
                            
                                ;sezione falso 4
                                ;rendere la variabile car1 uguale a space (20H)
                                falso4:
                                mov car1, 20H
                                jmp fine
                                
                        
            fine:
            nop
                         
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
            
                ;stampa della stringa ris
                mov ah, 09h
                mov dx, offset ris
                int 21H
                
                ;visualizzazione delle variabili car1, car2, car3, car4
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
                
                ;stampa della stringa acapo
                mov ah, 09h
                mov dx, offset acapo
                int 21H
                
                ;stampa della stringa ris2
                mov ah, 09h
                mov dx, offset ris2
                int 21h
                
                ;visualizzazione delle variabili pos1, pos2, pos3, pos4
                mov ah, 02h
                mov dl, pos1
                int 21H
                
                mov ah, 02h
                mov dl, pos2
                int 21H
                
                mov ah, 02h
                mov dl, pos3
                int 21H
                
                mov ah, 02h
                mov dl, pos4
                int 21H
                
                ;ridare il controllo al sistema operativo
                mov ah, 4ch
                int 21h
                
                end