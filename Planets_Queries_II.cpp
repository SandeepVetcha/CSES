#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &tel, vector<vector<int>> &nxt, vector<int> &dis, vector<bool> &vis)
{
    if (vis[node])
        return;
    vis[node] = true;
    dfs(tel[node], tel, nxt, dis, vis);
    dis[node] = 1 + dis[tel[node]];
}

int steps(int a, int k, vector<vector<int>> &nxt)
{
    if(k<0) return 0;
    int cur = a;
    for (int i = 0; i < 18; i++)
    {
        if (k & (1 << i))
        {
           // cout<<" step "<<i<<"\n";
            cur = nxt[i][cur];
        }
    }
    return cur;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> tel(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> tel[i];

    // Building pow step dp
    vector<vector<int>> nxt(18, vector<int>(n + 1));





    vector<int> dis(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
        nxt[0][i] = tel[i];

     for(int i=1;i<18;i++){
        for(int j=1;j<=n;j++)
        nxt[i][j]=nxt[i-1][nxt[i-1][j]];
     }   
    for (int i = 1; i <= n; i++)
        if (dis[i] == 0)
            dfs(i, tel, nxt, dis, vis);

    // for (int i = 1; i <= n; i++)
    //     cout<<dis[i]<<" ";
            
        
    cout<<"\n";    
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;


        int cycle_entry=steps(a,dis[a],nxt);
        
       
        if(steps(a,dis[a]-dis[b],nxt) == b) cout<<dis[a]-dis[b]<<"\n";
        else if (b == steps(cycle_entry, dis[cycle_entry]-dis[b], nxt))

            cout << dis[cycle_entry]-dis[b]+dis[a] << "\n";

        else
            cout << -1 << "\n";
    }

    return 0;
}