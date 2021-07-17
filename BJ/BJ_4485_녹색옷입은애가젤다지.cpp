#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int T = 0;
	while (1)
	{
		T++;
		int N;
		cin >> N;
		if (N == 0)
			break;
		vector <vector <int> > v, check_v;
		vector <int> temp_v;
		int temp;

		temp_v.assign(N, 0);
		v.assign(N, temp_v);
		temp_v.assign(N, 1000000);
		check_v.assign(N, temp_v);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &temp);
				v[i][j] = temp;
			}
		}

		queue <vector <int> > que;
		vector <int> temp_que;
		temp_que.assign(3, 0);
		temp_que[2] = v[0][0];
		check_v[0][0] = v[0][0];

		que.push(temp_que);

		int di[4] = { 0, 1, 0, -1 };
		int dj[4] = { 1, 0, -1, 0 };
		int minn = 99999;
		while (!que.empty())
		{
			int nexti = que.front()[0];
			int nextj = que.front()[1];
			int sum = que.front()[2];
			que.pop();

			if (sum > check_v[nexti][nextj])
				continue;

			if (nexti == N - 1 && nextj == N - 1)
			{
				if (minn > sum)
					minn = sum;
			}




			for (int i = 0; i < 4; i++)
			{
				if (nexti + di[i] >= N || nexti + di[i] < 0 || nextj + dj[i] >= N || nextj + dj[i] < 0)
					continue;

				if (check_v[nexti + di[i]][nextj + dj[i]] <= sum)
					continue;
				else
				{
					temp_que[0] = nexti + di[i];
					temp_que[1] = nextj + dj[i];
					temp_que[2] = sum + v[nexti + di[i]][nextj + dj[i]];
					if (check_v[nexti + di[i]][nextj + dj[i]] > temp_que[2])
						check_v[nexti + di[i]][nextj + dj[i]] = temp_que[2];
					que.push(temp_que);
				}
			}
		}

		cout << "Problem " << T << ": " << minn << endl;
	}
}