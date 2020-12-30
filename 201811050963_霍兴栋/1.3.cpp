#include <iostream>             
using namespace std;
#define N 100
int main()
{  
   int n,i,j;
   int temp=0,t=0,p=0,q=0;
   double sum[N],max;
  // cout<<"该校参加评选的学生人数为："<<endl;
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
   //cout<<"按学号由小到大学生的语文、数学、英语的成绩为："<<endl;
   for(i=0;i<n;i++)
   {
   //	cin>>stu[i].sno>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2];
   	cin>>stu[i].score[0]>>stu[i].score[1]>>stu[i].score[2];
   }
//排序
//先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，
//如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面
  for(i=0;i<n;i++)
	stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];//计算每名同学的总成绩 
 /*for(i=0;i<n;i++)
   {
   	cout<<stu[i].sno<<" "<<stu[i].sum<<endl;
   }*/
   //排序过程 由大到小 
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
   	//cout<<"前5名学生的学号和总分为："<<endl;
   	cout<<stu[i].sno<<" "<<stu[i].sum<<endl;
   }
return 0;
}

















