#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define rep(n) for(int i=0; i<n; i++)
#define repc(i, n) for(int i=0; i<n; i++)
#define rep1(n) for(int i=1; i<=n; i++)
#define repc1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a+n
//~ #define endl "\n" 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;

ll divn(ll a, ll b)
{
	ll x = a/b;
	if(a%b)
	{
		x++;
	}
	return x;
}

void input(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
//.............................................................
bool isprime(int n)
{
	if(n>3)
	if((n+1)%6 !=0 && (n-1)%6 !=0)
		return false;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)	
			return false;
	}
	return true;
}


int main()
{
	
	ll n;
	cin>>n;
	ll m = n;
	int d = 0;
	vector<int> a;
	while(m)
	{
		a.pb(m%10);
		m/=10;
		d++;

	}
	reverse(all(a));

	ll p = 1;
	ll p1 = pow(9, d-1);
	vector<int> ans(d, 1);
	repc(j,d)
	{
	rep(d)
	{
		// if(a[i]>a[i-1])
		// 	a[i]=1;
		if(a[i]==0 || a[i]==1)
		{
			// cout<<j;
			if(i>0)
			{
				ans[i-1]--;
			}
			else
			{
				ans[i]=1;
				i++;
			}
			while(i<d)
			{
				ans[i]=9;
				i++;
			}
			break;
		}
		ans[i]=a[i];
	}
	rep(d)
	{
		p *= ans[i];
	}
	// cout<<p<<endl;
	p1 = max(p1, p);
	p = 1;
	a[d-j-1]=1;
	
	}
	cout<<p1;
	return 0;

}

