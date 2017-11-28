/*************************************************************************
	> File Name: BFS_graph.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月28日 星期二 10时21分44秒
 ************************************************************************/
//不同于深度优先搜索，广度优先搜索用先进先出队列实现
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int graph[MAX][MAX] = {0};//邻接矩阵表示图
typedef struct node{
   int visited;
   char name;
}Node;
int queue[MAX];
int rear = -1;//队尾
int font = 0;//队头
int queueCount = 0;//队列中元素的数量
Node *NodeList[MAX];
int count = 0;
int deQueue()
{
   queueCount--;
   return queue[font++];
}
void enQueue(int item)
{
   queue[rear++] = item;
   queueCount++;
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
void breadthFirstSearch()
{
    int i = 0;
    NodeList[0]->visited = 1;
    enQueue(0);
    int index = 0;
    printNode(index);
    while(queueCount != 0)//如果队列不为空的话，最后全部出队列的过程结束点就是队列为空
    {
       for(i = 0; i < MAX; i++)
       {
          if(graph[index][i] == 1 && NodeList[i]->visited == 0)//如果与当前节点有边相连，且没被访问过则
          {
             enQueue(i);
             printNode(i);
             NodeList[i]->visited = 1;
          }
       }
       if(i == MAX)
        {
            deQueue(index);
            index = queue[font];
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
  breadthFirstSearch();
  return 0;
}
