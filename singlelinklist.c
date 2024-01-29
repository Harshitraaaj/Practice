#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
/*counting how many nodes exist in LINKLIST
void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("Linked list is empty");
    struct node *ptr = NULL;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("%d", count);
}

*/
void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->link;
    }
}
//case 1: inserting at first
struct Node *insertatfirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->link = head;
    ptr->data = data;
}
//case 2: inserting at index
struct Node *insertatIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->link;
        i++;
    }
    ptr->data = data;
    ptr->link = p->link;
    p->link = ptr;
    return head;
}
// case 3: inserting at the end 
struct Node *insertatend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = ptr;
    ptr->link = NULL;
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
}

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
    head->link = second;

    second->data = 9;
    second->link = third;

    third->data = 13;
    third->link = NULL;
    printf("\nlinkedlist before insertion\n");
    linkedlisttraversal(head);
    // head = insertatfirst(head, 56);
    // head=insertatIndex(head, 56, 1);
    //head = insertatend(head, 89);
    
    printf("\nlinked list after insertion\n");
    head=insertafternode(head,second,45);

    
    linkedlisttraversal(head);

    return 0;
}