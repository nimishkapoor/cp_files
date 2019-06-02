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
#define endl "\n"

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
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int k;
	cin>>k;
	
	string s1;
	string s2;
	
	cin>>s1;
	cin>>s2;
	
	vii v;
	queue<int> li[26],ri[26];
	queue<int> lq,rq;
	
	int l[26]={0};
	int r[26]={0};
	
	int lc=0,rc=0;
	for(int i=0;i<k;i++)
	{
		if(s1[i]=='?')
		{
			lc++;
			lq.push(i+1);
			continue;
		}
		l[s1[i]-'a']++;
		li[s1[i]-'a'].push(i+1);
	}
    for(int i=0;i<k;i++)
	{
		if(s2[i]=='?')
		{
			rq.push(i+1);
			rc++;
			continue;
		}
		r[s2[i]-'a']++;
		ri[s2[i]-'a'].push(i+1);
	}
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		cnt+=min(l[i],r[i]);
		int t=min(l[i],r[i]);
		for(int j=0;j<t;j++)
		{
			v.pb(mp(li[i].front(),ri[i].front()));
			li[i].pop();
			ri[i].pop();
		}
		l[i]-=min(l[i],r[i]);
		r[i]-=min(l[i],r[i]);
	}
	
	int sl=0;
	int trc=rc;
	for(int i=0;i<26;i++)
	{
		sl+=l[i];
		bool f=0;
		for(int j=0;j<min(l[i],trc);j++)
		{
			if(rq.empty())
			{
				f=1;
				break;
			}
			if(li[i].empty())
			{
				f=1;
				break;
			}
			v.pb(mp(li[i].front(),rq.front()));
			li[i].pop();
			rq.pop();
		}
		if(f==0)
		{
			trc-=min(trc,l[i]);
		}
		if(trc<=0)
		{
			break;
		}
	}
	cnt+=min(sl,rc);
	rc=max(0,rc-sl);
	
	int sr=0;
	int tlc=lc;
	for(int i=0;i<26;i++)
	{
		sr+=r[i];
		bool f=0;
		for(int j=0;j<min(r[i],tlc);j++)
		{
			if(lq.empty())
			{
				f=1;
				break;
			}
			if(ri[i].empty())
			{
				f=1;
				break;
			}
			v.pb(mp(lq.front(),ri[i].front()));
			ri[i].pop();
			lq.pop();
		}
		if(f==0)
		{
			tlc-=min(tlc,r[i]);
		}
		if(tlc<=0)
		{
			break;
		}
	}
	cnt+=min(sr,lc);
	lc=max(0,lc-sr);
	cnt+=min(lc,rc);
	for(int i=0;!lq.empty() && !rq.empty();i++)
	{
		v.pb(mp(lq.front(),rq.front()));
		lq.pop();
		rq.pop();
	}
	
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].fr<<" "<<v[i].sc<<endl;
	}
	return 0;
}
