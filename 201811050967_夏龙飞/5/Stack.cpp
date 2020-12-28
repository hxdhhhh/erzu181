#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void Init(Stack *s)
{
	if (NULL == s)
		return;
	
	s->top = NULL;
}

BOOL Empty(Stack *s)
{
	if (NULL == s)
		return FALSE;
	
	if (NULL == s->top)
		return TRUE;
	
	return FALSE;
}

void Push(Stack *s, Data data)
{
	if (NULL == s)
		return;
	
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));
	if (NULL == node)
		return;
	
	node->data = data;
	node->next = s->top;
	s->top = node;
}

void Pop(Stack *s)
{
	if (NULL == s)
		return;
	
	if (Empty(s) == TRUE)
		return;
	
	Node *tmp = s->top;
	s->top = tmp->next;
	free(tmp);
}

Data GetTop(Stack *s)
{
	if (NULL == s)
		return 0;
	
	if (Empty(s) == TRUE)
	{
		printf ("无栈顶元素\n");
		exit(-1);  // 程序退出
	}
	
	return s->top->data;
}
