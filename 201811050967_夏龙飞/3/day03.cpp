#include<iostream>
#include <algorithm>
using namespace std; 

struct student
{
    int Chinese;
	int Math;
	int English;
	int num;
	int sum;
}stu[10];
 
bool cmp(student stu1,student stu2)  //排序依据 
{
    if(stu1.sum!=stu2.sum) return stu1.sum>stu2.sum;
    else if(stu1.Chinese!=stu2.Chinese) return stu1.Chinese>stu2.Chinese;
    else return stu1.num<stu2.num;
}
 
int main(){
    int i,n;
	cout<<"请输入参加评选的学生人数n"<<endl;
    while(cin>>n)
    {
        for(i=0;i<n;i++) {
            stu[i].num=i+1;
            cin>>stu[i].Chinese>>stu[i].Math>>stu[i].English;
            stu[i].sum = stu[i].Chinese+stu[i].Math+stu[i].English;
        }
        sort(stu,stu+n,cmp);   //排序 
        for(i=0;i<5;i++)
            cout<<stu[i].num<<" "<<stu[i].sum<<endl;
    }
    return 0;
}   
