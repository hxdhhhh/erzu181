/*#include "iostream"
using namespace std;
 
int main(int argc, char* argv[])
{
	int count=0,num,i;
	int a[1010],m,n;
	cout<<"请输入猴子数m:";
	cin>>m;
	cout<<"数的数为n:";
	cin>>n;
	num=m;//记录未退出的猴子数
	for (i=1;i<=m;i++)
	{
		a[i]=1;//每个猴子标记为1，表示该猴子未退出
	}
	while(num!=1)//当只有一猴子时，退出循环
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
				num--;   //退出一只猴子
				count=0;
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		if (a[i]==1)//输出最后剩下的那只猴子，猴王
		{
			cout<<"大王是:"<<i<<endl;
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
	cout<<"请输入猴子数m:";
	cin>>m;
	cout<<"数的数为n:";
	cin>>n;
	for(int i=2;i<m;i++)
		{
			a[i].data=i;  a[i].last=i-1;  a[i].next=i+1;
		}
	a[1].data=1; a[1].last=m;   a[1].next=2;
	a[m].data=m; a[m].last=m-1; a[m].next=1;
		
	int num=1;       //记录报数次数 
	int count=1;     //记录当前猴子的序号 
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
	printf("大王是:%d\n",a[count].data);
}
