#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool bfs(vector<vector<ll>> &redcap, vector<set<int>> &g, int n, vector<int> &parent)
{
    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1, false);
    vis[1] = true;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int child : g[top])
        {
            if (redcap[top][child] && !vis[child])
            {
                parent[child] = top;
                if (child == n)
                    return true;
                vis[child] = true;
                q.push(child);
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;


    vector<vector<ll>> recidCap(n + 1, vector<ll>(n + 1, 0));
    vector<set<int>> g(n + 1);
    vector<int> parent(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll c;
        cin >> x >> y >> c;
        recidCap[x][y] += c;
        g[x].insert(y);
        g[y].insert(x);
    }

    ll maxflow = 0;

    while (bfs(recidCap, g, n, parent))
    {

        // find path flow
        ll pathflow = LLONG_MAX;
        int temp = n;
        while (temp != 1)
        {
            pathflow = min(pathflow, recidCap[parent[temp]][temp]);
            temp = parent[temp];
        }

        // adjust recidual capacities
        temp = n;
        while (temp != 1)
        {
            recidCap[parent[temp]][temp] -= pathflow;
            recidCap[temp][parent[temp]] += pathflow;
            temp = parent[temp];
        }

        maxflow += pathflow;
        parent.assign(n + 1, 0);
    }

    cout<<maxflow;

    return 0;
}