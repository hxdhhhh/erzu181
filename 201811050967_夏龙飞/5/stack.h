#ifndef _STACK_H_
#define _STACK_H_

#define SIZE 10

typedef enum {FALSE, TRUE} BOOL;
typedef int Data;
typedef struct node
{
	Data data;
	struct node *next;
}Node;

typedef struct stack 
{
	Node *top;
}Stack;

// 初始化栈
void Init(Stack *s);

// 判断空栈
BOOL Empty(Stack *s);

// 入栈
void Push(Stack *s, Data data);

// 出栈
void Pop(Stack *s);

// 获取栈顶元素
Data GetTop(Stack *s);

 



#endif // _STACK_H_
