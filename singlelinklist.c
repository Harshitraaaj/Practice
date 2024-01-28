#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
/*counting how many nodes exist in LINKLIST*/
void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        primtf("Linked list is empty");
    struct node *ptr = NULL;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("%d", count);
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 45;
    current->link = NULL;
    head->link = current;
    return 0;
}