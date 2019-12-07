#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		
		int mx1=0;
		int mx2=0;
		int mx3=0;
		
		vector<int> v;
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			v.push_back(a[i]);
		}
		
		auto it=unique(v.begin(),v.end());
		
		v.resize(distance(v.begin(),it));
		
		mx1=v[0];
		mx2=v[1];
		mx3=v[2];
		
		int g=0,s=0,b=0;
		
		int i=0;
		
		int mid;
		if(n%2!=0)
		{
			mid=(n/2)-1;
		}
		else
		{
			mid=(n/2)-1;
		}
		
		
		if(a[mid+1]<mx1)
		{
			while(a[i]==mx1)
			{
				g++;
				i++;
			}
		}
		int in=i;
		
		if(a[mid]!=a[mid+1])
		{
			int j;
			i--;
			for(j=mid;j>mid-(g+1);j--)
			{
				b++;
			}
			while(a[j]==a[j+1])
			{
				b++;
				j--;
			}
			for(j;j>i;j--)
			{
				s++;
			}
		}
		else
		{
			while(a[i]>a[mid])
			{
				i++;
			}
			i--;
			in--;
			mid=i;
			int j;
			for(j=mid;j>mid-(g+1);j--)
			{
				b++;
			}
			while(a[j]==a[j+1])
			{
				b++;
				j--;
			}
			for(j;j>in;j--)
			{
				s++;
			}
			
		}
		
		if(g==0 || s==0 || b==0 || b<=g || s<=g)
		{
			cout<<0<<" "<<0<<" "<<0<<endl;
			continue;
		}

		cout<<g<<" "<<s<<" "<<b<<endl;
	}
	return 0;
}
