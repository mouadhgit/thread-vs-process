#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

pid_t pid_child;
int x = 1;

void parent_process(){
    printf("Parent ID: %d\t",getppid());
    
    x++;
    printf("Pa_x = %d\n",x);  // testing variabels access 
    
}

void child_process(){
    printf("child  ID: %d\t",getpid());
    printf("Ch_x = %d\n",x);  // testing variabels access 
    
}

int main(int argc,char *argv[]){
    
    switch (pid_child = fork()){
        case -1:
            perror("fork problem !");
            exit(2); // indicate incorrect usage
        break;

        case 0 : child_process(); break; 

        default: parent_process(); break;
    }

    return 0;
}