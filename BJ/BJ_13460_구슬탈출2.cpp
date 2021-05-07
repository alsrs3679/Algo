#include <iostream>
#include <vector>

using namespace std;

int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int N, M;
int g_i, g_j;
vector <vector <char> > map;
vector <char> map_temp;
int ans = 99999;

void dfs(int cnt, int ans_check, int r_i, int r_j, int b_i, int b_j, int before)
{
	if (cnt >= 10)
	{
		if(ans_check == 0)
			return;
	}
	if (ans_check != 0)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (before == 0)
		{
			if (i == 2)
				continue;
		}
		if (before == 1)
		{
			if(i == 3)
				continue;
		}
		if (before == 2)
		{
			if(i == 0)
				continue;
		}
		if (before == 3)
		{
			if (i == 1)
				continue;
		}
		int next_r_i = r_i + di[i];
		int next_r_j = r_j + dj[i];
		int next_b_i = b_i + di[i];
		int next_b_j = b_j + dj[i];

		//이동가능할때
		if (map[next_r_i][next_r_j] == '.' || map[next_r_i][next_r_j] == '1' || map[next_r_i][next_r_j] == '2' || map[next_r_i][next_r_j] == 'O' || map[next_b_i][next_b_j] == '.' || map[next_b_i][next_b_j] == '1' || map[next_b_i][next_b_j] == '2' || map[next_b_i][next_b_j] == 'O')
		{
			vector <vector <char> > temp = map;
			int r_check = 0, b_check = 0;
			int now_r_i = r_i;
			int now_r_j = r_j;
			int now_b_i = b_i;
			int now_b_j = b_j;
			int asd = ans_check;
			int r_goal = 0, b_goal = 0;
			while (r_check + b_check != 2)
			{
				//빨
				if (r_goal == 0)
				{
					if (map[next_r_i][next_r_j] == 'O')
					{
						if (asd == 0)
							asd = 1;
						r_check = 1;
						map[now_r_i][now_r_j] = '1';
						now_r_i = next_r_i;
						now_r_j = next_r_j;
						next_r_i += di[i];
						next_r_j += dj[i];
						r_goal = 1;
					}
					else if (map[next_r_i][next_r_j] == '.' || map[next_r_i][next_r_j] == '1' || map[next_r_i][next_r_j] == '2')
					{
						r_check = 0;
						map[next_r_i][next_r_j] = 'R';
						map[now_r_i][now_r_j] = '1';
						now_r_i = next_r_i;
						now_r_j = next_r_j;
						next_r_i += di[i];
						next_r_j += dj[i];

					}
					else
						r_check = 1;
				}
				//파
				if (b_goal == 0)
				{
					if (map[next_b_i][next_b_j] == 'O')
					{
						asd = -1;
						b_check = 1;
						map[now_b_i][now_b_j] = '2';
						now_b_i = next_b_i;
						now_b_j = next_b_j;
						next_b_i += di[i];
						next_b_j += dj[i];
						b_goal = 1;
					}
					else if (map[next_b_i][next_b_j] == '.' || map[next_b_i][next_b_j] == '1' || map[next_b_i][next_b_j] == '2')
					{
						b_check = 0;
						map[next_b_i][next_b_j] = 'B';
						map[now_b_i][now_b_j] = '2';
						now_b_i = next_b_i;
						now_b_j = next_b_j;
						next_b_i += di[i];
						next_b_j += dj[i];
					}
					else
						b_check = 1;
				}
			}
			
			if (asd == 1)
			{
				if (ans > cnt + 1)
					ans = cnt + 1;
			}

			//재귀진입
			dfs(cnt + 1, asd, now_r_i, now_r_j, now_b_i, now_b_j, i);
			map = temp;
		}
		

		

	}
}
int main()
{
	char c;
	int r_i = 0, b_i = 0, r_j = 0, b_j = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			map_temp.push_back(c);
			if (c == 'R')
			{
				r_i = i;
				r_j = j;
			}
			if (c == 'B')
			{
				b_i = i;
				b_j = j;
			}
			if (c == 'O')
			{
				g_i = i;
				g_j = j;
			}
		}
		map.push_back(map_temp);
		map_temp.clear();
	}

	int cnt = 0;
	int ans_check = 0;
	dfs(cnt, ans_check, r_i, r_j, b_i, b_j, -1);
	
	if (ans == 99999)
		ans = -1;
	cout << ans;
}