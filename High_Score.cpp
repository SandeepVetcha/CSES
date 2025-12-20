#include <bits/stdc++.h>
using namespace std;

#define int long long

void find_anses(int n, vector<unordered_set<int>> &parent,unordered_set <int> &s)
{
    //cout<<"here\n";
    if (s.find(n) != s.end())
        return;
    s.insert(n);
    for (int x : parent[n])
    {
        find_anses(x, parent, s);
    }
}


int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dis(n + 1, INT64_MAX);
    dis[1] = 0;

    vector<vector<int>> edges;
    vector<unordered_set<int>> parent(n+1);

    for (int i = 0; i < m; i++)
    {
        vector<int> v(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> v[j];
        }
        edges.push_back(v);
        parent[v[1]].insert(v[0]);
    }

    

    for (int i = 1; i < n; i++)
    {
        for (auto edge : edges)
        {
            if (dis[edge[0]] == INT64_MAX)
                continue;
            //cout << dis[edge[1]] << " " << dis[edge[0]] << " " << (-edge[2]) << "\n";

            dis[edge[1]] = min(dis[edge[1]], dis[edge[0]] + (-edge[2]));
            // cout << edge[1] << " dist updated to " << dis[edge[1]] << "\n";
            
        }
    }

    vector<int> temp_dis = dis;
    for (auto edge : edges)
    {
        if (temp_dis[edge[0]] == INT64_MAX)
            continue;
        temp_dis[edge[1]] = min(temp_dis[edge[1]], temp_dis[edge[0]] + (-edge[2]));
      
      
      
        // cout << edge[1] << " dist updated to " << temp_dis[edge[1]] << "\n";
    }

    unordered_set<int >s;
    find_anses(n,parent,s);


    for(int x: s){
        if(temp_dis[x]!=dis[x]) {
            cout<<-1<<"\n";
            return 0;
        }
    }


    cout << -dis[n] << "\n";

    return 0;
}