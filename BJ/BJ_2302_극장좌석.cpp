#include <iostream>
#include <vector>

using namespace std;



int main()
{
	int N, M;
	vector <int> num, dp, index;
	dp.assign(40, 0);

	for (int i = 0; i < 4; i++)
		dp[i] = i;

	int temp, ind, ans = 1, vip;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		if (i == 0)
			ind = temp;
		else
			ind = temp - vip;
		vip = temp;
		index.push_back(ind - 1);

		for (int j = 4; j < ind; j++)
		{
			if (dp[j] != 0)
				continue;
			else
				dp[j] = dp[j - 1] + dp[j - 2];
		}
	}

	N = N - temp;

	index.push_back(N);
	for (int j = 4; j <= N; j++)
	{
		if (dp[j] != 0)
			continue;
		else
			dp[j] = dp[j - 1] + dp[j - 2];
	}

	for (int i = 0; i < index.size(); i++)
	{
		if (dp[index[i]] != 0)
			ans = ans * dp[index[i]];
	}

	cout << ans;

}