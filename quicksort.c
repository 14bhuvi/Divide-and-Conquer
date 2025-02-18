// Online C compiler to run C program online
#include <stdio.h>

int partition(int arr[],int p,int r)
{
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<=(r-1);j++)
    {
        if(arr[j]<=x)
        {
            i=i+1;
            if(i!=j)
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return (i+1);
}

void quicksort(int arr[],int p,int r)
{
    if (p<r)
    {
        int q=partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

int main()
{
    int arr[100],n,i;
    printf("Array size:");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<=n;i++)
    scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);   
    printf("Sorted array:\n");
    for(i=0;i<=n;i++)
    printf("%d\n",arr[i]);
}
