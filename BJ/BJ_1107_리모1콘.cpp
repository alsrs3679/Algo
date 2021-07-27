#include <iostream>
#include <vector>

using namespace std;

int N;
int mi = 99999999;
int ans = 1000000;
int channel = -1;
vector <int> nums;

void permutation(int depth, int val)
{
	if (depth == 7)
		return;

	if (val != -1)
	{
		if (abs(val - N) <= mi)
		{
			int temp = 1;
			int temp_val = val;
			while (1)
			{
				if (temp_val / 10 != 0)
				{
					temp++;
					temp_val = temp_val / 10;
				}
				else
					break;
			}
			if (ans + mi > temp + abs(val - N))
			{
				mi = abs(val - N);
				channel = val;
				ans = temp;
			}

		}
	}
	else
		val = 0;

	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == -1)
			continue;

		permutation(depth + 1, val * 10 + i);

	}
}

int main()
{
	int M, temp;
	cin >> N >> M;

	nums.assign(10, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		nums[temp] = -1;
	}

	permutation(0, -1);

	if(ans == 1000000)
		ans = abs(N - 100);
	else
	{
		ans += abs(channel - N);

		if (abs(N - 100) < ans)
			ans = abs(N - 100);
	}

	cout << ans;

}