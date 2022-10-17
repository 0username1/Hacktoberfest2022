#include<stdio.h>
#include<stdbool.h> 
void Avg_wt(int processes[],int n,int bt[],int wt[],int quantum) // Finding Average Waiting Time
{
	int rem_bt[n]; // storing remaining burst times
	for (int i=0;i<n;i++) rem_bt[i] = bt[i];
	int t = 0; // Current time
	// Traverse the processes in round robin manner until all of them are not done.
	while (1)
	{
		bool done = true;
		for (int i=0;i<n;i++)
		{
			if (rem_bt[i] > 0)
			{
				done = false; // Process is still pending
				if (rem_bt[i] > quantum)
				{
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else
				{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true) // If all processes are done 
		break;
	}
    int total_wt = 0;
   for(int i=0;i<n;i++) total_wt = total_wt + wt[i];
   float Average_wt = (float)total_wt / (float)n;
   printf("Average waiting time =  %f\n",Average_wt);
   
}

void Avg_tat(int processes[],int n,int bt[],int wt[],int tat[]) // Finding Average Turn Around Time
{
    int total_tat = 0;
   for (int i = 0; i < n ; i++) tat[i] = bt[i] + wt[i];
   for(int i=0;i<n;i++) total_tat = total_tat + tat[i];
   float Average_tat = (float)total_tat / (float)n;
   printf("Average Turn Around time =  %f\n",Average_tat);
}

int main()
{
    int n,processes[50],bt[50],wt[50],tat[50],total_wt,total_tat,quantum;
    printf("Enter no.of processes: ");
    scanf("%d",&n);
    printf("Enter  processes: \n");
    for(int i=0;i<n;i++) scanf("%d", &processes[i]);
    printf("Enter their respective burst time : \n");
    for(int i=0;i<n;i++) scanf("%d", &bt[i]);
    printf("Enter time quantum for Round Robin : \n");
    scanf("%d",&quantum);
    Avg_wt(processes,n,bt,wt,quantum);
    Avg_tat(processes,n,bt,wt,tat);
    return 0;
}

