//����ʵ�� 

/*#include <iostream>             
using namespace std; 

void fun(int m,int n);
int main()  
{  
    int m,n;  //mΪ���Ӹ�����nΪ��������ʱ�����뿪 
    cin>>m>>n;
    //cout<<m<<' '<<n<<endl;
    cout<<"����"<<m<<"�����ӣ���"<<n<<"�����ķ��������Ϊ�����ĺ���Ϊ:"<<endl;
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
            t=(t+1)%m;  //����ѭ�� 
            if(a[t]==1)  
            j++;  
        }  
        a[t]=0;  //��������Ϊ0 
        j=0;  
 
    }  
    cout<<t+1<<endl; 
}*/
#include <iostream>
using namespace std;

struct Monkey
{
    int num;  //���ӵı��
    struct Monkey *next; //��һֻ����
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
        //��������Χ�ɵ�ԲȦ
        p=q=new Monkey;
        head = p;
        p->num=1;
        for(i=1; i<m; i++)  //����m-1ֻ����
        {
            p=new Monkey;  //p1�������ӵ�
            p->num=i+1;
            q->next=q;
            q=p;          //p2������һֻ
        }
        q->next=head;      //���һֻ��ָ���һֻ������һ��ԲȦ
 
        //����Ҫ��ʼ����
        p=head;
        for(i=1; i<m; i++)  //ѭ��m-1�Σ���̭m-1ֻ����
        {
            //��p1��ʼ����n-1ֻ���ҵ���nֻ��
            for(j=1; j<n-1; j++)  //ʵ�����ҵ���n-1ֻ����һֻ���Ǳ���̭��
                p=p->next;    //Χ��Ȧ�ģ������ٿ�ʼ�ӵ�һֻ���������δ����̭�Ļ�
 
            //�ҵ��ˣ�
            q=p->next;  //p2����ɾ��
            //cout<<"��"<<i<<"����̭"<<p2->num<<endl;   //���������۲��м���
            p->next=q->next;  //p2�����������ܿ��ˡ�
            p=q->next;  //��һ�������������
            delete q;  //�����������еĽ�������
        }
        o=p->num;
        delete p;
    }
    cout<<o<<endl;
    return 0;
}



























