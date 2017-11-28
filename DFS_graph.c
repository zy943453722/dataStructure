/*************************************************************************
	> File Name: DFS_graph.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月26日 星期日 11时09分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int graph[MAX][MAX] = {0};//邻接矩阵表示图
typedef struct node{
   int visited;
   char name;
}Node;
int stack[MAX];
int top = -1;//栈的下标
Node *NodeList[MAX];
int count = 0;
int pop()
{
   return stack[top--];
}
void push(int item)
{
   stack[++top] = item;
}
void AddNode(char a)
{
    if(count < MAX)  
    {
      Node *p = (Node*)malloc(sizeof(Node));
      p->visited = 0;
      p->name = a;
      NodeList[count++] = p;
    }
    else
      return;
}
void AddEdge(int i,int j)
{
    graph[i][j] = 1;
    graph[j][i] = 1;
}
void printNode(int index)
{
    printf("%c\t",NodeList[index]->name);
}
void depthFirstSearch()
{
    int i = 0;
    NodeList[0]->visited = 1;
    push(0);
    int index = 0;
    printNode(index);
    while(top != -1)//如果栈不为空的话，最后全部退栈的过程结束点就是栈为空
    {
       for(i = 0; i < MAX; i++)
       {
          if(graph[index][i] == 1 && NodeList[i]->visited == 0)//如果与当前节点有边相连，且没被访问过则
          {
             push(i);
             index = i;
             printNode(index);
             NodeList[i]->visited = 1;
             break;
          }
       }
       if(i == MAX)
        {
            pop(index);
            index = stack[top];
        }
    }
}
int main()
{
  AddNode('S');//0
  AddNode('A');//1
  AddNode('B');//2
  AddNode('C');//3
  AddNode('D');//4
  AddEdge(0,1);//S-A
  AddEdge(0,2);//S-B
  AddEdge(0,3);//S-C
  AddEdge(1,4);//A-D
  AddEdge(2,4);//B-D
  AddEdge(3,4);//C-D
  depthFirstSearch();
  return 0;
}

