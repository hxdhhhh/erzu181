#include<stdio.h>
int fun(int a,int b)
{
	int c;
	c=(a/10)*1000+(b/10)*100+(a%10)*10+b%10;
	return c;
}
void main()
{
	int a,b;
	printf("请输入两个两位数：");
	scanf("%d%d",&a,&b);
	printf("%d\n",fun(a,b));
}
