/*//��1��ͨ������ֵ������c������������
#include <iostream>             
using namespace std;
int fun(int x,int y);	
int main()
{
  int a,b,c;
  c=0;
  cin>>a>>b;
  c=fun(a,b);
  cout<<c<<endl;
  return 0;
}
int fun(int x,int y)
{
  int z;
  z=x/10*10+x%10*1000+y/10+y%10*100;
  return z;
}
//��2��ͨ�����ò���������������������
#include <iostream>             
using namespace std;
void fun(int &x,int &y,int &z);	
int main()
{
  int a,b,c;
  c=0;
  cin>>a>>b;
  fun(a,b,c);
  cout<<c<<endl;
  return 0;
}
void fun(int &x,int &y,int &z)
{
  z=x/10*10+x%10*1000+y/10+y%10*100;		
}*/
//��3��ͨ��ָ���Ͳ�������������������
#include <iostream>             
using namespace std;
void fun(int* x,int* y,int* z);	
int main()
{
  int a,b,c;
  c=0;
  cin>>a>>b;
  fun(&a,&b,&c);
  cout<<c<<endl;
  return 0;
}
void fun(int* x,int* y,int* z)
{
  *z=*x/10*10+*x%10*1000+*y/10+*y%10*100;		
}









