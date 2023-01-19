#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

 int main() {
   
   clock_t begin;
    clock_t finish;

    begin=clock();

   int shmid = shmget(12345, 1000 * sizeof(char), IPC_CREAT | 0666),max=4;
   if (shmid < 0) {
     perror("Error creating shared memory segment");
     return 1;
   }
char* arr= (char*) shmat(shmid,NULL, 0);

   for (int i = 0; i <1000; i++) {
     
     
     arr[i]='Z'+rand()%26+5;
     
     
   }
   for(int i=0;i<10;i++)
   {
     printf("%d\n",max+1);
       max+=5;
   }
    int c=shmdt(arr);
    if(c==-1){
     perror("shadt error");
      return 1;
      }
   finish=clock();
    printf("The time of execution is %ld",finish-begin);
    return 0;
  }