#include <iostream>
#include <vector>

using namespace std;

long N, M, temp;
vector <long> v;
long high, hap;

void binary_divi(long min, long mid, long max)
{
	if (min == mid)
		return;

	hap = 0;
	for (int i = 0; i < N; i++)
	{
		temp = v[i] - mid;
		if (temp > 0)
			hap += temp;

	}

	if (hap >= M)
	{
		if (high < mid)
			high = mid;

		binary_divi(mid, (mid + max) / 2, max);
	}
	else
	{
		binary_divi(min, (min + mid) / 2, mid);
	}

}

int main()
{
	long max_high = 0, middle;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		if (max_high < temp)
			max_high = temp;

		v.push_back(temp);
	}

	binary_divi(0, max_high / 2, max_high);


	cout << high;
}