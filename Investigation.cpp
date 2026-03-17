#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long int>>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
    }

    vector<int> max_cities(n + 1, 0);
    vector<int> min_cities(n + 1, INT32_MAX);
    vector<long long int> min_price_routes(n + 1, 0);

    vector<long long int> dist(n + 1,INT64_MAX);
    dist[1] = 0;
    min_cities[1] = 0;
    min_price_routes[1] = 1;

    priority_queue<pair<long long int, int>> pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty())
    {

        auto top = pq.top();
        pq.pop();

        if (-top.first > dist[top.second])
            continue;
        for (auto next : g[top.second])
        {

            long long int new_dist = -top.first + next.second;
            if (dist[next.first] == new_dist)
            {
                max_cities[next.first] = max(max_cities[next.first], max_cities[top.second] + 1);
                min_cities[next.first] = min(min_cities[next.first], min_cities[top.second] + 1);
                min_price_routes[next.first] = (min_price_routes[next.first] + min_price_routes[top.second]) % 1000000007;
            }
            else if (dist[next.first] > new_dist)
            {
                dist[next.first] = new_dist;
                pq.push(make_pair(-new_dist, next.first));

                max_cities[next.first] = max_cities[top.second] + 1;
                min_cities[next.first] = min_cities[top.second] + 1;
                min_price_routes[next.first] = min_price_routes[top.second];
            }
        }
    }
    cout << dist[n] << " " << min_price_routes[n] << " " << min_cities[n] << " " << max_cities[n] << "\n";

    return 0;
    
}
