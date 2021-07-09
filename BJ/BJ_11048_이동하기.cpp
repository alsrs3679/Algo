#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct que
{
	int r, c;
	int cnt;
};

int main()
{
	int N, M;
	cin >> N >> M;

	vector <vector <int> > map, sum;
	vector <int> map_temp;
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			map_temp.push_back(temp);
		}
		map.push_back(map_temp);
		map_temp.clear();
	}

	map_temp.assign(M, 0);
	sum.assign(N, map_temp);

	que qq;
	qq.r = 0;
	qq.c = 0;
	qq.cnt = 
	queue <que> q;
	

}