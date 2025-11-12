// Leia o arquivo README.md ou README.html antes de iniciar este exercício!
// para compilar use
// gcc  q4.c -g -o q4
// ./q4 caso1.txt caso2.txt
// valgrind --leak-check=yes ./q4 caso1.txt caso2.txt

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINHA 100

char *le_palavra(int fd) {

}
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Use:\n./q4 arquivo1.txt arquivo2.txt\n");
        return EXIT_FAILURE;
    }

    // Escreva a partir daqui o trecho de codigo que abre os dois arquivos de entrada
    // e cria o arquivo de saida ...
    


    return 0;
}