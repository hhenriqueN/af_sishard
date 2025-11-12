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
char *log_filename;
volatile sig_atomic_t received_signal = 0;


// Crie AQUI as funcoes que tratam os handlers dos sinais

void write_to_log(const char *message){
    int fd = open(log_filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("open log file");
        return;
    }

    // Escreve a mensagem no descritor de arquivo
    if (write(fd, message, strlen(message)) == -1) {
        perror("write to log file");
    }

    // Fecha o descritor de arquivo
    if (close(fd) == -1) {
        perror("close log file");
    }
}

void sigterm_handler(int signum){
    received_signal = signum;
    write_to_log("./q3 finalizado\n");
}


void sigint_handler(int signum){
    write_to_log("./q3 nao finalizado com SIGINT\n");
}
int main(int argc, char *argv[])
{
    // Registre AQUI seu handler para os sinais SIGINT e SIGTERM!

    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    log_filename = argv[1];

    if(signal(SIGTERM, sigterm_handler) == SIG_ERR){
        perror("erro sigterm");
        exit(EXIT_FAILURE);
    }

    if(signal(SIGINT, sigint_handler) == SIG_ERR){
        perror("erro sigint");
        exit(EXIT_FAILURE);
    }
    
    write_to_log("./q3 iniciado\n");

    // Abra aqui o arquivo, lembre-se se o arquivo de log nao existir, deve ser criado,
    // se ja existir deve escrever no final, variavel int fd eh global

    


    
    printf("Aplicação iniciada. PID: %d. Aguardando sinais...\n", getpid());
    while(received_signal == 0){
        pause();
    }

    printf("Sinal recebido %d", received_signal);

    signal(received_signal, SIG_DFL);
    raise(received_signal);

    return EXIT_SUCCESS;

    
}
