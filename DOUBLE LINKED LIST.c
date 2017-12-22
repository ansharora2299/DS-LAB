#include <stdio.h>
#include <malloc.h>
struct node{
int info;
struct node *l;
struct node *r;
};
typedef struct node* NODE;
NODE start=NULL;
void inb(int item)
{
NODE NN;
NN = (NODE)malloc(sizeof(struct node));
NN->info = item;
NN->l=NULL;
if(start==NULL)
NN->r=NULL;
else{
NN->r=start;
start->l=NN;
}
start=NN;
return;
}
void ine(int item)
{
NODE NN;
NODE temp=NULL;
NN = (NODE)malloc(sizeof(struct node));
NN->info = item;
NN->r=NULL;
if(start==NULL)
{
NN->l=NULL;
start=NN;
return;
}
else
{
temp=start;
while(temp->r!=NULL)
temp=temp->r;
temp->r=NN;
NN->l=temp;
return;
}
}
void inpos(int item,int pos)
{
int c=1;
NODE NN;
NN = (NODE)malloc(sizeof(struct node));
NN->info = item;
if(start==NULL&&pos==1)
{
NN->l=NN->r=NULL;
start=NN;
return;
}
else if(start==NULL&&pos>1)
{
printf("INVALID POSITION\n");
return;
}
else if(start!=NULL&&pos==1)
{
NN->l=NULL;
NN->r=start;
start=NN;
return;
}
NODE temp=start;
while(temp!=NULL&&c!=(pos-1))
{
temp=temp->r;
c++;
}
if(temp==NULL)
{
printf("INVALID POSITION\n");
return;
}
NN->r=temp->r;
temp->r->l=NN;
temp->r=NN;
NN->l=temp;
}
void dlb()
{
NODE temp=NULL;
if(start==NULL)
{
printf("DLL is Empty\n");
return;
}
else if(start->r==NULL)
{
free(start);
start=NULL;
return;
}
else
{
temp=start;
printf("%d\n",start->info);
start=start->r;
start->l=NULL;
free(temp);
return;
}
}
void dle()
{
NODE temp;
NODE temp1=NULL;
if(start==NULL)
{
printf("DLL is Empty\n");
return;
}
else if(start->r==NULL)
{
free(start);
start=NULL;
return;
}
else
{
temp=start;
while(temp->r!=NULL)
{
temp1=temp;
temp=temp->r;
}
temp1->r=NULL;
printf("%d\n",temp->info);
free(temp);
return;
}
}
void delpos(int pos)
{
NODE temp=start;
if(start->r==NULL&&pos==1)
{
start=NULL;
free(temp);
}
else if(start->r!=NULL&&pos==1)
{
start=start->r;
start->l=NULL;
free(temp);
}
else
{
NODE temp1=NULL;
int i=1;
while(temp!=NULL&&i!=(pos-1))
{
temp=temp->r;
i++;
}
temp1=temp->r;
if(temp1->r!=NULL)
{
temp->r=temp1->r;
temp1->r->l=temp;
free(temp1);
}
else
{
temp->r=NULL;
free(temp1);
}
}
}
void display()
{
NODE temp=NULL;
if(start==NULL)
{
printf("DLL is Empty\n");
return;
}
else
{
temp=start;
while(temp!=NULL)
{
printf("%d ",temp->info);
temp=temp->r;
}
printf("\n");
return;
}
}
void main()
{
int ch,x,pos;
while(ch!=8)
{
printf("Enter you choice\n");
printf(" 1 INSERT AT BEGINNING\n 2 INSERT AT END\n 3 INSERT AT POSITION\n 4 DELETE AT BEGINNING\n 5 DELETE AT END\n 6 DELETE AT POSITION\n 7 DISPLAY\n 8 EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the value\n");
scanf("%d",&x);
inb(x);
break;
case 2:
printf("Enter the value\n");
scanf("%d",&x);
ine(x);
break;
case 3:
printf("Enter the value and the position\n");
scanf("%d %d",&x,&pos);
inpos(x,pos);
break;
case 4:
dlb();
break;
case 5:
dle();
break;
case 6:
printf("Enter the position\n");
scanf("%d",&pos);
delpos(pos);
break;
case 7:
display();
break;
}
}
}
