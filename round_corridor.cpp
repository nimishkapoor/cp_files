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

/*long long power(long long x, long long y,long long MOD)
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
}*/

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
long double gcd(long double a, long double b) 
{ 
    if (b == 0) 
        return a;
    long long int x=a,y=b; 
    return gcd(y, x % y);  
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
ll mulmod(ll a,ll b,ll c){
    ll x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
ll power(ll a,ll b,ll n){
	if(b==0)
		return 1;
	if(b==1) return a%n;
		ll c=power(a,b/2,n);
		ll p=mulmod(c%n,c%n,n);
		if(b%2==0)
			return p;
		else
			 return (mulmod(p,a,n));
}
bool fermat_prime(ull x)
{
	if(x==2 || x==3)
	{
		return 1;
	}
	if(x<=3 || x==4)
	{
		return 0;
	}
	
	for(int i=1;i<=2;i++)
	{
		ull a=2+rand()%(x-4);
		if(gcd(x,a)!=1)
		{
			return 0;
		}
		if(power(a,x-1,x)!=1)
		{
			return 0;
		}
	}
	return 1;
}
//======================================================================
vector<long double> a;
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	long double n,m,q;
	cin>>n>>m>>q;
	long double g=gcd(n,m);
	//watch(g);
	
	if(n==m)
	{
		long double x1,y1,x2,y2,s1,s2;
		while(q--)
		{
			cin>>x1>>y1>>x2>>y2;
			if(y1==y2)
			{
				cout<<"YES"<<endl;
			}	
			else
			{
				cout<<"NO"<<endl;
			}
		}
		return 0;
	}
	
	for(long double i=1;i<=g;i++)
	{
		//watch((double)i/g);
		a.pb((long double)i/g);
	}
	
	/*for(int i=0;i<g;i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;*/
	
	long double x1,y1,x2,y2,s1,s2;
	while(q--)
	{
		long double tmp,lb,ub;
		cin>>x1>>y1>>x2>>y2;
		if(x1==1)
		{
			auto it=lower_bound(all(a),(long double)y1/n);//watch((double)y1/n);
			ub=*it;//watch(ub);
			lb=ub-((long double)1/g);//watch(lb);
		}
		else
		{
			auto it=lower_bound(all(a),(long double)y1/m);//watch((double)y1/m);
			ub=*it;//watch(ub);
			lb=ub-(1/g);//watch(lb);
		}
		if(x2==1)
		{
			tmp=(long double)y2/n;
		}
		else
		{
			tmp=(long double)y2/m;
		}//watch(tmp);
		
		if(lb<tmp && tmp<=ub)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
    
	return 0;
}
