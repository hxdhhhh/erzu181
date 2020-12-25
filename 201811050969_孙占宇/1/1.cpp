#include<iostream.h>

/*void fun(int &a,int &b,int &d)
{
 int a1,a2,b1,b2;
 a1 = a/10;//求a的十位数
 a2 = a%10;//求a的个位数
 b1 = b/10;//求b的十位数
 b2 = b%10;//求b的个位数

 d= a2*1000+b2*100+a1*10+b1;
 

}

void main()
{
 int a,b,c;
 cout<<"请输入a,b"<<endl;
 cin>>a>>b;
 fun(a,b,c);
 cout<<c<<endl;
}

int fun(int a,int b)
{
 int c,a1,a2,b1,b2;
 a1 = a/10;//求a的十位数
 a2 = a%10;//求a的个位数
 b1 = b/10;//求b的十位数
 b2 = b%10;//求b的个位数

 c = a2*1000+b2*100+a1*10+b1;
 return c;

}

void main()
{
 int a,b,c;
 cout<<"请输入a,b"<<endl;
 cin>>a>>b;
 c=fun(a,b);
 cout<<c<<endl;
}
*/
void fun(int *a,int *b,int *c)
{
 int a1,a2,b1,b2,d;

 
 a1 = *a/10;//求a的十位数
 a2 = *a%10;//求a的个位数
 b1 = *b/10;//求b的十位数
 b2 = *b%10;//求b的个位数

 *c= a2*1000+b2*100+a1*10+b1;
 
}

void main()
{
 int a,b,c;
 cout<<"请输入a,b"<<endl;
 cin>>a>>b;
 fun(&a,&b,&c);
 cout<<c<<endl;
}


