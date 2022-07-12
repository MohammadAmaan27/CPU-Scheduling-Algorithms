#include<stdio.h>
#define N 10
int m[N][8];
void swap(int *x,int *y);
void sort(int n);
void calc(int n);
float avg(int n, int v);

int main() {

    int num,i;
    float avgTAT, avgWT;
    printf("\nName : Mohammad Amaan");
    printf("\nE.No : A2305219572");
    printf("\nPrgm : Priority CPU Schedulling\n\n");

    printf("Enter the number of processes: ");
    scanf("%d",&num);
    printf("Enter Process Number: ");
    for(i=0;i<num;i++) {
        scanf("%d",&m[i][0]);
    }
    printf("Enter Arrival Time: ");
    for(i=0;i<num;i++) {
        scanf("%d",&m[i][1]);
    }
    printf("Enter Burst Time: ");
    for(i=0;i<num;i++) {
        scanf("%d",&m[i][2]);
    }
    printf("Enter Priority: ");
    for(i=0;i<num;i++) {
        scanf("%d",&m[i][6]);
    }
    sort(num); 
    calc(num); 
    printf("\nProcess\tArrival Time\tBurst Time\tFinish Time\tTurnaround Time\tWaiting Time\tPriority\n"); 
    for(i=0; i<num; i++) 
    { 
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",m[i][0],m[i][1],m[i][2],m[i][3],m[i][4],m[i][5],m[i][6]); 
    } 
    avgTAT=avg(num, 4);
    avgWT=avg(num, 5);
    printf("\nAverage TAT: %f \nAverage WT: %f",avgTAT, avgWT);
    return 0;
}
void calc(int num) {
    int pFT, cBT, val, i, j, k, hpv;
    m[0][3]= m[0][1]+m[0][2];       
    m[0][4]= m[0][3]-m[0][1];       
    m[0][5]= m[0][4]-m[0][2];       
    for(i=1;i<num;i++) {
        pFT= m[i-1][3];
        cBT= m[i][2]; 
        hpv= m[i][6];
        for(j=i;j<num;j++) {
             if(pFT >= m[j][1] && m[i][6] > m[j][6] && m[j][6] < hpv) 
            { 
                cBT = m[j][2]; 
                val = j; 
                hpv = m[j][6];
            } 
        } 
        m[val][3] = pFT + m[val][2]; 
        m[val][4] = m[val][3] - m[val][1]; 
        m[val][5] = m[val][4] - m[val][2]; 
        for(k=0; k<7; k++) 
        { 
            swap(&m[val][k], &m[i][k]); 
        } 
    
    }
}
void swap(int *a, int *b) {
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
float avg(int num, int val) {
    int sum=0;
    float average;
    for(int i=0;i<num;i++) {
        sum+=m[i][val];
    }
    average=(float)sum/(float)num;
    return average;
}
void sort(int num) {
    int i, j;
    for(i=0;i<num;i++) {
        for(j=i+1;j<num;j++) {
            if(m[i][1]>m[j][1]) {
                swap(&m[i][1], &m[j][1]);
            }
            if(m[i][1]==m[j][1]) {
                if(m[i][6]>m[i][7]) {
                    swap(&m[i][1], &m[j][1]);
                }
            }
        }
    }
}

