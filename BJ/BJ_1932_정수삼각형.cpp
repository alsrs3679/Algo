#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, temp, max = 0;
	vector <vector <int> > v, dpv;
	vector <int> temp_v, temp_dpv;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> temp;
			temp_v.push_back(temp);
			temp_dpv.push_back(0);
		}
		v.push_back(temp_v);
		dpv.push_back(temp_dpv);
		temp_v.clear();
		temp_dpv.clear();
	}

	dpv[0][0] = v[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dpv[i][j] = dpv[i - 1][j] + v[i][j];

			else if (j == i)
				dpv[i][j] = dpv[i - 1][j - 1] + v[i][j];

			else
			{
				if (dpv[i - 1][j - 1] > dpv[i - 1][j])
					dpv[i][j] = dpv[i - 1][j - 1] + v[i][j];
				else
					dpv[i][j] = dpv[i - 1][j] + v[i][j];
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		if (max < dpv[n - 1][i])
			max = dpv[n - 1][i];
	}
	cout << max;

}