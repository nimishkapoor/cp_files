#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define gcd __gcd
#define nof1 __builtin_popcountll
#define nofleading_zerosull __builtin_clzll

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<long long int> vl;

const double pi = 2 * acos(0.0);
const int inf = 0x3f3f3f3f;//(ll) 9e18
const double infd = 1.0/0.0;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a+n
//#define endl "\n"

long long power(long long x, long long y,long long MOD)
{
	long long res = 1; 
	x = x % MOD; 

	while (y > 0)
	{
		if (y & 1)
		res = (res*x) % MOD;
		y = y>>1;
		x = (x*x) % MOD;
	}
	return res;
}
long long mul(long long a,long long b,long long MOD)
{
	if(b==1)
	{
		return a;
	}	
	if(b%2==0)
	{
		return 2*(mul(a,b/2,MOD)%MOD);
	}
	else
	{
		return (a+(2*(mul(a,b/2,MOD))%MOD))%MOD;
	}
}

/*ll ncr[6001][6001];
void nCr(long long MOD)
{
	for(ll i=0;i<=6000;i++)
	{
		for(ll k=0;k<=6000;k++)
		{
			if(k<=i)
			{
				if((k==0)||(k==i))
				ncr[i][k]=1;
				else
				ncr[i][k]=(ncr[i-1][k-1]+ncr[i-1][k])%MOD;
			}
		}
	} 
}

ll inv[100005];
void mulmodinv(long long MOD)
{
	inv[1]=1;
	inv[0]=1;
	for(int i = 2; i <= 100005; i++)
	inv[i] = inv[MOD % i]*(MOD-MOD / i) % MOD;
}*/

bool ispow2(ll n)
{
	if(((n & (n-1)) == 0) && n!=0)
	{
		return true;
	}
	return false;
}
bool prime(int x)
{
	if(x==1)
	{
		return false;
	}
	if(x==2)
	{
		return true;
	}
	if(x%2==0)
	{
		return false;
	}
	for(int i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
		{
			return false;
		}
	}
 return true;
}
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 
int coprime(int a, int b) 
{ 
	if(a==b)
		return 0;
    if(prime(a) && prime(b)) 
        return 1; 
    if((a==2 && b%2!=0) ||(b==2 && a%2!=0))
		return 1;
	if((a%2!=0 && prime(b) && a<b ) || (b%2!=0 && prime(a) && a>b))
		return 1;
	if(abs(a-b)==1)
		return 1;
	if(a==1 || b==1)
		return 1;
	return gcd(a,b);
}
unsigned long long lcm (unsigned a, unsigned b)
{
    return ((unsigned long long) a) * (b / gcd(a, b));
}
//======================================================================
int n,m,x,y;
float w;
int  dist[100005];
int vis[100005];
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin>>n;
	
	while(n!=0)
	{
		clr(vis);
		clr(dist);
		cin>>m;
		vii g[n+1];
		int par[100005];
		int wt[100005];
		memset(par,-1, sizeof(par));
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>w;
			g[x].pb(mp(y,w));
			g[y].pb(mp(x,w));
		}
		priority_queue<pair<ll,ll>, vector<pair<ll,ll> > > max_heap;
		max_heap.push(mp(0,1));
		double ans=1.0;
		while(!max_heap.empty())
		{
			ll tp=max_heap.top().sc;
			max_heap.pop();
			if(!vis[tp])
			{
				vis[tp]=1;
				for(int i=0;i<g[tp].size();i++)
				{
					if(!vis[g[tp][i].fr])
					{
						if(dist[g[tp][i].fr]<dist[tp]+g[tp][i].sc)
						{
							dist[g[tp][i].fr]=dist[tp]+g[tp][i].sc;
							max_heap.push(mp(dist[g[tp][i].fr],g[tp][i].fr));
							par[g[tp][i].first]=tp;
							wt[g[tp][i].first]=g[tp][i].second;
						}
					}
				}
			}
		}
		int i=n;
		cout<<setprecision(6)<<fixed;
		while(par[i]!=-1)
		{
			//watch(wt[i]);
			ans*=((double)wt[i]/100.0);
			i=par[i];
		}
		//cout<<dist[n]<<endl;
		
		cout<<(double)ans*100.0<<" percent"<<endl;
		cin>>n;
	}
	return 0;
}
