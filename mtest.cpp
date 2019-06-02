#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORI(i,b,a) for(int i=b;i>=a;--i)

int t[30];
int g[30];

int main()
{
	int n;
	t[0]=1;t[1]=0;t[2]=3;
	g[0]=0;g[1]=1;g[2]=0;
	FOR(i,3,31)
	{
		t[i]=2*t[i-2]+g[i-1]+g[i-3];
		g[i]=t[i-1]+g[i-2];
	}

	while(cin>>n)
	{
		if(n==-1) break;
		cout<<t[n]<<endl;

	}
}

