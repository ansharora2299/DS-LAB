#include<stdio.h>
#include<malloc.h>
struct NODE
{
int INFO;
struct NODE* LINK;
}*START = NULL;
void inb(int item)
{
struct NODE* NN;
NN = (struct NODE*)malloc(sizeof(struct NODE));
NN->INFO = item;
if(START==NULL)
NN->LINK=NULL;
else
NN->LINK=START;
START=NN;
return;
}
void ine(int item)
{
struct NODE* NN;
struct NODE* TEMP=NULL;
NN = (struct NODE*)malloc(sizeof(struct NODE));
NN->INFO = item;
NN->LINK=NULL;
if(START==NULL)
{
START=NN;
return;
}
else
{
TEMP=START;
while(TEMP->LINK!=NULL)
TEMP=TEMP->LINK;
TEMP->LINK=NN;
return;
}
}
void inpos(int item,int pos)
{
int c=1;
struct NODE* NN;
NN = (struct NODE*)malloc(sizeof(struct NODE));
NN->INFO = item;
if(START==NULL&&pos==1)
{
NN->LINK=NULL;
START=NN;
return;
}
else if(START==NULL&&pos>1)
{
printf("INVALID POSITION\n");
return;
}
else if(START!=NULL&&pos==1)
{
NN->LINK=START;
START=NN;
return;
}
struct NODE* TEMP=START;
while(TEMP!=NULL&&c!=(pos-1))
{
TEMP=TEMP->LINK;
c++;
}
if(TEMP==NULL)
{
printf("INVALID POSITION\n");
return;
}
NN->LINK=TEMP->LINK;
TEMP->LINK=NN;
}
void dlb()
{
struct NODE* TEMP=NULL;
if(START==NULL)
{
printf("SLL is Empty\n");
return;
}
else
{
TEMP=START;
printf("%d\n",START->INFO);
START=START->LINK;
free(TEMP);
return;
}
}
void dle()
{
struct NODE* TEMP1;
struct NODE* TEMP2=NULL;
if(START==NULL)
{
printf("SLL is Empty\n");
return;
}
else if(START->LINK==NULL)
{
free(START);
START=NULL;
return;
}
else
{
TEMP1=START;
while(TEMP1->LINK!=NULL)
{
TEMP2=TEMP1;
TEMP1=TEMP1->LINK;
}
TEMP2->LINK=NULL;
printf("%d\n",TEMP1->INFO);
free(TEMP1);
return;
}
}
void display()
{
struct NODE* TEMP=NULL;
if(START==NULL)
{
printf("SLL is Empty\n");
return;
}
else
{
TEMP=START;
while(TEMP!=NULL)
{
printf("%d ",TEMP->INFO);
TEMP=TEMP->LINK;
}
return;
}
}
void delpos(int pos)
{
struct NODE* TEMP=START;
if(START->LINK==NULL&&pos==1)
{
START=NULL;
free(TEMP);
}
else if(START->LINK!=NULL&&pos==1)
{
START=START->LINK;
free(TEMP);
}
else
{
struct NODE* TEMP1=NULL;
int i=1;
while(TEMP!=NULL&&i!=(pos-1))
{
TEMP=TEMP->LINK;
i++;
}
TEMP1=TEMP->LINK;
if(TEMP->LINK->LINK!=NULL)
{
TEMP->LINK=TEMP1->LINK;
free(TEMP1);
}
else
{
TEMP->LINK=NULL;
free(TEMP1);
}
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
