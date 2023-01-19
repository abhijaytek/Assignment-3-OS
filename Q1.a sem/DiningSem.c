#include <stdio.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <sys/ipc.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <sys/shm.h>

sem_t chop[5];  //This depicts the 5 forks that a philospher has

int n[5] = {0,1,2,3,4}; //Indicates the number of a perticular philosopher
int func[5];  //Depicts whether they think or eat. 0 or 1 resp.

int a = 0; //To terminate the loop


void *dine (void *args){ //The created threads will execute this function simultaneously
	int *pnum = (int*) args;  //Passing the philosopher number
	while(1)
	{ 
    a++;
    if(a>1000)
    {
      break;
    }
		sleep(1); //Indicate Thinking for 1 second
		if(func[*pnum] == 0) //If the philisopher is thinking
	{
    if(*pnum==4)  //Last philosopher reverses the direction of picking the forks
    {
      sem_wait(&chop[(*pnum+1)%5]); 
      sem_wait(&chop[*pnum]);
		
      }//Picking up forks by wait signal
		else
    {
      sem_wait(&chop[*pnum]);
		  sem_wait(&chop[(*pnum+1)%5]);
    }
		func[*pnum] = 1;   //Eating state of a philosopher	
		printf("Philosopher number %d is eating !!\n",*pnum+1);  //Printing the eating number 
	}
		sleep(1); //Indicate Eating for 1 seconds
		if(func[*pnum] == 1)  //Checking if already eating
		{
		if(*pnum!=4)
    {
    sem_post(&chop[*pnum]);   //Putting down the left fork
		sem_post(&chop[(*pnum+1)%5]);
    }
      else
    {
      sem_post(&chop[(*pnum+1)%5]);
         //Putting down the right fork first
		  sem_post(&chop[*pnum]);
    }
    func[*pnum]=0; //Goes to thinking state		     
		printf("Philosopher %d has finished eating \n",*pnum+1);
			
	}
	printf("Philosopher %d is thinking \n",*pnum+1);
	}
}
int global = 0;
int main()
{
	pthread_t p[5]; // Creating 5 threads for 5 philosophers
	int i=0,j=0,k=0;
		func[0]=0;
    func[1]=0;
    func[2]=0;
    func[3]=0;
    func[4]=0;
    //Right now the function of all of the philosophers is set to 0 i.e. thinking
    
	printf("The process begins here .... \n");
	for(j = 0 ; j < 5 ; j++)
	{   global++;
	    if(global>1000)
		{
			break;
		}
	    sem_init(&chop[j],0,1);  // Here the semaphore is initialized as
		pthread_create(&p[j],NULL,dine,&n[j]);    //Creation of threads to let philosophers start eating 
		printf("PHILOSOPHER %d IS THINKING RIGHT NOW \n",j+1);  //Philospher is thinking here
	}
	for(k = 0; k < 5 ;k++){
		pthread_join(p[k],NULL);  //Joining the threads to eliminate the process
	}

	return 0;

}