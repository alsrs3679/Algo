#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

class que 
{
public:
	int x;
	int y;
	vector <char> v;
};

int main()
{
	int R, C;

	cin >> R >> C;

	string s;
	vector <vector <char> > map;
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

	queue <que> q;

	que tq;
	tq.x = 0;
	tq.y = 0;
	tq.v.push_back(map[0][0]);

	q.push(tq);

	int ans = 0;

	while (!q.empty())
	{
		int now_x = q.front().x;
		int now_y = q.front().y;
		vector <char> now_v = q.front().v;
		q.pop();

		if (ans < now_v.size())
			ans = now_v.size();
		
		if (ans > now_v.size())
			continue;


		for (int i = 0; i < 4; i++)
		{
			int next_x = now_x + di[i];
			int next_y = now_y + dj[i];

			if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)
				continue;

			int check = 0;
			for (int j = 0; j < now_v.size(); j++)
			{
				if (map[next_x][next_y] == now_v[j])
				{
					check = 1;
					break;
				}
			}
			if (check == 1)
				continue;

			que next_q;
			next_q.x = next_x;
			next_q.y = next_y;
			next_q.v = now_v;
			next_q.v.push_back(map[next_x][next_y]);

			q.push(next_q);
		}
	}

	cout << ans;

}