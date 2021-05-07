#include <iostream>
#include <vector>

using namespace std;

int N;
vector <vector <int> > map;
int ans = 0;

void dfs(int depth)
{
	if (depth == 5)
	{
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > max)
					max = map[i][j];
			}
		}
		if (max > ans)
			ans = max;
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		vector <vector <int> > v;
		vector <int> temp;
		temp.assign(N, 0);
		v.assign(N, temp);
		
		temp.clear();
		int check_ind = -1;

		if (k == 0)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = N - 1; j >= 0; j--)
				{
					if (map[i][j] != 0)
					{
						if (check_ind == -1)
						{
							temp.push_back(map[i][j]);
							check_ind = temp.size() - 1;
						}
						else
						{
							if (map[i][j] == temp[check_ind])
							{
								temp[check_ind] += map[i][j];
								check_ind = -1;
							}
							else
							{
								temp.push_back(map[i][j]);
								check_ind++;
							}
						}

					}
				}

				for (int q = 0; q < temp.size(); q++)
					v[i][N - 1 - q] = temp[q];

				temp.clear();
				check_ind = -1;
			}

			vector <vector <int> > map_temp = map;
			map = v;
			dfs(depth + 1);
			map = map_temp;
		}

		if (k == 1)
		{
			for (int j = 0; j < N; j++)
			{
				for (int i = N - 1; i >= 0; i--)
				{
					if (map[i][j] != 0)
					{
						if (check_ind == -1)
						{
							temp.push_back(map[i][j]);
							check_ind = temp.size() - 1;
						}
						else
						{
							if (map[i][j] == temp[check_ind])
							{
								temp[check_ind] += map[i][j];
								check_ind = -1;
							}
							else
							{
								temp.push_back(map[i][j]);
								check_ind++;
							}
						}

					}
				}

				for (int q = 0; q < temp.size(); q++)
					v[N - 1 - q][j] = temp[q];

				temp.clear();
				check_ind = -1;
			}

			vector <vector <int> > map_temp = map;
			map = v;
			dfs(depth + 1);
			map = map_temp;
		}

		if (k == 2)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (map[i][j] != 0)
					{
						if (check_ind == -1)
						{
							temp.push_back(map[i][j]);
							check_ind = temp.size() - 1;
						}
						else
						{
							if (map[i][j] == temp[check_ind])
							{
								temp[check_ind] += map[i][j];
								check_ind = -1;
							}
							else
							{
								temp.push_back(map[i][j]);
								check_ind++;
							}
						}

					}
				}

				for (int q = 0; q < temp.size(); q++)
					v[i][q] = temp[q];

				temp.clear();
				check_ind = -1;
			}

			vector <vector <int> > map_temp = map;
			map = v;
			dfs(depth + 1);
			map = map_temp;
		}

		if (k == 3)
		{
			for (int j = 0; j < N; j++)
			{
				for (int i = 0; i < N; i++)
				{
					if (map[i][j] != 0)
					{
						if (check_ind == -1)
						{
							temp.push_back(map[i][j]);
							check_ind = temp.size() - 1;
						}
						else
						{
							if (map[i][j] == temp[check_ind])
							{
								temp[check_ind] += map[i][j];
								check_ind = -1;
							}
							else
							{
								temp.push_back(map[i][j]);
								check_ind++;
							}
						}

					}
				}

				for (int q = 0; q < temp.size(); q++)
					v[q][j] = temp[q];

				temp.clear();
				check_ind = -1;
			}

			vector <vector <int> > map_temp = map;
			map = v;
			dfs(depth + 1);
			map = map_temp;
		}

	}





}

int main()
{
	cin >> N;
	int temp;
	vector <int> map_temp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			map_temp.push_back(temp);
		}
		map.push_back(map_temp);
		map_temp.clear();
	}

	dfs(0);
	cout << ans;

}