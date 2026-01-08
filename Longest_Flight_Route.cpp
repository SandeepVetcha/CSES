#include <bits/stdc++.h>
using namespace std;

// int main()
// {

//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> g(n + 1);

//     vector<int> parent(n + 1, 0);

//     vector<int> vis(n + 1, 0);
//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         g[x].push_back(y);
//     }

//     queue<int> q;

//     q.push(1);
//     vis[1] = 1;

//     while (!q.empty())

//     {
//         int front = q.front();
//         q.pop();
//         for (int x : g[front])
//         {
//             if (!vis[x])
//             {

//                 vis[x] = 1;
//                 parent[x] = front;
//                 q.push(x);
//             }
//             else
//             {
//                 parent[x] = front;
//             }
//         }
//         /* code */
//     }

//     vector<int> temp;

//     int curr = n;
//     while (curr != 1)
//     {
//         temp.push_back(curr);
//         if (parent[curr] == 0)
//         {
//             cout << "IMPOSSIBLE\n";
//             return 0;
//         }
//         curr = parent[curr];
//     }

//     temp.push_back(curr);

//     cout << temp.size() << "\n";

//     for (int i = temp.size() - 1; i >= 0; i--)
//     {
//         cout << temp[i] << " ";
//     }

//     cout << "\n";

//     return 0;
// }

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);

        indeg[y]++;
    }

    queue<int> q;
    vector<int> order;

    for (int i = 1; i <= n; i++)
    {

        if (indeg[i] == 0)
        {
            q.push(i);
            order.push_back(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int x : g[front])
        {

            indeg[x]--;

            if (indeg[x] == 0)
            {
                order.push_back(x);
                q.push(x);
            }
        }
    }

    vector<int> parent(n + 1, 0);
    vector<int> dist(n + 1, INT_MIN);
    dist[1] = 0;

    for (int x : order)
    {
        if (dist[x] == INT_MIN)
            continue;

        for (int child : g[x])
        {

            if (dist[child] < dist[x] + 1)
            {
                dist[child] = dist[x] + 1;
                parent[child] = x;
            }
        }
    }

    if (dist[n] == INT_MIN)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int temp = n;
    vector<int> ans;
    while (temp)
    {
        ans.push_back(temp);
        temp = parent[temp];
    }

    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
