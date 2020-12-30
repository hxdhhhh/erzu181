#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
typedef enum {FALSE, TRUE} BOOL;//typedef enum { FALSE , TRUE } bool ; bool���͵ı�����
                              //FALSE���٣���TRUE���棩��Ҳ����>= <= ==�����������������
typedef int Data; //typedef �൱��һ��������
typedef struct node
{
	Data data;
	struct node *next;
}Node;

typedef struct stack 
{
	Node *top;
}Stack;

//��ʼ��ջ 
void Init(Stack *s)
{
	if (NULL == s)
		return;
	
	s->top = NULL;
}
//�жϿ�ջ 
BOOL Empty(Stack *s)
{
	if (NULL == s)
		return FALSE;
	
	if (NULL == s->top)
		return TRUE;
	
	return FALSE;
}
//��ջ 
void Push(Stack *s, Data data)
{
	if (NULL == s)
		return;
	
	Node *node = (Node *)malloc(sizeof(Node)/sizeof(char));//����ռ� 
	if (NULL == node)
		return;
	
	node->data = data;
	node->next = s->top;
	s->top = node;
}
//��ջ 
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
// ��ȡջ��Ԫ��
Data GetTop(Stack *s)
{
	if (NULL == s)
		return 0;
	
	if (Empty(s) == TRUE)
	{
		printf ("��ջ��Ԫ��\n");
		exit(-1);  // �����˳�
	}
	
	return s->top->data;
}
//�жϲ������Ƿ���ջ
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
//����
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

//����������
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
	fgets(buf,100,stdin);// ���Զ��ո񡢿��Զ�����
	buf[strlen(buf)-1] = '\0';//����һ���ַ���Ϊ '\0' ʹ��
	
	Stack s_num;//������ջ
	Stack s_ope;//������ջ
	
	Init (&s_num);//��ʼ�� 
	Init (&s_ope);
	
	char *p = buf;
	while(*p)
	{
		if(*p >= '0' && *p <= '9')//���������
		{
			int num = 0;
			while(*p >= '0' && *p <= '9')
			{
				num = num *10 + *p - '0';
				p++;
			}
			
			Push(&s_num , num);//��������ջ
			continue;
		}
		Ope_deal(&s_ope,&s_num,*p);//���������
		p++;
	}
		
		while(!Empty(&s_ope))//�������Ľ��
		{
			Calc(&s_ope,&s_num);
		}
		
		int res = GetTop(&s_num);
		
		printf ("%d\n", res);
	
	
	return 0;	
}
