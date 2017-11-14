/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 10时30分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
   int capacity;//队列的容量
   int front;
   int rear;
   int size;//计算元素出队入队后的元素个数
   int array[0];
}Queue;
Queue* Init(int n)
{
    Queue *q = (Queue*)malloc(sizeof(Queue)+n*sizeof(int));
    q->capacity = n;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}
int isEmpty(Queue *q)
{
    if(q->size == 0)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(Queue *q)
{
    if(q->size == q->capacity)
      return 1;
    else
      return 0;
}
void enQueue(Queue *q,int a)
{
    if(isFull(q))
    {
        printf("队列已满!\n");
    }
    else
    {
        (q->size)++;
        if(q->rear == q->capacity - 1)
        {
            q->rear = 0;
        }
        else
            q->rear++;
        q->array[q->rear] = a;
    }
}
void Print(Queue *q)
{
    int i = 0;
   if(q->front > q->rear)
    {
        for(i = q->front; i < q->capacity; i++)
        {
            printf("%10d",q->array[i]);
        }
        for(i = 0; i <= q->rear; i++)
        {
            printf("%10d",q->array[i]);
        }
        printf("\n");
    }
    else
    {
        for(i = q->front; i <= q->rear; i++)
        {
            printf("%10d",q->array[i]);
        }
        printf("\n");
    }
}
int deQueue(Queue *q)
{
    int top = 0;
    if(isEmpty(q))
    {
        printf("队列为空！\n");
    }
    else
    {
        (q->size)--;
        top = q->array[q->front];
        if(q->front == q->capacity-1)
        {
            q->front == 0;
        }
        else
        {
            q->front++;
        }
        Print(q);
    }
    return top;
}
void Destroy(Queue **s)
{
   free(*s);
   *s = NULL;
}
int main()
{
   int n = 0;
   printf("请输入想要多大的队列\n");
   scanf("%d",&n);
   Queue *q;
   q = Init(n);
   enQueue(q,4);
   enQueue(q,6);
   enQueue(q,3);
   enQueue(q,7);
   enQueue(q,9);
   enQueue(q,2);
   Print(q);
   deQueue(q);
   deQueue(q);
   enQueue(q,1);
   Print(q);
   Destroy(&q);
   return 0;
}
