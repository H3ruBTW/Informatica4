#include <stdlib.h>  // exit
#include <stdio.h>   // printf
#include <unistd.h>  // execl

int main(int argc, char **argv) {

    int lamp=atoi(argv[2]), ms=atoi(argv[3]);

    printf("Colore: %s\n", argv[1]);
    printf("Numero di lampeggi: %s\n", argv[2]);
    printf("Millisecondi tra lampeggi: %s\n", argv[3]);

    for(int i=0; i<lamp; i++){

        printf("Led  %s acceso\n", argv[1]);
        usleep(ms*1000);
        printf("Led %s spento\n", argv[1]);
        usleep(ms*1000);
    }

    exit(10);
}