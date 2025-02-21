// Online C compiler to run C program online
#include <stdio.h>
int n,p[20];
void weightedunion(int i,int j)
{
    int temp;
    temp=p[i]+p[j];
    if(p[i]>=p[j])
    {
        p[j]=i;
        p[i]=temp;
    }
    else
    {
        p[i]=j;
        p[j]=temp;
    }
}
int collapsefind(int i)
{
    int r,s;
    r=i;
    while(p[r]>0)
    {
        r=p[r];
    }
    while(i!=r)
    {
        s=p[i];
        p[i]=r;
        i=s;
    }
    return r;
}
int main()
{
    int u,v,k,i,ch;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    p[i]=-1;
    printf("\np[i]=\t");
    for(i=1;i<=n;i++)
    printf("%d\t",p[i]);
    printf("\nele[i]=");
    for(i=1;i<=n;i++)
    printf("%d\t",i);
    do
    {
        printf("Enter your choice \n1)weighted union\n 2)collapse find\n3)exit\nhere:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter  tree root of two different sets\n");
            scanf("%d%d",&u,&v);
            //if((p[r1]==-1) && (p[r2]==-1))
            weightedunion(u,v);
            //else
            //printf("invalid roots");
            break;
            case 2: printf("Enter elements to find the set:");
            scanf("%d",&i);
            k=collapsefind(i);
            printf("\nenter elements %d is the set whose root is %d",i,k);
            break;
            case 3: printf("\n thank you");
            break;
        }
    printf("\np[i]=\t");
    for(i=1;i<=n;i++)
    printf("%d\t",p[i]);
    printf("\nele[i]=");
    for(i=1;i<=n;i++)
    printf("%d\t",i);
    }while(ch>=1 && ch<=3);
    return 0;
}
