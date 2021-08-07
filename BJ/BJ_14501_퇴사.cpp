#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, T, P;
	cin >> N;

	vector <vector <int> > v;
	vector <int> temp_v;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> T >> P;
		temp_v.push_back(T);
		temp_v.push_back(P);
		v.push_back(temp_v);
		temp_v.clear();
	}

	for (int i = 0; i < N; i++)
	{
		int now, next;
		now = i;
		next = now + v[now][0];
		int sum = 0;
		if (next > N)
			continue;

		sum = v[now][1];
		now = next;
		while (1)
		{
			if (now >= N)
				break;
			next = now + v[now][0];
			if (next > N)
				break;

			sum += v[now][1];
			now = next;
		}

		if (ans < sum)
			ans = sum;
	}

	cout << ans;
}