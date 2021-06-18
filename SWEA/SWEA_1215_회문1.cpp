#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector <vector <char>> v;
	vector <char> temp_v;


	for (int testcase = 1; testcase <= 10; testcase++)
	{
		int len, ans = 0;
		int a, q, s;
		char temp, pare;
		cin >> len;

		v.clear();
		temp_v.assign(8, '\n');
		v.assign(8, temp_v);

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> temp;
				temp_v[j] = temp;
			}
			v[i] = temp_v;
		}


		a = len - 1;
		q = 0, s = 0;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8 - a; j++)
			{
				while (len / 2 > s)
				{
					if (v[i][j + s] == v[i][j + a - s])
						q++;
					s++;
				}
				if (q == s)
					ans++;
				q = 0, s = 0;
			}
		}



		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8 - a; i++)
			{
				while (len / 2 > s)
				{
					if (v[i + s][j] == v[i + a - s][j])
						q++;
					s++;
				}
				if (q == s)
					ans++;
				q = 0, s = 0;
			}
		}

		cout << "#" << testcase << " " << ans << endl;
		ans = 0;
	}
}