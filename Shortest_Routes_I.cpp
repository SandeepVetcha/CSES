#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
       // g[y].push_back(make_pair(x, z));
    }

    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, INT64_MAX);

    dist[1] = 0;
    pq.push(make_pair(0, 1));

    while (!pq.empty())
    {

        auto top = pq.top();
        //cout << top.first << " " << top.second << "popped\n";
        pq.pop();

        if (-top.first > dist[top.second])
        {
            //cout << "continued\n";
            continue;
        }

        for (auto node : g[top.second])
        {
            int distance = -top.first + node.second;

            if (distance < dist[node.first])
            {
                dist[node.first] = distance;
                pq.push(make_pair(-distance, node.first));
                //cout << -distance << " " << node.first << "pushed\n";
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}