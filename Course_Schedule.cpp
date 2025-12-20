#include <bits/stdc++.h>
using namespace std;


//Khans algo

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);

        indeg[y]++;
    }

    unordered_set<int> s1, s2;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
        {
            s1.insert(i);
        }

    vector<int> ans;

    while (!s1.empty() || !s2.empty())
    {
        /* code */

        for (int x : s1)
        {
            ans.push_back(x);

            for (int y : g[x])
            {
                indeg[y]--;
                if (indeg[y] == 0)
                    s2.insert(y);
            }
        }

        s1.clear();
        for (int x : s2)
        {
            ans.push_back(x);

            for (int y : g[x])
            {
                indeg[y]--;
                if (indeg[y] == 0)
                    s1.insert(y);
            }
        }
        s2.clear();
    }

    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}