#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		ll x=max(a,b);
		ll y=min(a,b);
		ll dif=(x-y);
		ll ans=0;
		ans+=dif/5;
		if(dif>=5)
		{
			dif-=5*ans;
		}
		ans+=dif/2;
		if(dif>=2)
		{
			dif-=2*(dif/2);
		}
		if(dif==1)
		{
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
