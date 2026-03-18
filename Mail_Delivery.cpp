#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<bool> &ec, vector<vector<pair<int,int>>> &g, stack<int> &s)
{
    while(!g[x].empty())
    {
        auto child=g[x].back();
        g[x].pop_back();

        if (ec[child.first])
            continue;
        else
        {
            ec[child.first] = true;
            dfs(child.second, ec, g, s);
        }
    }
    s.push(x);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n + 1);
    vector< bool> ec(m+1,false);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(make_pair(i,y));
        g[y].push_back(make_pair(i,x));

    }

    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() % 2)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    stack<int> s;
    dfs(1, ec, g, s);

    if (s.size() != m + 1)
        cout << "IMPOSSIBLE";
    else
    {
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    return 0;
}