/*************************************************************************
	> File Name: binarySearchTree.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 16时15分35秒
 ************************************************************************/
//二叉搜索树，并进行先序、中序、后序遍历
#include<stdio.h>
#include<stdlib.h>
typedef int Element;
typedef struct node{
   Element data;
   struct node* lchild;
   struct node* rchild;
}Node;
Node *root = NULL;
Node* CreateTree(int num)
{
    Node *e = (Node*)malloc(sizeof(Node));
    e->data = num;
    e->lchild = NULL;
    e->rchild = NULL;
    return e;
}
void Insert(Node *s,int num)
{
    int flag = 0;
    Node *parent = NULL;
    Node *current = NULL;
    if(root == NULL)
      root = CreateTree(num);
    current = root;
    while(current != NULL)
    {
        parent = current;
       if(s->data > current->data)
        {
            current = current->rchild;
            flag = 0;
        }
        else if(s->data < current->data)
        {
            current = current->lchild;
            flag = 1;
        }
        else
        {
            printf("插入出错，不可有重复元素\n");
            exit(-1);
        }
    }
    current = s;
    if(flag == 0)
      parent->rchild = current;
    else
      parent->lchild = current;
}
Node* Search(int num)
{
    Node* current = root;
    if(current == NULL)
      return NULL;
    while(current != NULL && current->data != num)
    {
        printf("visiting element:%d\n",current->data);
        if(current->data > num)
          current = current->lchild;
        else
          current = current->rchild;
    }
    return current;
}
void pre_order_travelsal(Node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        pre_order_travelsal(root->lchild);
        pre_order_travelsal(root->rchild);
    }
}
void in_ord_traversal(Node* root)
{
    if(root != NULL)
    {
        in_ord_traversal(root->lchild);
        printf("%d\t",root->data);
        in_ord_traversal(root->rchild);
    }
}
void post_order_traversal(Node* root)
{
    if(root != NULL)
    {
        post_order_traversal(root->lchild);
        post_order_traversal(root->rchild);
        printf("%d\t",root->data);
    }
}
int main()
{
    int num = 0;
    int array[7] = {27,14,35,10,19,31,42};
    root = CreateTree(array[0]);
    for(int i = 1; i < 7; i++)
    {
        Node *s = CreateTree(array[i]);
        Insert(s,array[i]);
    }
    printf("请输入要查找的值:\n");
    scanf("%d",&num);
    Node *res = Search(num);
    if(res == NULL)
      printf("没有找到！\n");
    else
      printf("找到了！\n");
    printf("先序遍历为:\n");
    pre_order_travelsal(root);
    printf("\n中序遍历为:\n");
    in_ord_traversal(root);
    printf("\n后序遍历为:\n");
    post_order_traversal(root);
    return 0;
}
