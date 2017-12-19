#include<stdio.h>
void main()
{
int a[30],n,i,search,first,last,middle;
printf("enter the no. of integers\n");
scanf("%d",&n);
printf("enter %d integers\n",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("enter the element to be searched\n");
scanf("%d",&search);
first=0;
last=n-1;
middle=(first+last)/2;
while(first<=last)
{
if(a[middle]<search)
first = middle+1;
else if(a[middle]==search)
{
printf("element found at %d position\n",middle+1);
break;
}
else
last=middle-1;
middle=(first+last)/2;
}
}

