#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
typedef enum {FALSE, TRUE} BOOL;//typedef enum { FALSE , TRUE } bool ; bool类型的变量可
                              //FALSE（假）或TRUE（真），也就是>= <= ==这类运算符的运算结果
typedef int Data; //typedef 相当于一种重命名
typedef struct node
{
	Data data;
	struct node *next;
}Node;

typedef struct stack 
{
	Node *top;
}Stack;

//初始化栈 
void Init(Stack *s)
{
	if (NULL == s)
		return;
	
	s->top = NULL;
}
//判断空栈 
BOOL Empty(Stack *s)
{
	if (NULL == s)
		return FALSE;
	
	if (NULL == s->top)
		return TRUE;
	
	return FALSE;
}
//入栈 
void Push(Stack *s, Data data)
{
	if (NULL == s)
		return;
	
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));//分配空间 
	if (NULL == node)
		return;
	
	node->data = data;
	node->next = s->top;
	s->top = node;
}
//出栈 
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
// 获取栈顶元素
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
//判断操作符是否入栈
BOOL Ope_judge(Stack *s_ope,int ope)
{
	if(Empty(s_ope))
		return TRUE;
	
	int top = GetTop(s_ope);
	
	switch(top)
	{
		case '+':
		case '-':
			if(ope == '*' || ope == '/' || ope == '(')
				return TRUE;
			break;
		case '*':
		case '/':
			if( ope == '(')
				return TRUE;
			break;
		case '(':
			if(ope == ')')
			{	
				Pop(s_ope);
			}
			return TRUE;
		default :
			break;
	}
	
	return FALSE;
}
//计算
void Calc(Stack *s_ope,Stack *s_num)
{
	int num1 = GetTop(s_num);
	Pop(s_num);
	
	int num2 = GetTop(s_num);
	Pop(s_num);
	
	int ope = GetTop(s_ope);
	Pop(s_ope);
	
	int res;
	switch(ope)
	{
		case '+':
			res = num2 + num1;
			break;
		case '-':
			res = num2 - num1;
			break;
		case '*':
			res = num2 * num1;
			break;
		case '/':
			res = num2 / num1;
			break;
		default:
			break;
	}
	Push(s_num,res);
}

//操作符处理
void Ope_deal(Stack *s_ope,Stack *s_num,int ope)
{
	if(Ope_judge(s_ope,ope) == TRUE)
	{
		Push(s_ope,ope);
	}
	else
	{
		while(Ope_judge(s_ope,ope) == FALSE)
		{
			Calc(s_ope,s_num);
		}
		
		if(ope != ')')
			Push(s_ope,ope);
	}
	
}
    
int main()
{
	char buf[100];
	fgets(buf,100,stdin);// 可以读空格、可以读换行
	buf[strlen(buf)-1] = '\0';//保留一个字符作为 '\0' 使用
	
	Stack s_num;//操作数栈
	Stack s_ope;//操作符栈
	
	Init (&s_num);//初始化 
	Init (&s_ope);
	
	char *p = buf;
	while(*p)
	{
		if(*p >= '0' && *p <= '9')//处理操作数
		{
			int num = 0;
			while(*p >= '0' && *p <= '9')
			{
				num = num *10 + *p - '0';
				p++;
			}
			
			Push(&s_num , num);//操作数入栈
			continue;
		}
		Ope_deal(&s_ope,&s_num,*p);//处理操作符
		p++;
	}
		
		while(!Empty(&s_ope))//计算最后的结果
		{
			Calc(&s_ope,&s_num);
		}
		
		int res = GetTop(&s_num);
		
		printf ("%d\n", res);
	
	
	return 0;	
}
