#include<stdio.h>
void gcd(int a,int b)
{
if(a==b)
printf("GCD id %d\n",a);
else if(a>b)
gcd(a-b,b);
else
gcd(a,b-a);
}
void main()
{
int a,b;
printf("Enter two numbers\n");
scanf("%d %d",&a,&b);
gcd(a,b);
}
