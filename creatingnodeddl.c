#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *rlink;
    struct Node *llink;
};
struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory is not allocated");
        exit(1);
    }
    newnode->data = data;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}
void printlist(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("ELEMENT: \t%d\n", temp->data);
        temp = temp->rlink;
    }
}
int main()
{
    int nnodes;
    printf("How many nodes you want to create\n");
    scanf("%d", &nnodes);
    struct Node *head = NULL;
    for (int i = 1; i <= nnodes; ++i)
    {
        int data;

        printf("Enter the data for new node\n");
        scanf("%d", &data);
        struct Node* newnode = createnode(data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            struct Node* temp = head;
            while (temp->rlink != NULL)
            {
                temp = temp->rlink;
            }
            temp->rlink = newnode;
            newnode->llink = temp;
        }
        printf("Doubly linklist is:\n");
        printlist(head);
    }
    return 0;
}