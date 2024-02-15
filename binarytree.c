#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *creatingnode(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    // newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main()
{
    /*constructing the root node
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;

    struct node *p1;
    p1=(struct node *)malloc(sizeof(struct node));
    p1->left=NULL;
    p1->right=NULL;

    struct node *p2;
    p2=(struct node *)malloc(sizeof(struct node));
    p2->left=NULL;
    p2->right=NULL;
    */

    // constructing root node - using functions
    struct node *p = creatingnode(2);
    struct node *p1 = creatingnode(1);
    struct node *p2 = creatingnode(4);
   

    // linking nodes
    p->left = p1;
    p->right = p2;

    return 0;
}