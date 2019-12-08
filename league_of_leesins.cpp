#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
const int maxn=1e5+10;
int cnt[maxn],a[maxn][4],ans[maxn];
set<int> s[maxn];
int main()
{
	int n,x,y,z;
	cin>>n;
	
	
	for(int i=1;i<=n-2;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			cnt[a[i][j]]++;
			s[a[i][j]].insert(i);
		}
	}
	
	
	
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==1)
		{
			if(ans[1]==0)
			{
				ans[1]=i;
			}
			else
			{
				ans[n]=i;
			}
		}
	}
	
	int x1=0,x2=0;
	int tmp=ans[1];
	int it=*s[tmp].begin();
	s[tmp].erase(it);
	for(int i=1;i<=3;i++)
	{
		if(a[it][i]!=tmp)
		{
			if(x1==0)
			{
				x1=a[it][i];
			}
			else
			{
				x2=a[it][i];
			}
		}
	}
	cnt[tmp]--;
	cnt[x1]--;
	cnt[x2]--;
	s[x1].erase(it);
	s[x2].erase(it);
	if(cnt[x2]==1)
	{
		swap(x1,x2);
	}
	ans[2]=x1;
	x1=x2;
	for(int i=2;i<n;i++)
	{
		tmp=ans[i];
		x2=0;
		it=*s[tmp].begin();
		for(int j=1;j<=3;j++)
		{
			if(a[it][j]!=tmp && a[it][j]!=x1)
			{
				x2=a[it][j];
			}
		}
		ans[i+1]=x1;
		s[x1].erase(it);
		s[x2].erase(it);
		cnt[x1]--;
		cnt[x2]--;
		x1=x2;
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
