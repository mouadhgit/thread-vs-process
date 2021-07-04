#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 1;

void *routine(){
    sleep(2);
    printf("Th1_ID: %d\t",getpid());
    printf("x_Th1 = %d\n",x);        // testing variabels access
}

void *routine2(){
    x++;
    sleep(2);
    printf("Th2_ID: %d\t",getpid());
    printf("x_Th2 = %d\n",x);       // testing variabels access
}

int main(int argc, char *argv[]){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_join(t1,NULL);

    pthread_create(&t2, NULL, &routine2, NULL);
    pthread_join(t2,NULL);
     

   
    return 0;
}