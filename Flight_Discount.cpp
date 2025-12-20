#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    vector<vector<pair<int, int>>> g_back(n + 1);
    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> edge{a, b, c};
        edges.push_back(edge);
        g[a].push_back(make_pair(b, c));
        g_back[b].push_back(make_pair(a, c));
    }

    vector<int> dis1(n + 1, LLONG_MAX);
    vector<int> dis2(n + 1, LLONG_MAX);

    vector<int> maxi(n + 1, 0);

    dis1[1] = 0;
    dis2[n] = 0;

    priority_queue<pair<int, int>> pq1;
    priority_queue<pair<int, int>> pq2;

    pq1.push(make_pair(0, 1));
    pq2.push(make_pair(0, n));

    while (!pq1.empty())
    {
        auto top = pq1.top();
        pq1.pop();
        if (dis1[top.second] < (-top.first))
            continue;

        for (auto x : g[top.second])
        {
            int dist = -top.first + x.second;
            int node = x.first;

            if (dis1[node] > dist)
            {
                dis1[node] = dist;
                pq1.push(make_pair(-dist, node));
            }
        }
    }

    while (!pq2.empty())
    {
        auto top = pq2.top();
        pq2.pop();
        if (dis2[top.second] < (-top.first))
            continue;

        for (auto x : g_back[top.second])
        {
            int dist = -top.first + x.second;
            int node = x.first;

            if (dis2[node] > dist)
            {
                dis2[node] = dist;
                pq2.push(make_pair(-dist, node));
            }
        }
    }

    int ans = LLONG_MAX;

    for (auto edge : edges)
    {

        if(dis1[edge[0]] != LLONG_MAX && dis2[edge[1]] != LLONG_MAX)
        ans = min(ans, (dis1[edge[0]] + dis2[edge[1]] + edge[2] / 2));
    }

    cout << ans << "\n";

    return 0;
}