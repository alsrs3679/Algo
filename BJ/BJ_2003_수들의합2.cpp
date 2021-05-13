#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, temp;
	cin >> N >> M;

	vector <int> v;

	v.assign(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v[i] = temp;
	}

	int last = 0;
	int sum = 0;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		sum += v[i];

		if (sum < M)
			continue;
		else if (sum == M)
		{
			ans++;
			continue;
		}
		else
		{
			sum -= v[last];
			sum -= v[i];
			last++;
			i--;
		}
	}
	cout << ans;
}