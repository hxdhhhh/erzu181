#include"iostream"
using namespace std;
//�������������ֱ�Ϊ����ֵ,���ò���,ָ���Ͳ�������ֵ��������ͬ����,�������㷨��һ����,ֻ�Ǵ��ݵķ�ʽ��ͬ����
int  fun1(int a,int b){
int c = a%10*1000+b%10*100+a/10*10+b/10;
return c;
}
void fun2(int a,int b,int& c1){//�����൱�ڸ��������ȡ"����"
c1 = a%10*1000+b%10*100+a/10*10+b/10;
}
void fun3(int a ,int b,int* p){
*p = a%10*1000+b%10*100+a/10*10+b/10;
}
int main(){
int a,b,c;
int *p = &c;//ָ�����������ʱ��ָ��ָ��ĵ�ַ,����ں���ָ��,дp=&c
cout<<"������������λ����a,b"<<endl;
cin>>a>>b;
fun3(a,b,p);
cout<<c;
return 0;
}
