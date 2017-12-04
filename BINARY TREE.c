#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct node{
int info;
struct node *l;
struct node *r;
};
typedef struct node* NODE;
NODE root=NULL;
NODE bt()
{
    NODE nn=(NODE)malloc(sizeof(struct node));
    printf("Enter Element\n");
    scanf("%d",&nn->info);
    nn->l=nn->r=NULL;
    if(root==NULL)
    {
        root=nn;
        return root;
    }
    printf("Enter direction\n");
    NODE curr=root;
    char s[10];
    scanf("%s",s);
    int len=strlen(s);
    int i;
    for(i=0;i<(len-1);i++)
    {
        if(s[i]=='L')
            curr=curr->l;
        else
            curr=curr->r;
    }
    if(curr->l==NULL&&s[i]=='L')
        curr->l=nn;
    else
        curr->r=nn;
        return root;
}
void pre_order(NODE root)
{
if(root!= NULL)
{
printf("%d",root->info);
pre_order(root->l);
pre_order(root->r);
}
}
void in_order(NODE root)
{
if(root!= NULL)
{
in_order(root->l);
printf("%d",root->info);
in_order(root->r);
}
}
void post_order(NODE root)
{
if(root!= NULL)
{
post_order(root->l);
post_order(root->r);
printf("%d",root->info);
}
}
void main()
{
int choice=0;
while(choice!=5)
{
printf("\n1. Create a Binary Tree\n");
printf("2. Pre-Order Traversal\n");
printf("3. In-Order Traversal\n");
printf("4. Post-Order Traversal\n5. EXIT\n");
scanf("%d", &choice);
switch(choice)
{
case 1:
root=bt();
break;
case 2:
pre_order(root);
break;
case 3:
in_order(root);
break;
case 4:
post_order(root);
break;
}
}
}
