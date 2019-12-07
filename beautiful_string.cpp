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
//dont use inbuilt ceil
//use (a+b-1)/b instead.
//======================================================================
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    
    int t;
    cin>>t;
    while(t--)
    {
		string s;
		cin>>s;
		bool f=0;
		for(int i=1;i<s.size();i++)
		{
			if(s[i]==s[i-1] && s[i]!='?')
			{
				cout<<-1<<endl;
				f=1;
				break;
			}
		}
		if(f==1)
		{
			continue;
		}
		s+='*';
		char prev='*';
		char next='*';
		for(int i=0;i<s.size();i++)
		{
			int in=i;
			if(s[i]=='?')
			{
				int cnt=0;
				while(s[i]=='?')
				{
					cnt++;
					i++;
				}
				next=s[i];
				if(prev=='*')
				{
					if(next=='a')
					{
						prev='b';
					}
					if(next=='b')
					{
						prev='c';
					}
					if(next=='c')
					{
						prev='a';
					}
				}
				if(next=='*')
				{
					if(prev=='*')
					{
						prev='a';
					}
					next='a';
				}
				if(cnt%2==0)
				{//watch(1);
					if(prev=='a' && next=='a')
					{//watch(2);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='b';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='b' && next=='b')
					{//watch(3);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='c' && next=='c')
					{//watch(4);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='b';
							}
							tmp++;
						}
					}
					
					if(prev=='a' && next=='b')
					{//watch(5);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='b';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='a' && next=='c')
					{//watch(6);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='c';
							}
							else
							{
								s[j]='b';
							}
							tmp++;
						}
					}
					if(prev=='b' && next=='c')
					{//watch(7);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='c';
							}
							else
							{
								s[j]='a';
							}
							tmp++;
						}
					}
					if(prev=='c' && next=='b')
					{//watch(8);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='b';
							}
							else
							{
								s[j]='a';
							}
							tmp++;
						}
					}
					if(prev=='b' && next=='a')
					{//watch(9);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='c' && next=='a')
					{//watch(10);
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='b';
							}
							tmp++;
						}
					}
					
				}
				else
				{
					if(prev=='a' && next=='a')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='b';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='b' && next=='b')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='c' && next=='c')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='b';
							}
							tmp++;
						}
					}
					if(prev=='a' && next=='b')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='c';
							}
							else
							{
								s[j]='b';
							}
							tmp++;
						}
					}
					if(prev=='a' && next=='c')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='b';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='b' && next=='c')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='c';
							}
							tmp++;
						}
					}
					if(prev=='c' && next=='b')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='a';
							}
							else
							{
								s[j]='b';
							}
							tmp++;
						}
					}
					if(prev=='b' && next=='a')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='c';
							}
							else
							{
								s[j]='a';
							}
							tmp++;
						}
					}
					if(prev=='c' && next=='a')
					{
						int tmp=0;
						for(int j=in;j<in+cnt;j++)
						{
							if(tmp%2==0)
							{
								s[j]='b';
							}
							else
							{
								s[j]='a';
							}
							tmp++;
						}
					}
				}
				i--;
			}
			prev=s[in];
		}
		s=s.substr(0,s.size()-1);
		cout<<s<<endl;
	}
	return 0;
}
