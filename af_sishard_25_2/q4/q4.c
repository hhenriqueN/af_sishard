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

    
    char buffer[MAX_LINHA];
    char *string = malloc(MAX_LINHA * sizeof(char));
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if(bytes_read == -1){
        perror("erro ao ler")
    }
    else if(bytes_read == 0){
        return string;
    }
    else{

        for(int i = 0; i <= bytes_read; i++){

            if(buffer[bytes_read] != '\0');
            string[i] = buffer[bytes_read];
        }
    }

    return string;
    



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
    int fd1 = open(argv[0], O_WRONLY | O_CREAT, 0700);
    int fd2 = open(argv[1], O_WRONLY | O_CREAT, 0700);

    char *string_arq1 = le_palavra(fd1);
    char *string_arq2 = le_palavra(fd1);

    int saida = open("saida.txt", O_WRONLY | O_CREAT, 0700);

    for(int i = 0; i < argc; i+=2){

        char buffer[];
        ssize_t bytes_written = write(saida, buffer, strlen(buffer)); 
        if (bytes_written == -1) {
            perror("Error writing to file");
            close(fd); // Close before exiting
            return 1;
    }
    }
    


    return 0;
}