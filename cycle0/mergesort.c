#include<stdio.h>
/*
14-09-2022
Merge Sort
*/
void main()
{
    int a[10],b[10],c[10],m,n,i,j,k=0;
    printf("Enter the number of elements in array A : ");
    scanf("%d",&m);
    printf("Enter the  elements in array A in acending order: ");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    printf("Enter the number of elements in array B : ");
    scanf("%d",&n);
    printf("Enter the elements in array B in ascending order:");
    for(j=0;j<n;j++)
    scanf("%d",&b[j]);
    i=0,j=0;
    printf("The merged array is:  ");
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    for(i;i<m;i++)
    c[k]=a[i];
    for(j;j<n;j++)
    c[k]=b[j];

    for(i=0;i<k+1;i++)
    printf("%d ",c[i]);

}