// #include <bits/stdc++.h>
// using namespace std;

// void build(int x, int &n, vector<int> &teleport, vector<char> &type, vector<int> &pos, vector<vector<int>> &paths, vector<int> &pathrefs)
// {
//     vector<int> temp;
//     vector<bool> vis(n + 1, 0);

//     bool done = 0;
//     while (!vis[x])
//     {

//         temp.push_back(x);
//         vis[x] = 1;
//         x = teleport[x];

//         if (type[x] != 0)
//         {

//             for (int i = 0; i < temp.size(); i++)
//             {
//                 pathrefs[temp[i]] = paths.size();
//                 pos[temp[i]] = i;
//                 type[temp[i]] = 1;
//             }

//             paths.push_back(temp);
//             done = 1;
//             break;
//         }
//     }

//     if (done)
//         return;
//     int last = temp.back();
//     vector<int> linear;
//     int idx = -1;
//     for (int i = 0; i < temp.size(); i++)
//     {
//         if (temp[i] == teleport[last])
//         {
//             idx = i;
//             break;
//         }

//         pathrefs[temp[i]] = paths.size();
//         pos[temp[i]] = linear.size();
//         linear.push_back(temp[i]);
//         type[temp[i]] = 1;
//     }

//     paths.push_back(linear);

//     vector<int> cycle;
//     for (int i = idx; i < temp.size(); i++)
//     {
//         pathrefs[temp[i]] = paths.size();
//         pos[temp[i]] = cycle.size();
//         cycle.push_back(temp[i]);
//         type[temp[i]] = 2;
//     }
//     paths.push_back(cycle);
// }

// int main()
// {

//     int n, q;
//     cin >> n >> q;

//     vector<int> teleport(n + 1);

//     vector<char> type(n + 1, 0);
//     vector<int> pos(n + 1, -1);
//     vector<int> pathrefs(n + 1, -1);
//     vector<vector<int>> paths;

//     vector<int> indeg(n + 1, 0);

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> teleport[i];
//         indeg[teleport[i]]++;
//     }

//     // Builder
//     for (int i = 1; i <= n; i++)
//     {
//         if (indeg[i] == 0)
//             build(i, n, teleport, type, pos, paths, pathrefs);
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (type[i] == 0)
//             build(i, n, teleport, type, pos, paths, pathrefs);
//     }

//     // cout << "build complete\n";

//     for (int i = 0; i < q; i++)
//     {
//         //  cout << i + 1 << " query\n";
//         int x, k;
//         cin >> x >> k;
//         // Response
//         while (1)
//         {
//             if (type[x] == 1)
//             {
//                 if (pos[x] + k < paths[pathrefs[x]].size())
//                 {
//                     cout << paths[pathrefs[x]][pos[x] + k] << "\n";
//                     break;
//                 }
//                 else
//                 {
//                     k = k + pos[x] - paths[pathrefs[x]].size();
//                     x = teleport[paths[pathrefs[x]].back()];
//                 }
//             }
//             else
//             {

//                 cout << paths[pathrefs[x]][(pos[x] + k) % paths[pathrefs[x]].size()] << "\n";
//                 break;
//             }
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, q;
//     cin >> n >> q;
//     vector<int> teleport(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> teleport[i];

//     int nxt[30][n+1];

//     for (int i = 1; i <= n; i++)
//     {
//         nxt[0][i] = teleport[i];
//     }

//     for (int i = 1; i < 30; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             nxt[i][j] = nxt[i-1][nxt[i-1][j]];
//         }
//     }

//     for (int i = 0; i < q; i++)
//     {
//         int x, k;
//         cin >> x >> k;

//         for (int j = 0; j < 30; j++)
//         {
//             if ((k >> j) & 1)
//                 x = nxt[j][x];
//         }

//         cout << x << "\n";
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

const int N = 200001;
const int M = 30;

int succ[M][N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> succ[0][i];
    }

    for (int i = 1; i < M; ++i) {
        for (int j = 1; j <= n; ++j) {
            succ[i][j] = succ[i - 1][succ[i - 1][j]];
        }
    }

    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < M; ++j) {
            if (k & (1 << j)) {
                x = succ[j][x];
            }
        }
        std::cout << x << '\n';
    }
}