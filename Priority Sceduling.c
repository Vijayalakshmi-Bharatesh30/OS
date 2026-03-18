#include<stdio.h>

int main(){
int n,choice;
printf("enter the number of processes: ");
scanf("%d",&n);

int at[n],bt[n],pr[n],ct[n],tat[n],wt[n],rt[n],done[n];

for(int i=0;i<n;i++){
    printf("P%d AT BT Priority: ",i+1);
    scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    rt[i]=bt[i];
    done[i]=0;
}

printf("1.Non-preemptive  2.Preemptive\nEnter choice: ");
scanf("%d",&choice);

int time=0,completed=0;

if(choice==1)
{
    while(completed<n){
        int idx=-1,high=9999;

        for(int i=0;i<n;i++){
            if(at[i]<=time && done[i]==0 && pr[i]<high){
                high=pr[i];
                idx=i;
            }
        }

        if(idx!=-1){
            time+=bt[idx];

            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];

            done[idx]=1;
            completed++;
        }
        else
            time++;
    }
}
else if(choice==2)
{
    while(completed<n){
        int idx=-1,high=9999;

        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && pr[i]<high){
                high=pr[i];
                idx=i;
            }
        }

        if(idx!=-1){
            rt[idx]--;
            time++;

            if(rt[idx]==0){
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];

                completed++;
            }
        }
        else
            time++;
    }
}

float avg_wt=0,avg_tat=0;

printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

for(int i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    avg_wt+=wt[i];
    avg_tat+=tat[i];
}

printf("\nAverage WT = %.2f",avg_wt/n);
printf("\nAverage TAT = %.2f",avg_tat/n);

return 0;
}
