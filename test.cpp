#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
#define watch(x) cout << (#x) << " is " << (x) << endl
 
int main(){
	int h,w;
	cin>>h>>w;
 
	int a[h+5][w+5];
	int row[h];
	int col[w];
	for(int i=0;i<h;i++){
		cin>>row[i];
	}
	for(int i=0;i<w;i++){
		cin>>col[i];
	}
	long long count=1;
	long long ans=0;
	
	int cnt=0;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(j>row[i]&&i>col[j]){
				count=(count*2)%p;cnt++;
			}
			else if(row[i]==j&&col[j]>i)
			{
				cout<<"0"<<endl;
				return 0;
			}
			else if(row[i]>j&&col[j]==i){
				cout<<"0"<<endl;
				return 0;
			}
		}
	}
	
	watch(cnt);
	ans=pow(2,cnt);
	watch(ans);
	ans%=p;
	cout<<ans<<endl;
		cout<<count<<endl;
	return 0;
}
