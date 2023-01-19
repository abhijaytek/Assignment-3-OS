#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include<time.h>
#include<math.h>


int main()
{   clock_t t;
    clock_t s;
    t = clock();
    int i=0;
    char temp[1000];
    char abh[1000];
    char message[200];
    int temp2 = mkfifo("/temp/Abhijay",0777);  //Making a path for the fifo file
    int start = 1;
    int j;
    while (start<50)   //Iterating the 2D array
    {
        temp2 =open("/temp/Abhijay",O_RDONLY);//To read only
        int ran = read(temp2, temp ,100);
        
        strcpy(abh,temp);
          //Reading for a1
        printf("\nWe have recieved the strings from Program 1 %s\n",abh);
        if(ran==0)
        {
          printf("Error while recieving!!!");
        }
        close(temp2);  //Closing for a1
        int inrc = 5;
        if(inrc>5)
        {
          printf("Assigning error");
        }
        
        start = start + inrc;
        if(start==0)
        {
          printf("Error in incrementation");
          }
        printf("Highest Index has been returned %d!!\n",start);
        temp2 = open("/temp/Abhijay",O_WRONLY);  //Write only format
        ran = write(temp2,message,strlen(message)+1);
        close(temp2);
    }
    s = clock();
        int diff = t-s;
        printf("Total time taken for the strings to return is %d",-diff);
    return 0;

}