#include <stdio.h>

int main(){

    struct horario{
        int hora;
        int minuto;
        int segundo;
    };

    struct horario agora, *depois;
    depois = &agora;

    depois->hora = 20;
    depois->minuto = 20;
    depois->segundo = 20;

/*
(*depois).hora = 20;
(*depois).minuto = 20;
(*depois).segundo = 20;
*/

    printf("%i:%i:%i \n", agora.hora, agora.minuto, agora.segundo);

    return 0;
}