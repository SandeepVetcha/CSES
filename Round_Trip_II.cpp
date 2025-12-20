#include <bits/stdc++.h>
using namespace std;

bool possible = false;

void dfs(int x, vector<vector<int>> &g, vector<int> &parent, vector<bool> &vis, vector<bool> &samevis)
{
    vis[x] = true;
    samevis[x] = true;
    for (int child : g[x])
    {

        if (vis[child] && samevis[child])
        {

            possible = true;
            int curr = x;
            vector<int> ans;
            while (curr != child)
            {
                ans.push_back(curr);
                curr = parent[curr];
            }
            cout << ans.size() + 2 << "\n";
            reverse(ans.begin(), ans.end());
            cout << child << " ";
            for (int xi : ans)
                cout << xi << " ";
            cout << child << " ";
            exit(0);
        }

        if (vis[child])
            continue;

        parent[child] = x;
        dfs(child, g, parent, vis, samevis);
    }
    parent[x] = 0;
    samevis[x] = 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> parent(n + 1, 0);
    vector<bool> vis(n + 1, false);
    vector<bool> samevis(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, g, parent, vis, samevis);
    }
    if (!possible)
        cout << "IMPOSSIBLE\n";

    return 0;
}