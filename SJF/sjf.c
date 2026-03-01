#include <stdio.h>

int main() {
    int n,t=0,c=0,at[20],bt[20],ct[20],wt[20],tat[20],done[20]={0};
    float sumWT=0,sumTAT=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    while(c<n){
        int idx=-1;
        for(int i=0;i<n;i++)
            if(!done[i] && at[i]<=t &&
               (idx==-1 || bt[i]<bt[idx]))
                idx=i;

        if(idx==-1){ t++; continue; }

        t+=bt[idx];
        ct[idx]=t;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];

        sumWT+=wt[idx];
        sumTAT+=tat[idx];

        done[idx]=1;
        c++;
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],wt[i],tat[i]);

    printf("\nAverage WT=%.2f\nAverage TAT=%.2f\n",
           sumWT/n,sumTAT/n);
}
