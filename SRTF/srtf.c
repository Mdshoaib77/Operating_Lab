#include <stdio.h>

int main() {
    int n,t=0,c=0,at[20],bt[20],rt[20],ct[20],wt[20],tat[20];
    float sumWT=0,sumTAT=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(c<n){
        int idx=-1;

        for(int i=0;i<n;i++)
            if(at[i]<=t && rt[i]>0 &&
              (idx==-1 || rt[i]<rt[idx]))
                idx=i;

        if(idx==-1){ t++; continue; }

        rt[idx]--;
        t++;

        if(rt[idx]==0){
            ct[idx]=t;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            sumWT+=wt[idx];
            sumTAT+=tat[idx];
            c++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    printf("\nAvg WT=%.2f\nAvg TAT=%.2f\n",
           sumWT/n,sumTAT/n);
}
