/*#include "iostream"
using namespace std;
 
int main(int argc, char* argv[])
{
	int count=0,num,i;
	int a[1010],m,n;
	cout<<"�����������m:";
	cin>>m;
	cout<<"������Ϊn:";
	cin>>n;
	num=m;//��¼δ�˳��ĺ�����
	for (i=1;i<=m;i++)
	{
		a[i]=1;//ÿ�����ӱ��Ϊ1����ʾ�ú���δ�˳�
	}
	while(num!=1)//��ֻ��һ����ʱ���˳�ѭ��
	{
		for (i=1;i<=m;i++)
		{
			if (a[i]==1)
			{
				count++;
			}
			if (count==n)
			{
				a[i]=0;  //
				num--;   //�˳�һֻ����
				count=0;
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		if (a[i]==1)//������ʣ�µ���ֻ���ӣ�����
		{
			cout<<"������:"<<i<<endl;
			break;
		}
	}
	return 0;
}
*/


#include <iostream>
#include <stdio.h> 
using namespace std;
 
struct node{
	int data;
	int last;
	int next;
};
 
struct node a[1100];
 
void main()
 {
	int m,n;
	cout<<"�����������m:";
	cin>>m;
	cout<<"������Ϊn:";
	cin>>n;
	for(int i=2;i<m;i++)
		{
			a[i].data=i;  a[i].last=i-1;  a[i].next=i+1;
		}
	a[1].data=1; a[1].last=m;   a[1].next=2;
	a[m].data=m; a[m].last=m-1; a[m].next=1;
		
	int num=1;       //��¼�������� 
	int count=1;     //��¼��ǰ���ӵ���� 
	while(a[count].next!=a[count].data)
	{
		if(num%n==0)
		{
			a[a[count].last].next=a[count].next;
			a[a[count].next].last=a[count].last;	
		}
		num++;
		count=a[count].next;
	}
	printf("������:%d\n",a[count].data);
}
