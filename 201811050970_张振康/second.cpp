#include<stdio.h>

 

#include<malloc.h>

struct Node

{
       int data;

       struct Node *next;

};//����һ���ڵ�ṹ��

 

int main()

{
       struct Node *head, *s, *q, *t;

       int n, m, count=0, i;

       printf("input the monkey number m:");

       scanf("%d",&m);

       printf(" input the number n:");

       scanf("%d",&n);

 

       for(i=0; i<m; i++)

       {
              s=(struct Node *)malloc(sizeof(struct Node));

              s->data=i+1;

              s->next=NULL;

              if(i==0)

              {
                     head=s;

                     q=head;

              }

              else

              {
                     q->next=s;

                     q=q->next;

              }

       }//����һ������ͷ���ĵ�����

 

       q->next=head;//�������������ɻ�״���γ�ѭ��������

       printf("before:");

 

       q=head;

       while(q->next!=head)

       {
              printf("%d ",q->data);

              q=q->next;

       }//��������ڵ��ֵ

 

       printf("%d ",q->data);

 

       q=head;

       printf(" ");

 

       do {
              count++;//��������ʼ����

              if(count==n-1)

              {
                     t=q->next;

                     q->next=t->next;//��nǰ���Ǹ��ڵ�stop��Ȼ��ɾ����n���ڵ�

                     count=0;//��������λ

                     printf("%d ", t->data);//�������̭�ĺ��ӵĺ���

                     free(t);//�ͷ��ڴ棬��ֹ�ڴ�й¶

              }

              q=q->next;

       }

       while(q->next!=q);//����ǹؼ�������ѭ����ֻʣ��һ���ڵ��ˣ����˵���ѶȵĻ�Ӧ���������ѵ���

       printf(" the king is: %d ",q->data);//���king�ĺ���

}