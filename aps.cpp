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


//======================================================================
ll a[10000007];
ll dp[10000007];
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    clr(dp);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	a[0]=a[1]=0;
	for(ll i=2;i<=10000007;i+=2)
	{
		a[i]=2;
	}
	for(ll i=3;i<=10000007;i+=2)
	{
		if(a[i]==0)
		for(ll j=i;j<=10000007;j+=i)
		{
			if(a[j]==0)
			{
				a[j]=i;
			}
		}
	}
	
	dp[0]=dp[1]=0;

	for(int i=2;i<=10000007;i++)
	{
		dp[i]=dp[i-1]+a[i];
	}
	
	int t;
	cin>>t;
	
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
    
	return 0;
}
