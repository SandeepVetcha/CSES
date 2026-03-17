#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x], parent);
}

int merge(int x, int y, vector<int> &parent, vector<int> &rank, int &maxrank)
{
    x = find(x, parent);
    y = find(y, parent);

    if (x == y)
        return 0;
    if (rank[x] > rank[y])
    {
        parent[y] = x;
        rank[x] += rank[y];
        maxrank = max(maxrank, rank[x]);
    }

    else
    {
        parent[x] = y;
        rank[y] += rank[x];

        maxrank = max(maxrank, rank[y]);
    }
    return 1;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int cnt = 0;
    int maxrank = 1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt += merge(a, b, parent, rank, maxrank);
        cout << n - cnt << " " << maxrank << "\n";
    }

    return 0;
}