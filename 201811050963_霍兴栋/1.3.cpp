#include <iostream>             
using namespace std;
#define N 100
int main()
{  
   int n,i,j;
   int temp=0,t=0,p=0,q=0;
   double sum[N],max;
  // cout<<"��У�μ���ѡ��ѧ������Ϊ��"<<endl;
   cin>>n; 
   struct student
{
   int sno;
   double score[3];
   double sum;
}stu[n];
   for(i=0;i<n;i++)
   {
   	stu[i].sno=i+1;
   }
   //cout<<"��ѧ����С����ѧ�������ġ���ѧ��Ӣ��ĳɼ�Ϊ��"<<endl;
   for(i=0;i<n;i++)
   {
   //	cin>>stu[i].sno>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2];
   	cin>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2];
   }
//����
//�Ȱ��ִܷӸߵ��������������ͬѧ�ܷ���ͬ���ٰ����ĳɼ��Ӹߵ�������
//�������ͬѧ�ֺܷ����ĳɼ�����ͬ����ô�涨ѧ��С��ͬѧ ����ǰ��
  for(i=0;i<n;i++)
	stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];//����ÿ��ͬѧ���ܳɼ� 
 /*for(i=0;i<n;i++)
   {
   	cout<<stu[i].sno<<" "<<stu[i].sum<<endl;
   }*/
   //������� �ɴ�С 
        for(i=0;i<n;i++) 
       {   
                for(j=0;j<n-i;j++)
                {   
					   /*if(stu[j].sum==stu[j+1].sum) 
						{
							
							if(stu[j].score[0]==stu[j+1].score[0])
							{
								if(stu[j].sno>stu[j+1].sno)
		                     	{
                                p = stu[j+1].sno;
                                stu[j+1].sno = stu[j].sno;
                                stu[j].sno = p;
			                    }	
							}
							else if(stu[j].score[0]<stu[j+1].score[0])	
							   {
                                q= stu[j+1].sno;
                                stu[j+1].sno = stu[j].sno;
                                stu[j].sno = q;
                            }
                            
                        
                        } */
						
                        if(stu[j].sum<stu[j+1].sum)
                        {   
                                temp = stu[j+1].sum;
                                stu[j+1].sum = stu[j].sum;
                                stu[j].sum = temp;
                                t = stu[j+1].sno;
                                stu[j+1].sno = stu[j].sno;
                                stu[j].sno = t;
                        }    
                   }   
            }
 for(i=0;i<5;i++)
   {
   	//cout<<"ǰ5��ѧ����ѧ�ź��ܷ�Ϊ��"<<endl;
   	cout<<stu[i].sno<<" "<<stu[i].sum<<endl;
   }
return 0;
}

















