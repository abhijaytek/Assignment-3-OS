#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main()
{   
    
    int i=0,a=1,j;
    char message1[1000];
    char message2[1000];
    int temp = mkfifo("/temp/Abhijay",0777);  //Making a fifo path
    if(temp<0)
    {
      printf("Error");
    }
    char conv[100][1000]={0};  // Having a 2D charecter array
    for(i = 1; i<51 ; i++)
    { 
        strcpy(conv[i],"abc");
    }
  
    int start = 1;
    
    while (start<50)   //Iterating the 2D array
    { 
          
        temp = open("/temp/Abhijay", O_WRONLY);

        strcat(conv[start],"\n");  //Adding linespace
        if(strlen(conv[start])==0)
        {
          printf("Error while comparing");
        }
        j=start+1;

        while(j<=start+4)
        {
          strcat(conv[start],conv[j]);
            if(j==start)
            {
              j= start;
              //sleep(1)
            }
            strcat(conv[start],"\n");
            if(strlen(conv[start])==0)
            {
              printf("Error");
            }
            j++;
        }
       
        printf("Message Has Been Sent to Program 2 \n");
        if(j==0)
        { 
          int flag1 = 0;
        }
        //To pass the array through the pipe

        int ran = write(temp,conv[start], strlen(message1)+1);

        close(temp); //Closing for Writing
      
        temp = open("/temp/Abhijay",O_RDONLY);  //For Read Only type

        ran = read(temp,message2,sizeof(message2));//Reading the file

        if(ran==0)
        {
          printf("Error!!!");
        }
        start = atoi(message2);   //Converting to Integer
        printf("We have the index from the second program %d \n",start);  //Printing Index
        close(temp);
        }
        
return 0;
}