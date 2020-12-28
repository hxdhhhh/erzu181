#include <iostream>
using namespace std;
int fun(int a,int b)
{
int c,a1,a2,b1,b2;
a1 = a/10;
a2 = a%10;
b1 = b/10;
b2 = b%10;
c = a1*1000+b1*100+a2*10+b2;
cout;
return c;
}
void main()
{
	int a,b;
	printf("请输入两个两位数：");
	scanf("%d%d",&a,&b);
	printf("%d\n",fun(a,b));
}
