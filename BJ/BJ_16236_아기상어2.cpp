#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, temp;
	vector <vector <int> > map;
	vector <int> map_temp;

	int shark_i = 0, shark_j = 0, target_i, target_j;
	int shark_size = 2, shark_stack = 0;
	int ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			if (temp == 9)
			{
				shark_i = i;
				shark_j = j;
				temp = 0;
			}
			map_temp.push_back(temp);
		}
		map.push_back(map_temp);
		map_temp.clear();
	}


	while (1)
	{
		//먹을수 있는 물고기 찾기
		vector <vector <int> > can_eat;
		vector <int> eat_temp;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] != 0 && map[i][j] < shark_size)
				{
					eat_temp.push_back(i);
					eat_temp.push_back(j);
					can_eat.push_back(eat_temp);
					eat_temp.clear();
				}
			}
		}

		if (can_eat.size() == 0)
			break;

		//가장 가까운 물고기 찾기
		int min_ind = 0;
		int min_dis = abs(can_eat[0][0] - shark_i) + abs(can_eat[0][1] - shark_j);
		
		for (int i = 1; i < can_eat.size(); i++)
		{
			if (abs(can_eat[i][0] - shark_i) + abs(can_eat[i][1] - shark_j) < min_dis)
			{
				min_dis = abs(can_eat[i][0] - shark_i) + abs(can_eat[i][1] - shark_j);
				min_ind = i;
			}
			else if (abs(can_eat[i][0] - shark_i) + abs(can_eat[i][1] - shark_j) == min_dis)
			{
				if (can_eat[min_ind][0] > can_eat[i][0])
					min_ind = i;

				else if (can_eat[min_ind][0] == can_eat[i][0])
				{
					if (can_eat[min_ind][1] > can_eat[i][1])
						min_ind = i;
				}
			}
		}
		target_i = can_eat[min_ind][0];
		target_j = can_eat[min_ind][1];

		//bfs사용해서 가장 가까운 물고기 까지의 거리 구하기
		int di[4] = { 0, 1, 0, -1 };
		int dj[4] = { 1, 0, -1, 0 };
		queue <int> que;

		vector <vector <int> > road;
		vector <int> temp_road;
		temp_road.assign(N, 0);
		road.assign(N, temp_road);

		que.push(shark_i);
		que.push(shark_j);
		que.push(0);
		road[shark_i][shark_j] = 1;
		int check = 0;
		int che_i, che_j;
		while (1)
		{
			if (que.size() == 0)
				break;

			int next_i, next_j, now_i, now_j, dis;
			
			now_i = que.front();
			que.pop();
			now_j = que.front();
			que.pop();
			dis = que.front();
			que.pop();

			if (check != 0 && check < dis)
				break;

			if (now_i == target_i && now_j == target_j)
			{
				ans += dis;
				shark_stack++;
				map[target_i][target_j] = 0;
				shark_i = target_i;
				shark_j = target_j;
				if (shark_stack == shark_size)
				{
					shark_size++;
					shark_stack = 0;
				}
				check = 0;
				break;
			}

			if (map[now_i][now_j] != 0 && map[now_i][now_j] < shark_size)
			{
				check = dis;
				che_i = now_i;
				che_j = now_j;
			}

			for (int i = 0; i < 4; i++)
			{
				next_i = now_i + di[i];
				next_j = now_j + dj[i];

				if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= N)
					continue;

				if (road[next_i][next_j] == 1)
					continue;

				if (map[next_i][next_j] > shark_size)
					continue;

				que.push(next_i);
				que.push(next_j);
				que.push(dis + 1);
				road[next_i][next_j] = 1;

			}
		}

		if (check != 0)
		{
			ans += check;
			shark_stack++;
			map[che_i][che_j] = 0;
			shark_i = che_i;
			shark_j = che_j;
			if (shark_stack == shark_size)
			{
				shark_size++;
				shark_stack = 0;
			}
		}

		if (ans == 0)
			break;


	}

	cout << ans;

}