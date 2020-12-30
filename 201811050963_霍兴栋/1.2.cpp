//数组实现 

/*#include <iostream>             
using namespace std; 

void fun(int m,int n);
int main()  
{  
    int m,n;  //m为猴子个数，n为数到该数时猴子离开 
    cin>>m>>n;
    //cout<<m<<' '<<n<<endl;
    cout<<"按照"<<m<<"个猴子，数"<<n<<"个数的方法，输出为大王的猴子为:"<<endl;
    fun(m,n);  
    return 0;  
}
void fun(int m,int n)  
{  
    int a[m];  
    int i,j=0,t=-1; 
	for(i=0;i<m;i++)  
        a[i]=1;  
    for(i=0;i<m;i++)
    {  
        while(j<n)  
        {  
            t=(t+1)%m;  //构成循环 
            if(a[t]==1)  
            j++;  
        }  
        a[t]=0;  //队列重置为0 
        j=0;  
 
    }  
    cout<<t+1<<endl; 
}*/
#include <iostream>
using namespace std;

struct Monkey
{
    int num;  //猴子的编号
    struct Monkey *next; //下一只猴子
};
 
int main()
{
    int m,n,i,j,o;
    Monkey *head, *p,*q;
    cin>>m>>n;
    if(n==1)
    {
        o=m;
    }
    else
    {
        //建立猴子围成的圆圈
        p=q=new Monkey;
        head = p;
        p->num=1;
        for(i=1; i<m; i++)  //其余m-1只猴子
        {
            p=new Monkey;  //p1是新增加的
            p->num=i+1;
            q->next=q;
            q=p;          //p2总是上一只
        }
        q->next=head;      //最后一只再指向第一只，成了一个圆圈
 
        //下面要开始数了
        p=head;
        for(i=1; i<m; i++)  //循环m-1次，淘汰m-1只猴子
        {
            //从p1开始，数n-1只就找到第n只了
            for(j=1; j<n-1; j++)  //实际先找到第n-1只，下一只将是被淘汰的
                p=p->next;    //围成圈的，可能再开始从第一只数，如果还未被淘汰的话
 
            //找到了，
            q=p->next;  //p2将被删除
            //cout<<"第"<<i<<"轮淘汰"<<p2->num<<endl;   //可以这样观察中间结果
            p->next=q->next;  //p2就这样被“架空了”
            p=q->next;  //下一轮数数的新起点
            delete q;  //将不在链表中的结点放弃掉
        }
        o=p->num;
        delete p;
    }
    cout<<o<<endl;
    return 0;
}



























