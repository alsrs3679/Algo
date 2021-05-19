#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int k, n;
	vector <vector <int>> v;
	vector <int> temp_v;
	int i, j, q;
	int sum = 0;

	cin >> n >> k;

	temp_v.assign(200, 0);
	v.assign(200, temp_v);

	for (i = 0; i < n; i++)
	{
		temp_v[i] = 1;
	}
	v[0] = temp_v;
	for (i = 1; i < k; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (q = 0; q <= j; q++)
				sum = (sum % 1000000000) + (v[i - 1][q] % 1000000000);

			sum++;
			sum = sum % 1000000000;
			temp_v[j] = sum;
			sum = 0;
		}
		v[i] = temp_v;
	}
	cout << v[k - 1][n - 1] << endl;
}