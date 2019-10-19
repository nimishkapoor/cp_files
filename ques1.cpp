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

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll l,r,v;
		ll mk[1000000006];
		clr(mk);

		vector<map<ll,ll> > s(2005);
		vector<set<ll> > st(2005);
		for(int i=0;i<n;i++)
		{
			cin>>l>>r>>v;
			for(int j=l;j<r;j++)
			{
				mk[j]++;
				s[j][v]++;
				st[j].insert(v);
			}
			
		}

		bool f=0;
		for(int i=0;i<=1000000001;i++)
		{
			if(mk[i]>=3)
			{
				for(auto it=st[i].begin();it!=st[i].end();it++)
				{
					//watch(*it);
					//watch(s[i][*it]);
					if(s[i][*it]>2)
					{
						f=1;
						break;
					}
				}
			}
		}
		if(f==0)
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
