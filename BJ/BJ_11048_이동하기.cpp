#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(int a, int b, int c)
{
	vector <int> aa;
	aa.push_back(a);
	aa.push_back(b);
	aa.push_back(c);

	sort(aa.begin(), aa.end());

	return aa[2];
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector <vector <int> > map, sum;
	vector <int> map_temp;
	int temp;

	map_temp.assign(M + 1, 0);
	map.assign(N + 1, map_temp);
	sum.assign(N + 1, map_temp);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> temp;
			map_temp[j] = temp;
		}
		map[i] = map_temp;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int mmax = find_max(sum[i - 1][j - 1], sum[i][j - 1], sum[i - 1][j]);
			sum[i][j] = mmax + map[i][j];
		}
	}

	cout << sum[N][M];
}