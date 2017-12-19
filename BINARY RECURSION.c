#include<stdio.h>
int bs(int a[],int key,int low,int high)
{
int mid;
if(low>high)
return -1;
mid=(low+high)/2;
if(key==a[mid])
return mid+1;
else if(key>a[mid])
return bs(a,key,mid+1,high);
else
return bs(a,key,low,mid-1);
}
void main()
{
int a[10],key,i,pos,n;
printf("Enter the array size\n");
scanf("%d",&n);
printf("Enter the array elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the element to be found\n");
scanf("%d",&key);
pos=bs(a,key,0,n-1);
printf("Element is found in %d position",pos);
printf("\n");
}

