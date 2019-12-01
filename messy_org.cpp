#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		string t="";
		for(int i=0;i<k-1;i++)
		{
			t+="()";
		}
		int d=s.size()-t.size();
		for(int i=0;i<d/2;i++)
		{
			t+="(";
		}
		for(int i=0;i<d/2;i++)
		{
			t+=")";
		}
		cout<<n<<endl;
	
		for(int i=0;i<n;i++)
		{//watch(t);watch(s);
			if(t[i]==s[i])
			{
				cout<<i+1<<" "<<i+1<<endl;
			}
			else
			{
				for(int j=i;j<n;j++)
				{
					if(t[i]==s[j])
					{
						for(int k=i;k<=(i+j)/2;k++)
						{
							char tmp=s[k];//watch(tmp);
							s[k]=s[j-(k-i)];//watch(s[k]);
							s[j-(k-i)]=tmp;//watch(s[j-(k-i)]);
						}
						cout<<i+1<<" "<<j+1<<endl;
						break;
					}
				}
			}
		}
	}
}
