// Leia o arquivo README.md ou README.html antes de iniciar este exercício!
// para compilar use:
// gcc q1.c -o q1 -pthread

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// SÓ PODE USAR A ESTRUTURA ABAIXO, NÃO PODE USAR VARIÁVEIS GLOBAIS
typedef struct  {
    sem_t *s1, *s2, *s3, *s4;
} t_arg;

void *thread1(void *_arg)
{
    t_arg *args = (t_arg*) _arg;

    sem_wait(args->s1);
    sem_wait(args->s2);
    printf("C\n");
    sem_post(args->s3);
    sem_post(args->s3);
    sem_post(args->s3);


    sem_wait(args->s3);
    sem_wait(args->s4);
    printf("E\n");

    return NULL;
}

void *thread2(void *_arg)
{
    t_arg *args = (t_arg*) _arg;

    sem_wait(args->s1);
    sem_wait(args->s2);
    printf("D\n");
    sem_post(args->s4);
    sem_post(args->s4);
    sem_post(args->s4);

    return NULL;
}

void *thread3(void *_arg)
{
    t_arg *args = (t_arg*) _arg;

    printf("A\n");
    sem_post(args->s1);
    sem_post(args->s1);

    sem_wait(args->s3);
    sem_wait(args->s4);
    printf("F\n");

    return NULL;
}

void *thread4(void *_arg)
{
    t_arg *args = (t_arg*) _arg;

    printf("B\n");
    sem_post(args->s2);
    sem_post(args->s2);

    sem_wait(args->s3);
    sem_wait(args->s4);
    printf("G\n");

    return NULL;
}

int main(int argc, char *argv[])
{

    pthread_t tids[4];
    void* threads[4] = {thread1, thread2, thread3, thread4};

    sem_t s1,s2,s3,s4;
    sem_init(&s1,0,0);
    sem_init(&s2,0,0);
    sem_init(&s3,0,0);
    sem_init(&s4,0,0);

    t_arg args = {
        .s1 = &s1,
        .s2 = &s2,
        .s3 = &s3,
        .s4 = &s4,
    };

    for (int i = 0; i < 4; i++)
    {
        pthread_create(&tids[i], NULL, threads[i], &args);
    }

    
    // Espere por TODAS as threads
    for (int i = 0; i < 4; i++)
    {
        pthread_join(tids[i], NULL);
    }
    
    return 0;
}
