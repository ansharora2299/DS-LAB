#include<stdio.h>
void toh(int n,char A,char B,char C)
{
if(n==1)
printf("Move disc from %c to %c\n",A,C);
else
{
toh(n-1,A,C,B);
printf("Move disc from %c to %c\n",A,C);
toh(n-1,B,A,C);
}
return;
}
void main()
{
int n;
char A='A',B='B',C='C';
printf("Enter the number of disc\n");
scanf("%d",&n);
toh(n,A,B,C);
}
