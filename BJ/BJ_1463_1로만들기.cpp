#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	int i;
	int n, min = 999999999;

	cin >> n;

	v.push_back(0);

	for (i = 1; i < n; i++)
	{
		int temp = i + 1;
		min = v[i - 1];

		if (temp % 2 == 0 && min > v[i / 2])
			min = v[i / 2];

		if (temp % 3 == 0 && min > v[i / 3])
			min = v[i / 3];

		v.push_back(min + 1);
	}

	cout << v[n - 1] << endl;
}