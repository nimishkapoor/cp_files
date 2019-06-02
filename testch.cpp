#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main()
{
	int n,q,k,count;
	string str;
	cin>>n>>q>>k;
	bitset<MAX>s,c;
//inserting bits in array
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		s[i]=temp;
	}
	cin>>str;
	for(int i=0;i<q;i++)
	{
	//making duplicate bitset
		c=s;
		if(str[i]=='?')
		{
			count=0;
			while(c!=0)
			{
	//using bitmask to count maximum no of continuous 1's-O(1's bit)
				c=(c&(c<<1));
				count++;
			}
			if(count>k)
				cout<<k<<"\n";
			else
				cout<<count<<"\n";
		}
		else
		{
		//shifting each bit to right and updating first bit with previous last bit
			bool lb=s[n-1];
			s=s>>1;
			s[n-1]=lb;
		}
	}
	return 0;
}
