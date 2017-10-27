/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月23日 星期六 14时35分53秒
 ************************************************************************/
//无头结点的链表
#include<stdio.h>
#include<stdlib.h>
typedef int Elementype;
typedef struct node
{
   Elementype data;
   struct node* next;    
}Node;
typedef Node* List;//把指向node的指针名字换成List,指的是整个链表的头,而node*是指某个结点的头,实际是一个地址，但是想表达的含义不同
List makeEmpty()//取指针是指其中的内容,创建结点操作
{
    List list_table = (List)malloc(sizeof(Node));
    list_table->data = 0;
    list_table->next = NULL;
    return list_table;
}

void Print(List list_table)
{
    do
    {
       printf("%d\t",list_table->data);
       list_table = list_table->next;
    }while(list_table != NULL);//本身已创建好的先打印一下
}
/*尾插法*/
List Insert(List *L,Elementype e)
{
    Node* ls  = makeEmpty();
    ls->data = e;
    List tmp = *L;//保存下来以便之后查询功能时能从头开始
    while((*L)->next != NULL)
    {
        *L = (*L)->next;
    }
    (*L)->next = ls;//指的是L的下一个结点是ls，而反过来是指L的下一个结点是某个结点，但是这个结点又由ls指向。
    return tmp;//返回插入后的链表
}
/*头插法*/
List Insert1(List *L,Elementype e)
{
    Node* node = makeEmpty();
    node->data = e;
    node->next = *L;
    return node;
}

void Delete(List *head,int e)//为防止删头部，用2级指针,返回头部的值
{
    List tmp = *head;//目的为了保留下*head的指针位置，而改用tmp操作，不会影响外部A的指针移动。
    List prov = *head;
  //如果是第一个元素
   if((*head)->data == e)
    {
        *head = (*head)->next;
        free(tmp);
    }
    //如果不是第一个元素
    else
    {
      while(tmp->next != NULL)
      { 
       prov = tmp; //记录要找的结点的前一个结点 
       tmp  = tmp->next;
       if(tmp->data == e)
       {
          //tmp = prov->next;
          prov->next = (prov->next)->next;
          free(tmp);
           //*head = NULL;
           tmp = NULL;
           return;
       }
      }
      if(tmp->next == NULL)
      {
        printf("没有要删除的元素\n");
      }
    }
}
/*void init(Node **list)//二级指针的原因：首先要实现多个Node，用*，而且要访问某个node是用他的地址，又一个*
{
    Node *list = (Node*)malloc(sizeof(struct node));
}*/
int main()
{
    List A = makeEmpty();
    A = Insert(&A,2);
    A = Insert(&A,5);
    A = Insert(&A,6);
    A = Insert(&A,8);
    A = Insert1(&A,3);
    Print(A);
    putchar(10);
    Delete(&A,6);
    Print(A);
    return 0;
}
