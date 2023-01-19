#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main() {
   printf("\ncreated b\n");
   int shmid = shmget(12345, 1000 * sizeof(char), 0666);
  if(shmid<0){
    perror("\nErro crating shared memory segment\n");
    return 1;
  }
   char* array= (char*) shmat(shmid,NULL, 0);
   for(int j=0;j<10;j++){
     for(int i=0;i<5;i++)
     {for(int k=0;k<20;k++){
        printf("%c",array[i]);
       
     }}
     printf("\n");
   }
   shmdt(array);
   shmctl(shmid,IPC_RMID,NULL);
  
    return 0;
  
   }

    
   