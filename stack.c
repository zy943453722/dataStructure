/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月26日 星期四 20时47分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int count;
    int array[];
    //int *array;
}Stack;
/*此处要用2级指针，因为主函数中定义一个Stack类型结构体后，在栈上开辟了一块内存地址，但要是将此指向此地址的指针重新malloc后，栈又给此指针分配一块新的内存地址，改变也是改变新的内存地址上的内容，原地址中的数据并没有发生变化。*/
void Init(Stack **s,int n)
{
  Stack *p = (Stack *)malloc(sizeof(Stack) + n * sizeof(int));//新malloc出一块地址指向原来的结构体，则改变
  *s = p;//这实际上是将这个2级指针s也指向malloc出来的指针
  //s = (Stack *)malloc(sizeof(Stack));
  //s->array = (int *)malloc(sizeof(int) * n);
  p->top = -1;
  p->count = n;
}
/*另一种Init函数的另外写法*/
//Stack* Init(int n)
//{
//  Stack *p = (Stack*)malloc(sizeof(Stack)+n * sizeof(int));
//  p->top = -1;
//  p->count = n;
//  return p;
//}
int isEmpty(Stack *s)
{
  if(s->top == -1)
    {
        return 1;
    }
    else
      return 0;
}

int isFull(Stack *s)
{
    if(s->top == s->count - 1)
       return 1;
    else
       return 0;
}

void Push(Stack *s,int a)
{
    if(isFull(s))
    {
        printf("栈已满！\n");
    }
    else
    {
       s->array[++(s->top)] = a;
    }
}

int Pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("栈为空!");
        return -1; 
    }
    else
    {
       return s->array[(s->top)--];
    }
}

void Top(Stack *s)
{
   if(isEmpty(s))
    {
        printf("栈为空!\n");
    }
    else
    {
       printf("%d\n",s->array[(s->top)]);
    }
}

void Print(Stack *s)
{
    for(int i = 0; i <= s->top; i++)
    {
        printf("%10d\n",s->array[i]);
    }
}

void Destroy(Stack **s)
{
  free(*s);
  *s = NULL;
}

int main()
{
    int n = 0;
    printf("请输入栈的大小:\n");
    scanf("%d",&n);
    Stack s;
    Stack *q = &s;
    Init(&q,n);//这个函数返回回来之后q这个指针的已经改变，并不指向原来的s了，指向malloc的地址，而s的地址还是原来的地址
    Push(q,5);
    Push(q,6);
    Push(q,7);
    Top(q);
    Print(q);
    printf("\n");
    int a = Pop(q);
    Print(q);
    Destroy(&q);
    return 0;
}
