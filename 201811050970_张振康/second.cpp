#include<stdio.h>

 

#include<malloc.h>

struct Node

{
       int data;

       struct Node *next;

};//建立一个节点结构体

 

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

       }//建立一个不带头结点的单链表

 

       q->next=head;//这里，将单链表组成环状，形成循环单链表

       printf("before:");

 

       q=head;

       while(q->next!=head)

       {
              printf("%d ",q->data);

              q=q->next;

       }//依次输出节点的值

 

       printf("%d ",q->data);

 

       q=head;

       printf(" ");

 

       do {
              count++;//计数器开始计数

              if(count==n-1)

              {
                     t=q->next;

                     q->next=t->next;//到n前面那个节点stop，然后删除第n个节点

                     count=0;//计数器复位

                     printf("%d ", t->data);//输出被淘汰的猴子的号码

                     free(t);//释放内存，防止内存泄露

              }

              q=q->next;

       }

       while(q->next!=q);//这句是关键，就是循环到只剩下一个节点了，如果说有难度的话应该是理解的难点了

       printf(" the king is: %d ",q->data);//输出king的号码

}