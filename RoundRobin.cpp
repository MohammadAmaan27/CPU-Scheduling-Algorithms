#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i,n,time,remain,temps=0,time_quantum;
    int wt=0,tat=0;
    printf("\nName : Mohammad Amaan");
    printf("\nE.No : A2305219572");
    printf("\nPrgm : Round-Robin CPU Scheduling\n\n");

    cout<<"Enter Number of process : ";
    cin>>n;

    remain=n;
    vector<int>at(n);
    vector<int>bt(n);
    vector<int>rt(n);
    cout<<"\nEnter Arrival Time : ";
    for(i=0;i<n;i++)
    {
        cin>>at[i];
    }
    cout<<"\nEnter Burst Time : ";
    for(i=0;i<n;i++)
    {
        cin>>bt[i];
        rt[i]=bt[i];
    }
    cout<<"\nEnter value of Time Slice : ";
    cin>>time_quantum;

    cout<<"\n\nProcess\t\tTurnAround Time\t\tWaiting Time\n\n";
    for(time=0,i=0;remain!=0;)
    {
        if(rt[i]<=time_quantum && rt[i]>0)
        {
            time += rt[i];
            rt[i]=0;
            temps=1;
        }
        else if(rt[i]>0)
        {
            rt[i] -= time_quantum;
            time += time_quantum;
        }
        if(rt[i]==0 && temps==1)
        {
            remain--;
            printf("%d\t\t%d\t\t\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
            cout<<endl;

            wt += time-at[i]-bt[i];
            tat += time-at[i];
            temps=0;
        }
        if(i == n-1)
            i=0;
        else if(at[i+1] <= time)
            i++;
        else
            i=0;
    }

    cout<<"Average Turn Around Time : "<<tat*1.0/n<<endl;;
    cout<<"Average Waiting Time : "<<wt*1.0/n<<endl;
    return 0;
}

