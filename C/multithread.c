#include <stdio.h>
#include <pthread.h>

#define THREAD_NUM 5

void * workerThreadFunc(void *tid){
    char buf[35];
    long * myID = (long *) tid;
    printf("Hello world this is thread no. %ld\n", *myID);
}

int main(void){
    pthread_t tid[THREAD_NUM];
    pthread_t * pthreads[] = {&tid[0],&tid[1],&tid[2],&tid[3],&tid[4],&tid[5]};
    for (int i = 0; i < THREAD_NUM; i++){
        pthread_create(pthreads[i],NULL,workerThreadFunc,(void *)pthreads[i]);
    }

    pthread_exit(NULL);
    return 0;
}

