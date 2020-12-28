#include"iostream"
using namespace std;
//下面三个函数分别为返回值,引用参数,指针型参数传递值的三个不同函数,但基本算法是一样的,只是传递的方式不同而已
int  fun1(int a,int b){
int c = a%10*1000+b%10*100+a/10*10+b/10;
return c;
}
void fun2(int a,int b,int& c1){//引用相当于给这个参数取"别名"
c1 = a%10*1000+b%10*100+a/10*10+b/10;
}
void fun3(int a ,int b,int* p){
*p = a%10*1000+b%10*100+a/10*10+b/10;
}
int main(){
int a,b,c;
int *p = &c;//指针可以在声明时就指明指向的地址,如果在后续指明,写p=&c
cout<<"请输入两个两位整数a,b"<<endl;
cin>>a>>b;
fun3(a,b,p);
cout<<c;
return 0;
}
