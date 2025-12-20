
/*
A very good application of Bellman ford
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<int>> g(n + 1);
    vector<int> relaxant(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> edge{x, y, z};
        edges.push_back(edge);
        g[y].push_back(x);
    }
    vector<int> dist(n + 1, 0);

    int x = -1;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (auto edge : edges)
        {

            int update = min(dist[edge[1]], dist[edge[0]] + edge[2]);
            if (dist[edge[1]] != update)
            {
                dist[edge[1]] = update;
                relaxant[edge[1]] = edge[0];
                x = edge[1];
            }
        }
    }
    //Can do all n at a time x!=-1 indicates update in last iteration

    
    if (x == -1)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        x = relaxant[x];
    }
    // this are excess and can be optimized

    cout << "YES\n";
    
    int curr = relaxant[x];
    vector<int> ans;

    ans.push_back(x);

    while (curr != x)
    {
        // cout<<curr<<' ';
        ans.push_back(curr);
        curr = relaxant[curr];
    }
    ans.push_back(x);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    cout << " \n";

    return 0;
}