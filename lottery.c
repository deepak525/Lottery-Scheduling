#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main()
{
	char process[5] = { 'A', 'B', 'C', 'D', 'E'},temp[10];
	int arrival[10];
	int brust[10],lottery[10],ticket[10][10];
	int i,j,p,max_tick,z;
	//Generate arrival time for each process randomly
	for(i=0;i<5;i++)
	{
		int num = (rand() + 1) % (15 + 1);
		arrival[i] = num;
	}
	
	//Generate brust time for each process randomly
	for(j=0;j<5;j++)
	{
		int num = (rand()%16) + 1;                     //random number b/w {1,15}
		brust[j] = num;
	}
	
	printf("Process   Arrival     Brust ");
	
	for(i=0;i<5;i++)
	{
		printf("\n  %c \t    %d    \t%d",process[i],arrival[i],brust[i]);
	}
	
	printf("\n\n:::::   Quantom time is 1 Sec   ::::: \n\n");
	
    //arrange them on the bases of there arrival time
	for (i= 0;i<5;i++)
	{
		for(j=0;j<4;j++) 
		{
			if (arrival[j] >= arrival[j + 1])
			{
				int temp2 = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp2;

                char temp1 = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp1;
			}
		}	
	}	
	
	
	printf("Process   Arrival     Brust ");
	
	for(i=0;i<5;i++)
	{
		printf("\n  %c \t    %d    \t%d",process[i],arrival[i],brust[i]);
	}
	
        printf("\n\n\nRequest  process    Lottery \t Tickets");
        p =0;
        max_tick = 0;
        //assign one or more lottery numbers to each process
	for(i=0;i<5;i++)
	{
		if(brust[i]>0)
		{
			lottery[i]=brust[i]/2;
			if ((lottery[i] == 0) && (brust[i] > 0))
                lottery[i] = 1;
               
			for (z = 0; z < lottery[i]; z++) {
                    ticket[i][z] = p++;
                        max_tick = p;
                    }
                    temp[i] = process[i];   
					
			printf("\n  %d\t   %c\t\t%d",brust[i],temp[i],lottery[i]);
			for(z=0;z<lottery[i];z++)
			{
				printf("\t::%d::",ticket[i][z]);
			   }   
		}
	}

	
	
	
}
