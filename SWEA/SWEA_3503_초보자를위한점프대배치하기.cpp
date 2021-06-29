#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	int testcase, t = 1;
	int N, high, max = 0;

	vector <int> ans;
	vector <int> v;
	vector <int>::iterator a;

	cin >> testcase;

	while (t <= testcase)
	{
		cin >> N;
		v.assign(N, 0);

		for (int i = 0; i < N; i++)
		{
			cin >> high;
			v[i] = high;
		}

		sort(v.begin(), v.end(), greater<int>());

		a = v.begin() + 1;

		max = v[0] - *a;
		a++;
		for (int i = 0; i <= N - 3; i++)
		{
			if (v[i] - *a > max)
				max = v[i] - *a;
			a++;
		}
		ans.push_back(max);
		max = 0;
		t++;
	}

	for (int i = 0; i < testcase; i++)
		cout << "#" << i + 1 << " " << ans[i] << endl;
}