#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> team(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    bool possible = true;

    for (int i = 1; i <= n; i++)
    {
        if (!possible)
            break;
        if (team[i] == 0)
        {
            team[i] = 1;
            q.push(i);

            while (!q.empty())
            {

                if (!possible)
                    break;
                int front = q.front();
                q.pop();
                for (int x : g[front])
                {
                    if (team[x] == team[front])
                    {
                        possible = false;
                        break;
                    }
                    if (team[x] == 0)
                    {
                        team[x] = (3 - team[front]);
                        q.push(x);
                    }
                }
            }
        }
    }

    if (!possible)
        cout << "IMPOSSIBLE\n";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << team[i] << " ";

        cout << "\n";
    }

    return 0;
}