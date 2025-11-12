// Leia os arquivos README.html ou readme.md antes de iniciar este exercício!
// Para compilar use:
// gcc q3.c -g -o q3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

// descritor do arquivo global
int fd;

int loop_infinito()
{
    while(1)
    {
        printf("pid(%d) - Processo executando ...\n", getpid());
        fflush(stdout);
        sleep(1);
    }
}

// Crie AQUI as funcoes que tratam os handlers dos sinais

int main(int argc, char *argv[])
{
    // Registre AQUI seu handler para os sinais SIGINT e SIGTERM!

    
    
    

    // Abra aqui o arquivo, lembre-se se o arquivo de log nao existir, deve ser criado,
    // se ja existir deve escrever no final, variavel int fd eh global



    
    loop_infinito();

    return 0;
}
