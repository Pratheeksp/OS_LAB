#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int pid,bt,at,ct,tt,wt;
} pro;

pro P[50], R[50];
int pn=0,rn=0,cputime=0,startRq=0;

void swap(pro *a,pro *b){
    pro temp = *a;
    *a = *b;
    *b = temp;
}

void makeRQ(){
    for(int i=0;i<pn;i++){
        if(P[i].at == cputime){
            R[rn] = P[i];
            rn++; 
        }
    }
}

void sortBT(pro a[],int start,int end){
    pro temp;
    for(int i=start;i<end-1;i++){
        for(int j=i+1;j<end;j++){
            if(a[i].bt > a[j].bt)
                swap(&a[i],&a[j]);

            else if(a[i].bt == a[j].bt && i!=j && a[i].bt != 0){
                if(a[i].at > a[j].at)
                    swap(&a[i],&a[j]);
                else if(a[i].at == a[i].at)
                    if(a[i].pid > a[j].pid)
                        swap(&a[i],&a[j]);
            }
        }
    }
}

void preemtive(pro a[]){
    if(a[startRq].bt >= 0)
        a[startRq].bt--;
    
    if(a[startRq].bt == 0){
        a[startRq].ct = cputime+1;
        startRq++;
    }
}

void non_pre(pro a[]){
    for(int i=startRq;i<rn;i++){
        a[i].ct = a[i].bt + cputime;
        cputime += a[i].bt;
        a[i].bt = 0;
    }
    startRq = rn;
}
 
int main(){
    int maxAT = 0;
    int totalTT=0,totalWT=0;
    float avgTT=0,avgWT=0;

    printf("Enter the number of process: ");
    scanf("%d",&pn);
    
    for(int i=0;i<pn;i++){
        P[i].pid = i+1;
        printf("Enter the arrival time of Process %d: ",i+1);
        scanf("%d",&P[i].at);

        printf("Enter the Busrt time of Process %d: ",i+1);
        scanf("%d",&P[i].bt);

        if(P[i].at > maxAT)
            maxAT = P[i].at;

        P[i].ct = 0;
        P[i].tt = 0;
        P[i].wt = 0;
    }

    do{
        makeRQ();
        sortBT(R,0,rn);

        if(rn != pn && rn!=0)
            preemtive(R);

        else if(rn == pn)
            non_pre(R);

        cputime++;
    }while(startRq < pn || cputime <= maxAT);

    for(int i=0;i<rn-1;i++)
	{
		for(int j=i+1;j<rn;j++)
		{
			if(R[i].pid > R[j].pid)
			{
				swap(&R[i],&R[j]);
			}
		}
	}

    for(int i=0;i<pn;i++){
        P[i].ct = R[i].ct;
		P[i].tt=P[i].ct-P[i].at;
		P[i].wt=P[i].tt-P[i].bt;
		totalTT+=P[i].tt;
		totalWT+=P[i].wt;
    }

    avgTT=(float)totalTT/pn;
	avgWT=(float)totalWT/pn;

    printf("Displaying Processes and associated Details:\n");
	printf("------------------------------------------------\n");
	printf("PID\tAT\tBT\tCT\tTT\tWT");
	printf("\n------------------------------------------------\n");
	for(int i=0;i<pn;i++)
	{
		printf("%i \t%i \t%i \t%i \t%i \t%i\n",P[i].pid,P[i].at,P[i].bt,P[i].ct,P[i].tt,P[i].wt);
	}

    printf("\nAverage TurnAround Time : %.2f",avgTT);
	printf("\nAverage Waiting time: %.2f\n",avgWT);
}
