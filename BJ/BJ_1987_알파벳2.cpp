#include <iostream>
#include <vector>

using namespace std;

int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int R, C;
int ans = 0;

vector <vector <char> > map;
vector <int> visit;

void dfs(int x, int y, int depth)
{
	if (ans < depth)
		ans = depth;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + di[i];
		int next_y = y + dj[i];

		if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)
			continue;
		
		if (visit[map[next_x][next_y] - 65] == 0)
		{
			visit[map[next_x][next_y] - 65] = 1;
			dfs(next_x, next_y, depth + 1);
			visit[map[next_x][next_y] - 65] = 0;
		}
	}
}

int main()
{
	cin >> R >> C;

	string s;
	vector <char> map_temp;
	for (int i = 0; i < R; i++)
	{
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			char c = s.at(j);
			map_temp.push_back(c);
		}
		map.push_back(map_temp);
		map_temp.clear();
	}

	visit.assign(26, 0);

	visit[map[0][0] - 65] = 1;

	dfs(0, 0, 1);

	cout << ans;


}