#include<stdio.h>
#define size 5
int stack[size],top=-1;
void push()
{
if(top==size-1)
printf("Stack Overflow\n");
else
{
top++;
printf("Enter value to push\n");
scanf("%d",&stack[top]);
}
return;
}
void pop()
{
if(top==-1)
{
printf("Stack Underflow\n");
}
else
{
printf("Deleted Element is %d\n",stack[top]);
top--;
}
return;
}
void display()
{
if(top==-1)
{
printf("Stack is empty\n");
return;
}
int i;
for(i=top;i>=0;i--)
printf("%d\n",stack[i]);
return;
}
void main()
{
int ch,n;
while(ch!=4)
{
printf(" 1 PUSH\n 2 POP\n 3 DISPLAY\n 4 EXIT\n");
printf("Enter you choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
break;
}
}
}
