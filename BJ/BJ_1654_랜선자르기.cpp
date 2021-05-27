#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int K, N;
vector <long long> v;
long long temp, ans, maximum, cnt;

void binary_search(long long first, long long mid, long long last)
{
	cnt = 0;

	if (first == mid)
		return;

	for (int i = 0; i < K; i++)
		cnt += v[i] / mid;

	if (cnt < N)
		binary_search(first, (first + mid) / 2, mid);

	else if (cnt >= N)
	{
		if (ans < mid)
			ans = mid;

		binary_search(mid, (mid + last) / 2, last);
	}

}

int main()
{
	long long mid;
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> temp;
		if (temp > maximum)
			maximum = temp;
		v.push_back(temp);
	}

	mid = maximum / 2;

	if (mid < 1)
		mid = 1;

	binary_search(0, mid, maximum);

	cnt = 0;
	for (int i = 0; i < K; i++)
		cnt += v[i] / maximum;

	if (cnt == N)
		ans = maximum;

	cout << ans;

}