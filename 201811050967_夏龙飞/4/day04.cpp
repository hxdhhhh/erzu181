#include"iostream"
using namespace std;
//��������ʱ�����±�Խ�������,���Ǳ�����������,��Ȼ���Եõ���ȷ�Ľ��,������c/c++��ע������ʱ��Ч��,������ȥ�����������
int main(){
int N,M,C;
int m=0;
char a[100][100];
int f1[10],f2[10];
cout<<"�������ͼ����N*M"<<endl;
cin>>N>>M;
for(int i = 0;i < N; i++)
for(int j = 0;j < M; j++)
     cin>>a[i][j];
cout<<"����ѭ��������C"<<endl;
cin>>C;
for(int p = 0; p < C; p++){
	for(int s = 0; s < N; s++){
		for(int d = 0;d < M; d++){
			if(a[s][d] == 'X'){
				f1[m] = s;
				f2[m] = d;
				m++;//�ҵ�����X���±�
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
