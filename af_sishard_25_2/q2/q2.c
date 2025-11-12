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
     
    printf("Processo pai cria os K=%d Processos Filhos para analisar o vetor com N=%d posicoes do Vetor A[]...\n",k,n);
    fflush(stdout);

    // Implemente aqui a criacao dos processos filhos



    printf("Processo pai esperando os filhos finalizarem...\n");
    fflush(stdout);
    // Implemente a parte do pai esperando o retorno dos processos filhos



    // coloque as respostas obtida pelo processo pai, substituindo o primeiro `%d` pela ordem do filho 
    // e o segundo `%d` pelo maior elemento no vetor.
    printf("P%d Maior=%d\n", 0, 0);

    free(A);


    return 0;
}