#include<iostream>
void fun(int a,int b,long*c)
{
*c=(a/10)*1000+(b/10)*100+(a%10)*10+b%10;
}
void main()
{int a,b;long c;
printf("Input 两个整数a ,b:");
scanf("%d %d",&a,&b);
fun(a,b,&c);
printf("The result is :%ld\n",c);
}