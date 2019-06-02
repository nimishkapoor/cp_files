#include<bits/stdc++.h>
using namespace std;

int n,m,t1,t2;
vector<int> adj[100100],out[2];
bool col[100100],vis[100100],ans;

void dfs(int s,bool c=0){
    if(vis[s] && col[s]!=c){cout<<s<<endl;ans=1;}
    if(vis[s])return;
    vis[s]=1;
    col[s]=c;
    out[c].push_back(s);
    for(int i : adj[s]){
        dfs(i,!c);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        scanf("%d%d",&t1,&t2);
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        dfs(i);
    }
    if(ans){
        cout<<"-1\n";
        return 0;
    }
    for(int i=0; i<2; i++){
        cout<<out[i].size()<<"\n";
        for(int j : out[i]){
            cout<<j<<" ";
        }cout<<"\n";
    }
    return 0;
}
