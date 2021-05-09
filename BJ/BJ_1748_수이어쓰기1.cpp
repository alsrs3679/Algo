#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> v;
	int N;
	int temp = 9;
	int ans = 0;
	int check = 0;
	v.assign(10, 0);
	for (int i = 1; i < 10; i++)
	{
		v[i] = temp;
		temp *= 10;
	}

	cin >> N;

	temp = 9;
	int ind = 1;

	while (1)
	{
		if (temp < N)
		{
			temp = temp * 10 + 9;
			ind++;
			continue;
		}
		else
		{
			if (temp != N)
				temp = temp / 10;
			else
				check = 1;
			break;
		}
	}

	ans = (N - temp) * ind;
	for (int i = 1; i < ind; i++)
		ans += v[i] * i;

	if (check == 1)
		ans += v[ind] * ind;
	cout << ans;
}