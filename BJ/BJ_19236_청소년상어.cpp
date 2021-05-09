#include <iostream>
#include <vector>

using namespace std;

int map[2][4][4];
int max_ans = 0;
int di[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void fish_move()
{
	int dir, next_i, next_j, temp1, temp2;
	int check = 0;
	for (int fish_num = 1; fish_num <= 16; fish_num++)
	{
		check = 0;
		for (int i = 0; i < 4; i++)
		{
			if (check == 1)
				break;
			for (int j = 0; j < 4; j++)
			{
				if (check == 1)
					break;
				if (map[0][i][j] == fish_num)
				{
					dir = map[1][i][j];
					next_i = i + di[dir];
					next_j = j + dj[dir];
					if (next_i < 0 || next_i >= 4 || next_j < 0 || next_j >= 4)
					{
						map[1][i][j]++;
						if (map[1][i][j] == 8)
							map[1][i][j] = 0;
						j--;
					}
					else if(map[0][next_i][next_j] == -1)
					{
						map[1][i][j]++;
						if (map[1][i][j] == 8)
							map[1][i][j] = 0;
						j--;
					}

					else if(map[0][next_i][next_j] == 0)
					{
						check = 1;
						map[0][next_i][next_j] = map[0][i][j];
						map[1][next_i][next_j] = dir;
						map[0][i][j] = 0;
						map[1][i][j] = 0;
					}
					else
					{
						check = 1;
						temp1 = map[0][next_i][next_j];
						temp2 = map[1][next_i][next_j];
						map[0][next_i][next_j] = map[0][i][j];
						map[1][next_i][next_j] = dir;
						map[0][i][j] = temp1;
						map[1][i][j] = temp2;
					}

				}
			}
		}
	}
	
}

void dfs(int a, int b, int cnt)
{
	//물고기 이동
	fish_move();

	//상어기준 탈출조건 확인 및 이동
	int dir = map[1][a][b];
	int next_a, next_b;
	int can_eat = 0;
	for (int q = 1; q <= 3; q++)
	{
		int temp_map[2][4][4];
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				temp_map[0][i][j] = map[0][i][j];
				temp_map[1][i][j] = map[1][i][j];
			}
		}

		next_a = a + (di[dir] * q);
		next_b = b + (dj[dir] * q);

		if (next_a < 0 || next_a >= 4 || next_b < 0 || next_b >= 4)
			break;

		if (map[0][next_a][next_b] != 0)
		{
			can_eat = 1;
			int val = map[0][next_a][next_b];
			map[0][next_a][next_b] = -1;
			map[0][a][b] = 0;
			map[1][a][b] = 0;
			dfs(next_a, next_b, cnt + val);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					map[0][i][j] = temp_map[0][i][j];
					map[1][i][j] = temp_map[1][i][j];
				}
			}

		}
	}
	if (can_eat == 0)
	{
		if (max_ans < cnt)
			max_ans = cnt;
		return;
	}



}
int main()
{
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> map[0][i][j];
			cin >> temp;
			map[1][i][j] = temp - 1;
		}
	}

	int first = map[0][0][0];
	map[0][0][0] = -1;
	dfs(0, 0, first);

	cout << max_ans;
	
}