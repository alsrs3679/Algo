#include<iostream>
#include<vector>

using namespace std;

int main()
{
	for (int T = 1; T <= 10; T++)
	{
		int N, temp, compare = 1, ans = 0;
		vector <vector <int> > v;
		vector <int> tv;

		cin >> N;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> temp;
				tv.push_back(temp);
			}
			v.push_back(tv);
			tv.clear();
		}

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (v[j][i] == 2)
					v[j][i] = 0;
				else if (v[j][i] == 1)
					break;
			}
		}

		for (int i = 0; i < 100; i++)
		{
			for (int j = 99; j > 0; j--)
			{
				if (v[j][i] == 1)
					v[j][i] = 0;
				else if (v[j][i] == 2)
					break;
			}
		}

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (v[j][i] == 1)
					compare = 1;
				else if (v[j][i] == 2)
				{
					if (compare != 2)
						ans++;
					compare = 2;
				}

			}
		}

		cout << "#" << T << " " << ans << endl;
	}
}