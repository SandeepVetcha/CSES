#include <bits/stdc++.h>
using namespace std;


bool possible = false;

void dfs(int x,vector<vector<int>> &g,vector<int>& parent,vector<bool> &vis){
    vis[x]=true;
    for(int child: g[x]){
        if(vis[child] && parent[x] != child){
            
            possible =true;
            int curr = x;
            vector<int> ans;
            while(curr != child){
             ans.push_back(curr);
             curr = parent[curr]; 


            }
            cout<<ans.size()+2<<"\n";
            cout<<child<<" ";
            for(int x: ans) cout<<x<<" ";
            cout<<child<<" ";
            exit(0);
        }

        if(!vis[child]){
            parent[child] =x;
            dfs(child,g,parent,vis);
        }


    }

}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> parent(n + 1, 0);
    vector<bool> vis(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,g,parent,vis);
    }
    if(!possible) cout<<"IMPOSSIBLE\n";



    return 0;
}