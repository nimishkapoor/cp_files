#include<bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<int,int> m;
	int n,x,y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		m[x]++;
	}
	for(auto it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<endl;
	}
	return 0;
}
