#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int dfs(int node, vector<vector<int>> &g, vector<int> &dp, int n)
{

    if (node == n)
        return 1;
    if (dp[node] != -1)
        return dp[node];
    int temp = 0;

    for (int child : g[node])
    {

        temp = (temp + dfs(child, g, dp, n)) % mod;
    }
    return dp[node] = temp;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> dp(n + 1, -1);

    cout << dfs(1, g, dp, n) << "\n";

    return 0;
}
