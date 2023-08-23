#include<stdio.h>
struct jobseq{
    int num;
    int deadline;
    int profit;
};
void swap(struct jobseq j[],int i,int k)
{
    int temp=j[i].profit;
    j[i].profit=j[k].profit;
    j[k].profit=temp;
   temp=j[i].num;
    j[i].num=j[k].num;
    j[k].num=temp;
    temp=j[i].deadline;
    j[i].deadline=j[k].deadline;
    j[k].deadline=temp;
}
int partition(struct jobseq j[],int low,int high)
{
    int pivot=j[high].profit,i=low-1,k;

    for(k=low;k<=high-1;k++)
    {
        if(j[k].profit<pivot)
        {
            i++;
            swap(j,i,k);
        }
    }
	swap(j, i + 1, high);
	return (i+1);


}

void quicksort(struct jobseq j[],int low,int high)
{
    while(low<high)
    {
        int pi=partition(j,low,high);
        quicksort(j,low,pi-1);
        quicksort(j,pi+1,high);
    }
}

void main(){
    int n,i,count,value;
    printf("Enter the number of jobs\n");
    scanf("%d",&n);
    struct jobseq j[n];
    printf("Enter the job number with dedline and profit\n");

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&j[i].num,&j[i].deadline,&j[i].profit);
    }

    quicksort(j,0,n-1);

    int jobsequence[j[0].deadline];

    for(count=0;count<n;count++){
        jobsequence[count]=0;
    }
    i=0;
    for(count=0;count<n;count++)
    {
        value=j[i].deadline;

        while(value>=0)
        {
            if(jobsequence[value-1]==0)
            {
                jobsequence[value-1]=j[i].num;
                break;
            }
            value=value-1;
        }
        i++;
        
    }

    printf("Job sequence\n");
    for(i=0;i<j[0].deadline;i++)
    {
        printf("J%d-->",jobsequence[i]);
    }
}