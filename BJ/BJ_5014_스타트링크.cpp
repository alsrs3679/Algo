#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	int F, S, G, U, D;
	int nowF;
	queue<int> q;
	vector<int> v;

	cin >> F >> S >> G >> U >> D;
	v.assign(F, -1);

	q.push(S);
	v[q.front() - 1] = 0;


	while (!q.empty())
	{
		nowF = q.front();
		q.pop();
		if (nowF - D >= 1)
		{
			if (v[nowF - D - 1] == -1)
			{
				q.push(nowF - D);
				v[nowF - D - 1] = v[nowF - 1] + 1;
			}
		}

		if (nowF + U <= F)
		{
			if (v[nowF + U - 1] == -1)
			{
				q.push(nowF + U);
				v[nowF + U - 1] = v[nowF - 1] + 1;
			}
		}
	}

	if (v[G - 1] != -1)
		cout << v[G - 1] << endl;

	if (v[G - 1] == -1)
		cout << "use the stairs" << endl;

}