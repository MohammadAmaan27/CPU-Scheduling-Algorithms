#include <stdio.h>
#include <conio.h>

void TA_Time(int n, int at[],int bt[], int ft[], int tat[])
{
    int i,delay;
    ft[0]=bt[0];
    for (i = 0; i < n ; i++) {
        if((i>0&&i<n)&&(at[i]>ft[i-1])) {
            delay=at[i]-ft[i-1];
        }
        else {
            delay=0;
        }
        tat[i]=ft[i]-at[i];
        if(i<n-1) {
            ft[i+1]=ft[i]+bt[i+1]+delay;
        }
    }
}
void W_Time(int n,int tat[], int bt[], int wt[])
{
    int i;
    wt[0] = 0;
    for (i = 1; i < n ; i++)
    {
        wt[i]=tat[i]-bt[i];
        if(wt[i]<0){
            wt[i]=0;
        }
    }
}
void Avg_Time(int processes[], int n, int at[], int bt[])
{
    int wt[n], tat[n], ft[n];
    int total_tat = 0, total_wt = 0;

    TA_Time(n, at, bt, ft, tat);
    W_Time(n, tat, bt, wt);

    printf("Processes\tArrival Time\tBurst Time\tFinish Time\tTurn Around Time\tWaiting Time \n");

    for (int i = 0 ; i < n ; i++)
    {
        total_tat += tat[i];
        total_wt += wt[i];
        
        printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i+1, at[i], bt[i], ft[i], tat[i], wt[i] );
    }

    printf("\nAverage Turn Around Time : %0.3f ms",(float)total_tat / (float)n);
    printf("\nAverage Waiting Time : %0.3f ms\n", (float)total_wt / (float)n);
}
int main () {
    printf("\nName : Mohammad Amaan");
    printf("\nE.No : A2305219572");
    printf("\nPrgm : First Come First Serve\n\n");

    int processes[] = {1, 2, 3,4};
    int n = sizeof processes / sizeof processes[0];
    int arrival_time[] = {0, 1, 3, 5};
    int burst_time[] = {10,6,2,4};
    Avg_Time(processes, n, arrival_time, burst_time);
    return 0;
}

