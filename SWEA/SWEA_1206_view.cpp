#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int high, buildn, t, ans = 0, h = 0;

	vector <vector <int>> v;
	vector <int> temp_v;

	temp_v.assign(255, 0);

	for (int q = 0; q < 10; q++)
	{

		v.assign(1000, temp_v);

		cin >> buildn;
		for (int i = 0; i < buildn; i++)
		{
			cin >> high;
			for (int j = 0; j < high; j++)
				v[i][j] = 1;
		}

		for (int i = 2; i < buildn - 2; i++)
		{
			while (v[i][h] != 0)
			{
				if (v[i - 2][h] != 1 && v[i - 1][h] != 1 && v[i + 1][h] != 1 && v[i + 2][h] != 1)
					ans++;
				h++;
			}
			h = 0;
		}

		cout << "#" << q + 1 << " " << ans << endl;

		ans = 0;

	}


}