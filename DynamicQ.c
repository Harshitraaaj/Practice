#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

struct queue q;

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

int isempty(struct queue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        // int value = q->arr[q->f];
        q->f++;
        a = q->arr[q->f];
        // printf("deleted value is %d",value);
    }
    return a;
}
void display(struct queue *q)
{
    if (isempty(q))
    {
        printf("queue is empty\n");
    }
    for (int i = q->f+1; i <= q->r; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}
int main()
{
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 15);
    display(&q);
    return 0;
}