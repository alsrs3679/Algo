#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector <int> prime, arr;
	arr.assign(N + 1, 0);
	arr[0] = 1;
	arr[1] = 1;
	
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == 1)
			continue;
		prime.push_back(i);
		for (int j = i + i; j <= N; j += i)
			arr[j] = 1;
	}

	int start = prime.size() - 1, end = prime.size() - 1, sum = 0, ans = 0;

	while(1)
	{
		if (end < 0)
			break;
		sum += prime[end--];
		if (sum >= N)
		{
			if (sum == N)
				ans++;

			sum -= prime[start--];
		}
	}

	cout << ans;
}