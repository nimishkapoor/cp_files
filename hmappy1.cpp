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
const int inf = 0x3f3f3f3f;
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
//======================================================================

int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int n,q,k,cnt,x;
	
	cin>>n>>q>>k;
	
	if(n>1000)
	{
	int arr[n];
	deque<pair<int, int> > qu;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int lm=0,om=0,s,e,tmps,mx=0,lc=0,rc=0,flag=0;
	if(arr[0]==1)
	{
		lm=1;
		om=1;
		s=0;
		e=0;
		tmps=0;
	}
	for(int i=1;i<n;i++)
	{
		if(arr[i]==1)
		{
			if(arr[i-1]==1)
			{
				lm++;
				if(om<lm)
				{
					om=lm;
					e=i;
					s=tmps;
				}
			}
			else
			{
				lm=1;
				if(om<lm)
				{
					om=lm;
					e=i;
					s=i;
				}
				tmps=i;
			}
		}
		else
		{
			lm=0;
		}
	}
	
	//watch(om);
	
	int dlm=0,dom=0;
	if(arr[0]==1 && s!=0)
	{
		dlm=1;
	}
	for(int i=1;i<n;i++)
	{
		if(i>=s && i<=e)
		{
			dlm=0;
			continue;
		}
		else
		{
			if(arr[i]==1)
			{
				if(arr[i-1]==1 && !((i-1)>=s && (i-1)<=e))
				{
					dlm++;
					dom=max(dom,dlm);
				}
				else
				{
					dlm=1;
					dom=max(dom,dlm);
				}
			}
			else
			{
				dlm=0;
			}
		}
	}
	if(dom==om)
	{
		flag=1;
	}
	//watch(dom);
	//watch(flag);
	int sm=0;
	mx=om;
	if(arr[0]==1 && arr[n-1]==1)
	{
		lc=0,rc=0;
		int li,ri;
		for(int i=0;i<n && arr[i]==1;i++)
		{
			lc++;
			li=i;
		}
		for(int i=n-1;i>=0 && arr[i]==1;i--)
		{
			rc++;
			ri=i;
		}
		if(om==(lc+rc))
		{
			flag=1;
		}
		else if(om<(lc+rc))
		{
			om=lc+rc;
			flag=0;
			for(int i=0;i<n;i++)
			{
				if((i<=li || i>=ri) && arr[i]==1)
				{
					qu.push_back(mp(arr[i],1));
				}
				else
				{
					qu.push_back(mp(arr[i],0));
				}
			}
		}
		mx=max(lc,rc);
	}
	
	
	if(qu.empty() && flag==0)
	{
		for(int i=0;i<n;i++)
		{
			if((i>= s && i<=e) && (arr[i]==1))
			{
				qu.push_back(mp(arr[i],1));
			}
			else
			{
				qu.push_back(mp(arr[i],0));
			}
		}
	}
	
	
	string qr;
	cin>>qr;
	int fr,bk;
	
	if(flag==1)
	{
		for(int i=0;i<q;i++)
		{
			if(qr[i]=='?')
			{
				cout<<(k<om?k:om)<<endl;
			}
		}
		return 0;
	}
	
	for(int i=0;i<q;i++)
	{
		//watch(mx);
		//watch(lc);
		//watch(rc);
		if(qr[i]=='?')
		{
			cout<<(k<mx?k:mx)<<endl;
		}
		else
		{
			auto it =qu.back();
			fr=qu.front().second;
			bk=qu.back().second;
			//watch(fr);
			//watch(bk);
			if(fr==0 && bk==1)
			{
				//watch(fr);
				//watch(bk);
				rc=om-1;
				lc=1;
				mx=max(lc,rc);
				mx=max(mx,dom);
			}
			else if(fr==1 && bk==1)
			{
				lc++;//watch(lc);
				rc--;//watch(rc);
				mx=max(lc,rc);
				mx=max(mx,dom);
			}
			else
			{
				mx=om;
			}
			qu.pop_back();
			qu.push_front(it);
		}
	}
	}
	
	else
	{
	int arr[n];
	deque<int> qu;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		qu.push_back(arr[i]);
	}
	string s;
	cin>>s;
	for(int i=0;i<q;i++)
	{
		if(s[i]=='?')
		{
			int lm=0,om=0,prev=0;
			auto it=qu.begin();
			if(*it==1)
			{
				lm=1;
				om=1;
				prev=1;
			}
			
			for(it++;it!=qu.end();it++)
			{
				if(*it==1)
				{
					if(prev==1)
					{
						lm++;
						om=max(lm,om);
					}
					else
					{
						lm=1;
						om=max(lm,om);
					}
				}
				else
				{
					lm=0;
				}
				prev=*it;
			}
			cout<<(k<om?k:om)<<endl;
		}
		else
		{
			auto it=qu.back();
			qu.pop_back();
			qu.push_front(it);
		}
	}
		
	}
	return 0;
}
