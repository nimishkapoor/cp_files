#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl 
int fun(int x)
{
	x--;
	return (x*(x+1))/2;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n;
		int in[n+1];
		in[0]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			in[x]=i;
		}
		cout<<1;
		int l=in[1];
		int r=in[1];
		for(int i=2;i<=n;i++)
		{
			l=min(l,in[i]);
			r=max(r,in[i]);
			if(r-l+1==i)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		cout<<endl;
	}
}
