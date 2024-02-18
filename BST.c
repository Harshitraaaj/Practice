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
// preorder function
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
int isBST(struct node* root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
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
    struct node *p = creatingnode(5);
    struct node *p1 = creatingnode(3);
    struct node *p2 = creatingnode(6);
    struct node *p3 = creatingnode(1);
    struct node *p4 = creatingnode(4);
    /*
    tree looks like this
                5
               / \
              3     6
             / \
            1   4
    */

    // linking nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //preOrder(p);
    //printf("\n");
    //postOrder(p);
    //printf("\n");
    inorder(p);//output is in ascending order , Hence it is a binary tree
    printf("\n");
    printf("%d",isBST(p));

    return 0;
}