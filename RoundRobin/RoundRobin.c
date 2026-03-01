#include <stdio.h>

int main(){
    int n,tq,t=0,c=0,at[20],bt[20],rt[20],ct[20],wt[20],tat[20];
    float sumWT=0,sumTAT=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(c<n){
        int done=1;
        for(int i=0;i<n;i++){
            if(rt[i]>0 && at[i]<=t){
                done=0;
                if(rt[i]>tq){ t+=tq; rt[i]-=tq; }
                else{
                    t+=rt[i];
                    ct[i]=t;
                    rt[i]=0;
                    c++;
                }
            }
        }
        if(done) t++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        sumWT+=wt[i];
        sumTAT+=tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAvg TAT=%.2f\nAvg WT=%.2f\n",
           sumTAT/n,sumWT/n);
}
