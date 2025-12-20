#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, 0);

    queue<int> q;
    q.push(1);
    vis[1] = true;
    bool possible = false;

    while (!q.empty())
    {

        if (possible)
            break;
        int front = q.front();
        q.pop();
        for (int x : g[front])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
                parent[x] = front;
                if (x == n)
                {
                    possible = true;
                    break;
                }
            }
        }
    }

    if (!possible)
        cout << "IMPOSSIBLE\n";
    else
    {

        int curr = n;
        vector<int> ans;

        while (curr != 1)
        {
            ans.push_back(curr);
            curr = parent[curr];
        }

        cout << ans.size() + 1 << "\n";
        cout << 1 << " ";
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}