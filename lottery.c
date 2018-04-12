#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void main()
{
	int n,i,j,k,temp=65,flag=0;
	char process[20];
	int brust[20],priority[20],pos;
	int time=0,quantom=1,tbt=0;
	int z=0,lottery[20],ticket[20][20],q=0;
	printf("Enter Number Of Process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		process[i] = temp;
		temp+=1;
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter The Brust Time For Process %c: ",process[i]);
		scanf("%d",&brust[i]);
		printf("Enter The Priority For Process %c(b/w 1 to %d): ",process[i],n);
		scanf("%d",&priority[i]);
	}
	
	//sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
 
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
 
        temp=brust[i];
        brust[i]=brust[pos];
        brust[pos]=temp;
 
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
        
        if(brust[i]<0)
		{
			flag = 1;
		}
    }
    
    if(flag==1)
    {
    	printf("\n\n:::  Invalid Time Entered ::: \n");
    	exit(0);
	}
    
    printf("\n |Priority |  Process   |  Brust |");
	
	for(i=0;i<n;i++)
	{
		printf("\n |   %d \t   |    %c    \t|   %d    |",priority[i],process[i],brust[i]);
		tbt = tbt + brust[i];
	}
	
	printf("\n\n:::::::::   Quantom time is 1 Sec   ::::::::: \n\n");
	
	//assign one or more lottery numbers to each process
	int p=1,m_ticket=0;
	printf("\n\n\nPriority  process  Brust  Lottery   Tickets");
	for(i=0;i<n;i++)
	{
		lottery[i] = (brust[i]/quantom) + (n-priority[i]);
		for (z=0;z<lottery[i];z++) 
		{
            ticket[i][z] = p++;
            m_ticket = p;
        }
      			
		printf("\n  %d\t    %c\t    %d \t    %d\t",priority[i],process[i],brust[i],lottery[i]);
		for(z=0;z<lottery[i];z++)
		{
			printf("   ::%d::",ticket[i][z]);
		}   
	}
	
	while(tbt>0)
	{
	
	int winner = (rand()%m_ticket-1)+ 1;
    for(i =0;i<n;i++)
        for(z=0;z<lottery[i];z++)
            if(ticket[i][z]==winner)
                q=i;
                
    printf("\n\n-------------------------------------");
    printf("<<<<  Winner: %d   >>>>",winner);
    printf("-------------------------------------\n\n");
	
	if ((brust[q] > 0))  
	{
        brust[q] -= quantom;
        
        if (brust[q] > 0) 
		{
            time += quantom;
        } 
		else 
		{
            time += (brust[q] + quantom);
        }
		
		if (brust[q] < 0) {
                brust[q] = 0;
            }
	    printf("\n\nProcess That Are Running Is: %c",process[q]);
	    printf("\n(Total Time << Remaining Brust time << process ):  ( %d  <<  %d  <<  %c )\n\n",time,brust[q],process[q]);
    }

     tbt-=quantom;
 }
	
}
