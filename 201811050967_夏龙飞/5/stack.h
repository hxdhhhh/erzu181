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

// ��ʼ��ջ
void Init(Stack *s);

// �жϿ�ջ
BOOL Empty(Stack *s);

// ��ջ
void Push(Stack *s, Data data);

// ��ջ
void Pop(Stack *s);

// ��ȡջ��Ԫ��
Data GetTop(Stack *s);

 



#endif // _STACK_H_
