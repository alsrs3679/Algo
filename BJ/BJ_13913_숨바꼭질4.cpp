#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	vector <int> v, ans;

	cin >> N >> K;

	v.assign(100010, -1);
	queue <pair <int, int> > q;

	q.push(make_pair(N, 0));
	v[N] = -2;
	int now, cnt;
	while (1)
	{
		now = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (now == K)
			break;

		if (now * 2 <= K + 1 && v[now * 2] == -1)
		{
			q.push(make_pair(now * 2, cnt + 1));
			v[now * 2] = now;
		}

		if (now + 1 <= K && v[now + 1] == -1)
		{
			q.push(make_pair(now + 1, cnt + 1));
			v[now + 1] = now;
		}

		if (now - 1 >= 0 && v[now - 1] == -1)
		{
			q.push(make_pair(now - 1, cnt + 1));
			v[now - 1] = now;
		}
	}

	cout << cnt << endl;

	while (1)
	{
		ans.push_back(now);
		if (v[now] == -2)
			break;
		now = v[now];
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";

}
