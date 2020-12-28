#include"iostream"
using namespace std;
//存在运行时数组下标越界的问题,但是编译器不报错,依然可以得到正确的结果,可能是c/c++更注重运行时的效率,不会再去检查这种问题
int main(){
int N,M,C;
int m=0;
char a[100][100];
int f1[10],f2[10];
cout<<"请输入地图长度N*M"<<endl;
cin>>N>>M;
for(int i = 0;i < N; i++)
for(int j = 0;j < M; j++)
     cin>>a[i][j];
cout<<"输入循环周期数C"<<endl;
cin>>C;
for(int p = 0; p < C; p++){
	for(int s = 0; s < N; s++){
		for(int d = 0;d < M; d++){
			if(a[s][d] == 'X'){
				f1[m] = s;
				f2[m] = d;
				m++;//找到所有X的下标
			}
		}
	}
	for(int flag = 0; flag < m ; flag++){
		if(a[f1[flag]-1][f2[flag]]!='P')
		a[f1[flag]-1][f2[flag]] = 'X';
        if(a[f1[flag]+1][f2[flag]]!='P')
		a[f1[flag]+1][f2[flag]] = 'X';
		if(a[f1[flag]][f2[flag-1]]!='P')
		a[f1[flag]][f2[flag]-1] = 'X';
		if(a[f1[flag]][f2[flag]+1]!='P')
		a[f1[flag]][f2[flag]+1] = 'X';
	}
	m = 0;
}
for(int i1 = 0;i1 < N; i1++){
	for(int j1 = 0;j1 < M; j1++){
		cout<<a[i1][j1];}
	cout<<endl;
}
return 0;
}
