// Online C compiler to run C program online
#include <stdio.h>
int n;
int p[20];
void simpleunion(int i,int j)
{
    p[i]=j;
}
int simplefind(int i)
{
    int j;
    j=i;
    while(p[j]>0)
    j=p[j];
    return j;
}
int main()
{
    int i,j,r1,r2,ch;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    p[i]=-1;
    printf("\np[i]=\t");
    for(i=1;i<=n;i++)
    printf("%d\t",p[i]);
    printf("\nele[i]=");
    for(i=1;i<=n;i++)
    printf("%d\t",i);
    //for(i=1;i<=n;i++)
    //printf("%d\t",p[i]);
    do
    {
        printf("Enter your choice \n1)simple union\n 2)simple find\n3)exit\nhere:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter  tree root of two different sets\n");
            scanf("%d%d",&r1,&r2);
            if((p[r1]==-1) && (p[r2]==-1))
            simpleunion(r1,r2);
            else
            printf("invalid roots");
            break;
            case 2: printf("Enter elements to find the set:");
            scanf("%d",&i);
            j=simplefind(i);
            printf("\nenter elements %d is the set whose root is %d",i,j);
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
