#include<stdio.h>
#include<malloc.h>
struct NODE
{
int INFO;
struct NODE* LINK;
}*LAST = NULL;
void inb(int item)
{
struct NODE* NN;
NN = (struct NODE*)malloc(sizeof(struct NODE));
NN->INFO = item;
if(LAST==NULL)
{
NN->LINK=NN;
LAST=NN;
}
else
{
NN->LINK=LAST->LINK;
LAST->LINK=NN;
}
return;
}
void ine(int item)
{
struct NODE* NN;
NN = (struct NODE*)malloc(sizeof(struct NODE));
NN->INFO = item;
if(LAST==NULL)
{
NN->LINK=NN;
LAST=NN;
return;
}
else
{
NN->LINK=LAST->LINK;
LAST->LINK=NN;
LAST=LAST->LINK;
return;
}
}
void inpos(int item,int pos)
{
int c=1;
struct NODE* NN;
NN = (struct NODE*)malloc(sizeof(struct NODE));
NN->INFO = item;
if(LAST==NULL&&pos==1)
{
NN->LINK=NN;
LAST=NN;
return;
}
else if(LAST==NULL&&pos>1)
{
printf("INVALID POSITION\n");
return;
}
else if(LAST!=NULL&&pos==1)
{
NN->LINK=LAST->LINK;
LAST->LINK=NN;
return;
}
else
{
struct NODE* TEMP=LAST->LINK;
while(TEMP!=LAST&&c!=(pos-1))
{
TEMP=TEMP->LINK;
c++;
}
if(TEMP==LAST)
{
NN->LINK=TEMP->LINK;
TEMP->LINK=NN;
LAST=NN;
return;
}
NN->LINK=TEMP->LINK;
TEMP->LINK=NN;
}
}
void dlb()
{
struct NODE* TEMP=NULL;
if(LAST==NULL)
{
printf("CLL is Empty\n");
return;
}
else if(LAST->LINK==LAST)
{
printf("%d\n",LAST->INFO);
free(LAST);
LAST=NULL;
return;
}
else
{
TEMP=LAST->LINK;
printf("%d\n",TEMP->INFO);
LAST->LINK=TEMP->LINK;
free(TEMP);
return;
}
}
void dle()
{
struct NODE* TEMP1;
struct NODE* TEMP2=NULL;
if(LAST==NULL)
{
printf("CLL is Empty\n");
return;
}
else if(LAST->LINK==LAST)
{
printf("%d\n",LAST->INFO);
free(LAST);
LAST=NULL;
return;
}
else
{
TEMP2=LAST;
TEMP1=LAST;
while(TEMP1->LINK!=LAST)
{
TEMP1=TEMP1->LINK;
}
TEMP1->LINK=LAST->LINK;
printf("%d\n",TEMP2->INFO);
free(TEMP2);
LAST=TEMP1;
return;
}
}
void delpos(int pos)
{
struct NODE* TEMP=LAST;
struct NODE* TEMP1=NULL;
if(LAST==NULL)
printf("List is Empty\n");
else if(LAST->LINK==LAST&&pos==1)
{
LAST=NULL;
free(TEMP);
}
else if(LAST->LINK!=LAST&&pos==1)
{
TEMP=LAST->LINK;
LAST->LINK=TEMP->LINK;
free(TEMP);
}
else
{
TEMP=TEMP->LINK;
int i=1;
while(TEMP!=LAST&&i!=(pos-1))
{
TEMP=TEMP->LINK;
i++;
}
TEMP1=TEMP->LINK;
TEMP->LINK=TEMP1->LINK;
if(TEMP1==LAST)
{
free(TEMP1);
LAST=TEMP;
}
else
free(TEMP1);
}
}
void display()
{
struct NODE* TEMP=NULL;
if(LAST==NULL)
{
printf("CLL is Empty\n");
return;
}
else
{
TEMP=LAST;
TEMP=TEMP->LINK;
while(TEMP!=LAST)
{
printf("%d ",TEMP->INFO);
TEMP=TEMP->LINK;
}
printf("%d ",TEMP->INFO);
return;
}
}
int main()
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
return 0;
}
