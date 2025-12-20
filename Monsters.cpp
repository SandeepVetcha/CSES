#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;


	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<int>> monstime(n, vector<int>(m, INT32_MAX));

	vector<vector<bool>> vis(n, vector<bool>(m, 0));

	queue<pair<int, int>> qmons;
	queue<pair<int, pair<int, int>>> qman;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];

			if (v[i][j] == 'M')
			{
				monstime[i][j] = 1;
				qmons.push(make_pair(i, j));
			}
			if (v[i][j] == 'A')
			{
				vis[i][j] = true;
				qman.push(make_pair(1, make_pair(i, j)));
			}
		}
	}

	vector<int> dr{1, -1, 0, 0};
	vector<int> dc{0, 0, 1, -1};

	while (!qmons.empty())
	{

		auto co_ord = qmons.front();
		qmons.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = co_ord.first + dr[i];
			int y = co_ord.second + dc[i];

			if (x >= 0 && x < n && y >= 0 && y < m && monstime[x][y] == INT32_MAX && v[x][y] != '#')
			{
				qmons.push(make_pair(x, y));
				monstime[x][y] = monstime[co_ord.first][co_ord.second] + 1;
			}
		}
	}



	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));

	while (!qman.empty())
	{

		auto co_ord = qman.front();
		// Check if starting position is already on boundary
		if (co_ord.second.first == 0 || co_ord.second.first == n - 1 || co_ord.second.second == 0 || co_ord.second.second == m - 1)
		{
			cout << "YES\n0\n";
			return 0;
		}

		qman.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = co_ord.second.first + dr[i];
			int y = co_ord.second.second + dc[i];

			if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#' && !vis[x][y] && monstime[x][y] > co_ord.first + 1)
			{

				qman.push(make_pair(co_ord.first + 1, make_pair(x, y)));
				vis[x][y] = 1;
				parent[x][y] = make_pair(co_ord.second.first, co_ord.second.second);

				if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
				{

					int tempx = x;
					int tempy = y;
					string ans = "";
					while (v[tempx][tempy] != 'A')
					{

						int parx = parent[tempx][tempy].first;
						int pary = parent[tempx][tempy].second;

						if (parx > tempx)
						{
							ans += 'U';
						}
						else if (parx < tempx)
						{
							ans += 'D';
						}
						else if (pary > tempy)
						{
							ans += 'L';
						}
						else
						{
							ans += 'R';
						}
						tempx = parx;
						tempy = pary;
					}

					cout << "YES\n";
					cout << ans.length() << "\n";
					reverse(ans.begin(), ans.end());
					cout << ans << "\n";

					return 0;
				}


			}
		}
	}


	cout << "NO\n";

	return 0;
}