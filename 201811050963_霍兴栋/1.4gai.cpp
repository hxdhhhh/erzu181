#include <iostream>  
#include <string>           
using namespace std; 
#define n 100
int main()  
{   int i,j,M,N,C,c;
    string str[n];
    cout<<"地图的长M宽N为："<<endl;
	cin>>M>>N;
    for(i=0;i<N;i++)
    cin>>str[i];
    cin>>C;
for(c=0;c<C;c++)
{
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)

		{	
	   	   if(str[i][j]=='X')
		   { 
	   	    
	   	     	if(i!=0)
				{   
					if(str[i-1][j]!='P')  //上 
                     str[i-1][j]='X';
				} 
		        if(j!=(M-1))
		       	{
					if(str[i][j+1]=='O')  //右 
					{
			          str[i][j+1]='D';
					}
				} 
		    	if(i!=(N-1))
				{
					if(str[i+1][j]=='O')  //下 
					{
		            	str[i+1][j]='D'; 
					}
                    
				}

	           if(j!=0) 
			   { 
				   str[i][j-1]='X';      //左 
	           }
	   	   } 
        }
	 //D在周期结束后转换为X 
	   for(i=0;i<N;i++)
         for(j=0;j<M;j++)
		 {
		     if(str[i][j]=='D')
	         str[i][j]='X';
	     }
}
	 
	 
		for(i=0;i<N;i++)
	       cout<<str[i]<<endl;
    return 0;  
}

