#include <bits/stdc++.h>
using namespace std;

int cycle_entry;
void dfs(int node, vector<int> &tel, vector<int> &dis, vector<bool> &vis, vector<bool> &currvis)
{
    if (vis[node])
    {
        cycle_entry = node;
        return;
    }
    vis[node] = true;
    currvis[node] = true;
    dfs(tel[node], tel, dis, vis, currvis);
    dis[node] = 1 + dis[tel[node]];
}

int main()
{
    int n;
    cin >> n;
    vector<int> tel(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> tel[i];

    vector<int> dis(n + 1, 0);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++)
    {

        
        if (dis[i] == 0)
        {
            vector<bool> currvis(n + 1, false);
            dfs(i, tel, dis, vis, currvis);

            if (!currvis[cycle_entry])
                continue;

            int temp = tel[cycle_entry];
            while (temp != cycle_entry)
            {
                dis[temp] = dis[cycle_entry];
                temp = tel[temp];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << "\n";

    return 0;
}