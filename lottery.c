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
	int brust[10];
	int ticket[10][10];
	int lottery[10] = {0,0,0,0,0,0,0,0,0,0};
	int i,j,z,p=0,max_tick,q=0,pss=0;
	
	//Generate arrival time for each process randomly
	for(i=0;i<5;i++)
	{
		int num = (rand()%5)+ 1;
		arrival[i] = num;
	}
	
	//Generate brust time for each process randomly
	for(j=0;j<5;j++)
	{
		int num = (rand()%5) + 1;                     //random number b/w {1,15}
		brust[j] = num;
	}
	
	printf("Process   Arrival     Brust ");
	
	for(i=0;i<5;i++)
	{
		printf("\n  %c \t    %d    \t%d",process[i],arrival[i],brust[i]);
	}
	
	printf("\n\n:::::   Quantom time is 1 Sec   ::::: \n\n");
	
	int time = 0,quantom=1;
	
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
                 
   while((brust[0]+brust[1]+brust[2]+brust[3]+brust[4])>0){
   
   	printf("\n\n\nBrust  process    Lottery \t Tickets");
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
		
		else if ((brust[i] > 0) && (time < arrival[i]))
		{
			temp[i] = process[p];
            lottery[i] = brust[i] / 2;
            if ((lottery[i] == 0) && (brust[i] > 0))
                lottery[i] = 1;
                
            for (z = 0; z < lottery[i]; z++){
                ticket[i][z] = p++;
                max_tick=p;
            }
            
            if (brust[i] > 0) {
                time += quantom;
                } else {
                    time += (brust[i] + quantom);
                }
                
            printf("\n  %d\t   %c\t\t%d",brust[i],temp[i],lottery[i]);
			for(z=0;z<lottery[i];z++)
			{
				printf("\t::%d::",ticket[i][z]);
			}       
		}
	}
	
	
	int winner = (rand()%max_tick-1)+ 1;;
    for(i =0;i<10;i++)
        for(z=0;z<lottery[i];z++)
            if(ticket[i][z]==winner)
                q=i;
    printf("\n\n-------------------------------------");
    printf("<<<<  Winner: %d   >>>>",winner);
    printf("-------------------------------------\n\n");
	
	
	if ((brust[q] > 0))  
	{
        temp[q] = process[q];
        brust[q] -= quantom;
        
        if (brust[q] > 0) {
            time += quantom;
        } else {
            time += (brust[q] + quantom);
            }
		
		if (brust[q] < 0) {
                brust[q] = 0;
            }
	    printf("Process That Are Running Is: %c",temp[q]);
	    printf("\n(Total Time << Remaining Brust time << process ):  ( %d  <<  %d  <<  %c )\n\n",time,brust[q],temp[q]);
	
    }
    
    else if ((brust[q] > 0) && (time < arrival[q])) {
        temp[q] = process[p];
        if (brust[q] > 0) {
                time += quantom;
        } else {
                time += (brust[q] + quantom);
        }
        
        printf("Process That Are Runnring Is: %c",temp[q]);
	    printf("\n%d \t%d \t%c\n\n",time,brust[q],temp[q]);
    }
    pss++;
}

     printf("\n\n::::::::  Total Time Taken by CPU to Run All The Process: %d Sec  ::::::::\n\n\n",time);
     
}
