#include<stdio.h>

void swap(int* x, int* y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void sort1(int process[], int n, int at[], int bt[]) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n; i++) 
    {
        if (at[i] == 0) {
            swap(&bt[0], &bt[i]);
            swap(&at[0], &at[i]);
            swap(&process[0], &process[i]);
        }
    }
    for (i = 1; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (bt[j] < bt[min_idx]) 
                min_idx = j; 
  
        swap(&bt[min_idx], &bt[i]);
        swap(&process[min_idx], &process[i]);
        swap(&at[min_idx], &at[i]);
    } 
}
void sort2(int process[], int n, int at[], int bt[]) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (bt[j] < bt[min_idx]) 
                min_idx = j; 
  
        swap(&bt[min_idx], &bt[i]);
        swap(&process[min_idx], &process[i]);
        swap(&at[min_idx], &at[i]);
    } 
}
int check (int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            return 0;
        }
    }
    return 1;
}

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
        
        printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i], at[i], bt[i], ft[i], tat[i], wt[i] );
    }

    printf("\nAverage Turn Around Time : %0.3f ms",(float)total_tat / (float)n);
    printf("\nAverage Waiting Time : %0.3f ms\n", (float)total_wt / (float)n);
}    

int main () {
    printf("\nName : Mohammad Amaan");
    printf("\nE.No : A2305219572");
    printf("\nPrgm : Shortest job First\n\n");

    int processes[] = {1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];
    // int arrival_time[] = { 0, 1, 3, 5};
    // int burst_time[] = { 10, 6, 2, 4};
    
    int arrival_time[] = { 0, 0, 0, 0};
    int burst_time[] = { 10, 6, 2, 4};

    // int arrival_time[] = { 2, 0, 4, 5};
    // int burst_time[] = { 3, 4, 2, 4};

    if (check(n, arrival_time) == 0) {
        sort1(processes, n, arrival_time, burst_time);
    }
    else 
        sort2(processes, n, arrival_time, burst_time);

    Avg_Time(processes, n, arrival_time, burst_time);
    return 0;

}

