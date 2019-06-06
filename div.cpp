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
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int a[1000006];
	
	set<int> prime;
	
	clr(a);
	
	for(int i=1;i<1000001;i++)
	{
		for(int j=i;j<1000001;j+=i)
		{
			a[j]++;
		}
		if(a[i]==2)
		{
			prime.insert(i);
		}
	}
	
	vi ans;
	for(int i=1;i<1000001;i++)
	{
		if(a[i]>2)
		{
			for(auto j=prime.begin();j!=prime.end();j++)
			{
				int tmp=*j;
				if(tmp>a[i])
				{
					break;
				}
				
				if(a[i]%tmp==0)
				{
					if(prime.find(a[i]/tmp)!=prime.end() && (a[i]/tmp!=tmp))
					{
						ans.pb(i);
						break;
					}
				}
			}
		}
	}
    
    for(int i=8;i<ans.size();i+=9)
    {
		cout<<ans[i]<<endl;
	}
    
    
	return 0;
}
