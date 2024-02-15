#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
};
/*counting how many nodes exist in LINKLIST
void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("Linked list is empty");
    struct node *ptr->rlink = NULL;
    while (ptr->rlink!= NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("%d", count);
}

*/
void linkedlisttraversal(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("Element: %d\n", temp->data);
        temp = temp->rlink;
    }
}
// case 1: deleting first node
struct Node *deleteatfirst(struct Node *head)
{
    int value;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    value = ptr->data;
    head = head->rlink;
    head->llink=NULL;
    printf("deleted data is : %d", value);
    free(ptr);
   
}

/*case 2: inserting at index
struct Node *insertatIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp = head;
    int i;
    for (i = 1; i != index - 1; i++)
    {
        temp = temp->rlink;
    }
    ptr->llink = temp;
    ptr->rlink = temp->rlink;
    temp->rlink->llink = ptr;
    temp->rlink = ptr;
    return head;
}

// case 3: inserting at the end
struct Node *insertatend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp = head;
    while (temp->rlink != NULL)
    {
        temp = temp->rlink;
    }
    temp->rlink = ptr;
    ptr->llink = temp;
    ptr->rlink = NULL;
    return head;
}

//case 4 :inserting node after node
struct Node *insertafternode(struct Node *head,struct Node *previousnode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link=previousnode->link;
    previousnode->link=ptr;

    return head;
}*/

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->llink = NULL;
    head->rlink = second;

    second->data = 9;
    second->llink = head;
    second->rlink = third;

    third->data = 13;
    third->llink = second;
    third->rlink = NULL;
    printf("\nlinkedlist before deletion\n");
    linkedlisttraversal(head);
    printf("\nlinked list after deletion\n");

    // head = insertatfirst(head, 56);
    head = deleteatfirst(head);

    // head=insertatIndex(head, 56, 2);
    //  head= insertatend(head, 89);

    // head=insertafternode(head,second,45);

    linkedlisttraversal(head);

    return 0;
}