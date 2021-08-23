#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> >v;
vector <vector <int> > dx, dy;
int ans = 0;
int N;

void dfs(int x, int y, int state)
{
	if (x == N - 1 && y == N - 1)
	{
		ans++;
		return;
	}

	int nexti, nextj;
	for (int i = 0; i < 3; i++)
	{
		nexti = x + dx[state][i];
		nextj = y + dy[state][i];

		if (nexti == x && nextj == y)
			continue;

		if (nexti >= N || nextj >= N)
			continue;

		if (v[nexti][nextj] == 1 || v[x][nextj] == 1 || v[nexti][y] == 1)
			continue;
		dfs(nexti, nextj, i);
	}
}

int main()
{
	int temp;

	vector <int> temp_v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			temp_v.push_back(temp);
		}
		v.push_back(temp_v);
		temp_v.clear();
	}

	dx = { { 0, 0, 1 },{ 0, 1, 1 },{ 0, 1, 1 } };
	dy = { { 1, 0, 1 },{ 0, 0, 1 },{ 1, 0, 1 } };

	dfs(0, 1, 0);

	cout << ans;

}