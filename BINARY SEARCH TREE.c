#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct NODE
{
int info;
struct NODE* l;
struct NODE* r;
}*root = NULL;
void bst(int item)
{
struct NODE* nn;
nn=(struct NODE*)malloc(sizeof(struct NODE));
nn->info=item;
nn->l=nn->r=NULL;
if(root==NULL)
{
root=nn;
return;
}
struct NODE* parent=NULL;
struct NODE* curr=root;
while(curr!=NULL)
{
parent=curr;
if(item<=curr->info)
curr=curr->l;
else
curr=curr->r;
}
if(item<=parent->info)
parent->l=nn;
else
parent->r=nn;
return;
}
void display(struct NODE* root,int spaces)
{
    if(root!=NULL)
    {
    int i;
    display(root->r, spaces + 3);
    for( i = 0; i < spaces; i++ )
    printf(" ");
    printf("%d\n",root->info);
    display(root->l, spaces + 3);
    return;
    }
}
void main()
{
int item;
int choice=0;
while(choice!=3)
{
printf("1. Create a Binary Search Tree\n");
printf("2. Display\n3. EXIT\n");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Enter an item: ");
scanf("%d",&item);
bst(item);
break;
case 2:
display(root,0);
break;
}
}
}
