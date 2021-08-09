#include <iostream>
#include <vector>

using namespace std;

struct TP {
	int tt;
	int pp;
};

int main()
{
	int N, T, P;
	cin >> N;

	vector <TP> v;

	for (int i = 0; i < N; i++)
	{
		cin >> T >> P;
		TP temp;
		temp.tt = T;
		temp.pp = P;
		v.push_back(temp);
	}

	vector <int> dp;
	dp.assign(N + 1, 0);

	for (int i = N - 1; i >= 0; i--)
	{
		int dodo = 0;
		if (v[i].tt + i <= N)
			dodo = v[i].pp + dp[v[i].tt + i];
		int notdo = dp[i + 1];

		if (dodo > notdo)
			dp[i] = dodo;
		else
			dp[i] = notdo;

	}

	cout << dp[0];
	
}