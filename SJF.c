#include<stdio.h>

void sjf_nonpreemptive()
{
    int n,i,time=0,count=0,smallest;
    int at[20],bt[20],ct[20],wt[20],tat[20],done[20];
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        done[i]=0;
    }

    while(count<n)
    {
        smallest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0)
            {
                if(smallest==-1 || bt[i]<bt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
        {
            time++;
            continue;
        }

        time=time+bt[smallest];
        ct[smallest]=time;

        tat[smallest]=ct[smallest]-at[smallest];
        wt[smallest]=tat[smallest]-bt[smallest];

        done[smallest]=1;
        count++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage WT=%.2f",avgwt/n);
    printf("\nAverage TAT=%.2f\n",avgtat/n);
}

void sjf_preemptive()
{
    int n,i,time=0,count=0,smallest;
    int at[20],bt[20],rt[20],ct[20],wt[20],tat[20];
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(count<n)
    {
        smallest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
        {
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0)
        {
            count++;

            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];

            avgwt+=wt[smallest];
            avgtat+=tat[smallest];
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    printf("\nAverage WT=%.2f",avgwt/n);
    printf("\nAverage TAT=%.2f\n",avgtat/n);
}

int main()
{
    int ch;

    printf("1. SJF Non Preemptive\n");
    printf("2. SJF Preemptive\n");
    printf("Enter choice: ");
    scanf("%d",&ch);

    if(ch==1)
        sjf_nonpreemptive();
    else if(ch==2)
        sjf_preemptive();
    else
        printf("Invalid choice");

    return 0;
}