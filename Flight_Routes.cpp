#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
    }

    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, 1));

    priority_queue<int> init;
    for (int i = 0; i < k; i++)
        init.push(LLONG_MAX);
    vector<priority_queue<int>> dist(n + 1, init);

    while (!pq.empty())
    {

        auto top = pq.top();
        pq.pop();

        if (-top.first > dist[top.second].top())
        {
            continue;
        }

        for (auto node : g[top.second])
        {
            int distance = -top.first + node.second;

            if (distance < dist[node.first].top())
            {
                dist[node.first].pop();
                dist[node.first].push(distance);
                pq.push(make_pair(-distance, node.first));
            }
        }
    }

    vector<int> ans;

    while (!dist[n].empty())
    {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    for (int i = k - 1; i >= 0; i--)
        cout << ans[i] << " ";

    cout << "\n";

    return 0;
}