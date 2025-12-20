#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()


{

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (d[x][y] == -1)
            d[x][y] = d[y][x] = z;
        else
        {
            d[x][y] = d[y][x] = min(z, d[x][y]);
        }
    }

    for (int i = 1; i <= n; i++)
        d[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (d[i][k] == -1)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (d[k][j] == -1)
                    continue;

                if (d[i][j] == -1)
                {
                    d[i][j] = d[i][k] + d[k][j];
                    continue;
                }
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << d[x][y] << "\n";
    }

    return 0;
}