#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n+1];
		
		int mn1=INT_MAX;
		int mn2=INT_MAX;
		int i1,i2;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<=mn1)
			{
				mn1=a[i];
				i1=i;
			}
			if(a[i]<=mn2 && a[i]>mn1)
			{
				mn2=a[i];
				i2=i;
			}
		}
		
		if(m<n || n==2)
		{
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		vector<pair<int,int> > v;
		for(int i=1;i<n;i++)
		{
			v.push_back(make_pair(i,i+1));
			ans+=(a[i]+a[i+1]);
		}
		v.push_back(make_pair(n,1));
		ans+=(a[n]+a[1]);
		int rem=m-v.size();
		for(int i=0;i<rem;i++)
		{
			v.push_back(make_pair(i1,i2));
			ans+=(mn1+mn2);
		}
		cout<<ans<<endl;
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i].first<<" "<<v[i].second<<endl;
		}
	}
	return 0;
}
