#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


ull power(ull x, ull y,ull MOD)
{
	ull res = 1;  
	x=x%MOD;

	while (y > 0)
	{
		if (y & 1)
		res = (res*x)%MOD;
		y = y>>1;
		x = (x*x)%MOD;
	}
	return res;
}

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
		ull a,b;
		cin>>a>>b;
		cout<<power(a,b,10)%10<<endl;
	}
    
	return 0;
}

