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
bool fn(ll a,ll b)
{
	return a>b;
}
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
		ll n,x,y,a,b,k;
		cin>>n;
		
		ll arr[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		
		cin>>x>>a;
		cin>>y>>b;
		
		cin>>k;
		
		sort(arr+1,arr+(n+1),fn);
		
		ll tmp1[n+1];
		ll tmp2[n+1];
		
		clr(tmp1);
		clr(tmp2);
		
		int j=1;
		for(int i=a;i<=n;i+=a)
		{
			tmp1[i]=arr[j];
			j++;
		}
		for(int i=b;i<=n;i+=b)
		{
			if(j<=n)
			{
				tmp1[i]+=arr[j];
			}
			j++;
		}
		
		ll cnt1=0;
		ll sum1=0;
		
		for(int i=1;i<=n;i++)
		{
			if(sum1>k)
			{
				break;
			}
			if(i%a==0 && i%b==0)
			{
				sum1+=((x+y)*tmp1[i])/100;
			}
			else if(i%a==0)
			{
				sum1+=(x*tmp1[i])/100;
			}
			else if(i%b==0)
			{
				sum1+=(y*tmp1[i])/100;
			}
			cnt1++;
		}
		
		j=1;
		for(int i=b;i<=n;i+=b)
		{
			tmp2[i]=arr[j];
			j++;
		}
		for(int i=a;i<=n;i+=a)
		{
			if(j<=n)
			{
				tmp2[i]+=arr[j];
			}
			j++;
		}
		
		ll cnt2=0;
		ll sum2=0;
		
		for(int i=1;i<=n;i++)
		{
			if(sum2>k)
			{
				break;
			}
			if(i%a==0 && i%b==0)
			{
				sum2+=((x+y)*tmp2[i])/100;
			}
			else if(i%a==0)
			{
				sum2+=(x*tmp2[i])/100;
			}
			else if(i%b==0)
			{
				sum2+=(y*tmp2[i])/100;
			}
			cnt2++;
		}
		
		/*watch(k);
		watch(sum1);
		watch(sum2);
		watch(cnt1);
		watch(cnt2);*/
		
		if(sum1<k && sum2<k)
		{
			cout<<-1<<endl;
			continue;
		}
		
		if(sum1<k)
		{
			cout<<cnt2<<endl;
			continue;
		}
		
		if(sum2<k)
		{
			cout<<cnt1<<endl;
			continue;
		}
		
		if(sum1<sum2)
		{
			cout<<cnt1<<endl;
		}
		else
		{
			cout<<cnt2<<endl;
		}
		
	}
    
	return 0;
}
