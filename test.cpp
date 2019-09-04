#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
const int N=2003;
char a[N][N];
int p[N][N];
int main()
{
	int n,k,i,j,b,e;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
    int sum=0;
	for(i=0;i<n;i++){ //每行
		b=e=-1; //最左最右端点
		for(j=0;j<n;j++)
			if(a[i][j]=='B'){
				if(b<0) b=j; e=j;
			}
		if(b<0) sum++;
		else if(e-b+1<=k){
            for(int ii=max(0,i-k+1);ii<=i;ii++){watch(ii);
                for(int jj=max(0,e-k+1);jj<=b;jj++){
                    p[ii][jj]++;watch(jj);}}
		}
		for(int l=0;l<n;l++)
		{
			for(int m=0;m<n;m++)
			{
				cout<<p[l][m]<<" ";
			}
			cout<<endl;
		}
		cout<<"*********"<<endl;
		
	}
	
	cout<<"____________"<<endl;
	for(i=0;i<n;i++){ //每列
		b=e=-1;
		for(j=0;j<n;j++)
			if(a[j][i]=='B'){
				if(b<0) b=j; e=j;
			}
        if(b<0) sum++;
		else if(e-b+1<=k){
            for(int ii=max(0,i-k+1);ii<=i;ii++)
                for(int jj=max(0,e-k+1);jj<=b;jj++)
                    p[jj][ii]++;
		}
		for(int l=0;l<n;l++)
		{
			for(int m=0;m<n;m++)
			{
				cout<<p[l][m]<<" ";
			}
			cout<<endl;
		}
		cout<<"*********"<<endl;
	}
	int ans=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ans=max(ans,p[i][j]);
	printf("%d\n",sum+ans);
	return 0;
}
