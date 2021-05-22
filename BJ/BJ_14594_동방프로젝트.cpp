#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector <int> v;
	int sum = 0;
	int n, m, x, y;

	cin >> n >> m;

	v.assign(n, 1);

	while (m > 0)
	{
		cin >> x >> y;
		x--;
		y--;


		for (int i = x + 1; i <= y; i++)
			v[i] = 0;

		m--;
	}

	for (int i = 0; i < n; i++)
	{
		sum = sum + v[i];
	}

	cout << sum;

}