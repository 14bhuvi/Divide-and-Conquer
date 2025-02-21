// Online C compiler to run C program online
#include <stdio.h>

void maxheapify(int a[],int i,int n)
{
    int l,r,largest,temp;
    l=2*i;
    r=2*i+1;
    if(l<=n && a[l]>a[i])
    largest=l;
    else
    largest=i;
    if(i!=largest)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        maxheapify(a,largest,n);
    }
}
void display(int a[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    printf("The sorted form is:%d\t",a[i]);
}
void createmaxheap(int a[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    maxheapify(a,i,n);
}
void heapsort(int a[],int n)
{
    int temp;
    createmaxheap(a,n);
    for(int i=n;i>=2;i++)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        maxheapify(a,1,i-1);
    }
}
void main()
{
    int a[10],n,x,i;
    printf("Enter size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        printf("array elements are:\n");
    }
    for(i=1;i<=n;i++)
    {
        printf("%d",a[i]);
        heapsort(a,n);
    }
    printf("sorted elements are:");
    display(a,n);
}
