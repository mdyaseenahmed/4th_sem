/*********************************************************************************************************************************************************************************
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i.
The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers
**********************************************************************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void Max_Meetings(int S[],int F[],int n)
{
	int i,j,count = 1;
	printf("\nFollowing Meetings Are Possible : ");
	i=0;
	printf("[%d,%d]",S[i],F[i]);
	for(j=1;j<n;j++)
	{
		if(S[j] >= F[i])
		{
			printf("[%d,%d]",S[j],F[j]);
			i = j;
			count++;
		}
	}
	printf("\nMaximum Possible Meetings Are : %d",count);
}

void insert_Sort(int S[],int F[],int n)
{
	int i,j;
	int key,key1;

	for(i=1;i<n;i++)
	{
		key = F[i];
		key1 = S[i];

		j = i-1;
		while(j>=0 && F[j]>key)
		{
			F[j+1] = F[j];
			S[j+1] = S[j];
			j = j-1;
		}
		F[j+1] = key;
		S[j+1] = key1;
	}
	Max_Meetings(S,F,n);
}

int main()
{
	int S[1000],F[1000];
	int n,i;
	printf("\nEnter The Number Of Meetings : ");
	scanf("%d",&n);
	printf("\nEnter Detail Of %d Meetings : \n",n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter Starting Time For %d Meeting : ",(i+1));
		scanf("%d",&S[i]);
		printf("\nEnter Ending Time For %d Meeting : ",(i+1));
		scanf("%d",&F[i]);
	}
	insert_Sort(S,F,n);
	return 0;
}
