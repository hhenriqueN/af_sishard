// Leia o arquivo README.md ou README.html antes de iniciar este exercício!
// para compilar use:
// gcc q2.c -o q2
// para realizar testes com valgrind use:
// valgrind --leak-check=yes ./q2 < in4.txt

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h> 



int find_max(int *arr, int start, int end){

    int max_val = INT_MIN;

    for(int i = start; i < end; i++){
        if (arr[i] > max_val){
            max_val = arr[i];
        }
    }

    return max_val;
}

int main()
{
    int n, k, status;

    //quantidade de processos
    scanf("%d", &k);

    //tamanho do array
    scanf("%d", &n);

    int *A = malloc(n * sizeof(int));

    //le os elementos do vetor
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
     
    int segment_size = n / k;
    printf("Processo pai cria os K=%d Processos Filhos para analisar o vetor com N=%d posicoes do Vetor A[]...\n",k,n);
    fflush(stdout);

    // Implemente aqui a criacao dos processos filhos


    int pipes[k][2];
    for(int i = 0; i < k; i++){
        

        if(pipe(pipes[i]) == -1){
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        pit_t pid = fork();

        if(pid == -1){
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if(pid == 0){
            close(pipes[i][0]);

            int start_index = i * segment_size;
            int end_index = (i == NUM_CHILDREN - 1) ? n : (i + 1) * segment_size;

            int child_max = find_max(A, start_index, end_index);
            write(pipes[i][1], &child_max, sizeof(int)); 
            close(pipes[i][1]); 
            exit(EXIT_SUCCESS);
        }

        else{

            close(pipes[i][1]);
        }
    }

    int overall_max = INT_MIN;
    for(int i = 0; i < k; i++){
        int child_max_val;
        read(pipes[i][0], &child_max_val, sizeof(int)); 
        close(pipes[i][0]);

        if(child_max_val > overall_max){
            overall_max = child_max_val;
        }

        wait(NULL);

    }

    printf("Maior numero do vetor: %d\n", overall_max);



    printf("Processo pai esperando os filhos finalizarem...\n");
    fflush(stdout);
    // Implemente a parte do pai esperando o retorno dos processos filhos



    // coloque as respostas obtida pelo processo pai, substituindo o primeiro `%d` pela ordem do filho 
    // e o segundo `%d` pelo maior elemento no vetor.
    printf("P%d Maior=%d\n", 0, 0);

    free(A);


    return 0;
}