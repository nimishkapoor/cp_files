#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
		int n,m;
		cin>>n;
		m=n;
		int a[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
			}
		}
		
		int k=0,l=0;
		
		int tot=n*m;
		int cnt=0;
		bool f=0;
		//cout<<1<<endl;
		while(cnt<=tot)
		{
			for(int i=l;i<m;i++)
			{
				if(cnt>=tot)
				{
					f=1;
					break;
				}
				cout<<a[k][i]<<" ";
				cnt++;
			}
			if(f==1)
			{
				break;
			}
			k++;
			for(int i=k;i<n;i++)
			{
				if(cnt>=tot)
				{
					f=1;
					break;
				}
				cout<<a[i][m-1]<<" ";
				cnt++;
			}
			if(f==1)
			{
				break;
			}
			m--;
			for(int i=m-1;i>=l;i--)
			{
				if(cnt>=tot)
				{
					f=1;
					break;
				}
				cout<<a[n-1][i]<<" ";
				cnt++;
			}
			if(f==1)
			{
				break;
			}
			
			n--;
			for(int i=n-1;i>=k;i--)
			{
				if(cnt>=tot)
				{
					f=1;
					break;
				}
				cout<<a[i][l]<<" ";
				cnt++;
			}
			if(f==1)
			{
				break;
			}
			l++;
			if(cnt>=tot)
			{
				break;
			}
		}
		cout<<endl;
	}
	
	return 0;
}
