#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxsize 100

void main()
{
	int M,N,c;
	int i,j,m,n,k=0,count=0;
	char a[maxsize][maxsize]={0};
	char (*p)[4]=0;
	cout<<"输入地图的列数和行数：";
	cin>>M>>N;
	printf("输入感染信号\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
            cin>>a[i][j];  
        }
		
    }
/*	for(i=0; i<N; i++)
	{
        for(j=0; j<M; j++)
		{
            cout<<a[i][j];  
        }
		cout<<endl;
    }
*/
	cout<<"输入周期数：";
	cin>>c;	
while(k<c)
{
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
           if(a[i][j]=='X')
		   {	
			   {	if(a[i-1][j]=='O')
						a[i-1][j]='m';
					if(a[i+1][j]=='O')		
						a[i+1][j]='m';	   
					if(a[i][j+1]=='O')
						a[i][j+1]='m';
					if(a[i][j-1]=='O')
						a[i][j-1]='m';		
				 }		
		   }
        }
		
    }
	k++;
for(m=0; m<N; m++)
{
	for(n=0; n<M; n++)
	{
		if(a[m][n]=='m')
		a[m][n]='X';
	}
}	
}

	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
            cout<<a[i][j];  
        }
		cout<<endl;
	}

}
