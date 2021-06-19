#include<iostream>
#include<vector>

using namespace std;

vector <vector <char>> v;
vector <char> temp_v;

int len, ans = 0;
int a, q, s;
char temp, pare;

int checker()
{
	len = 100;
	while (len > 0)
	{
		a = len - 1;
		q = 0, s = 0;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100 - a; j++)
			{
				while (len / 2 > s)
				{
					if (v[i][j + s] == v[i][j + a - s])
						q++;
					else
						break;
					s++;
				}
				if (q == len / 2)
					return len;
				q = 0, s = 0;
			}
		}



		for (int j = 0; j < 100; j++)
		{
			for (int i = 0; i < 100 - a; i++)
			{
				while (len / 2 > s)
				{
					if (v[i + s][j] == v[i + a - s][j])
						q++;
					else
						break;
					s++;
				}
				if (q == len / 2)
					return len;
				q = 0, s = 0;
			}
		}
		len--;
	}
}

int main()
{



	for (int testcase = 1; testcase <= 10; testcase++)
	{

		cin >> len;

		v.clear();
		temp_v.assign(100, '\n');
		v.assign(100, temp_v);

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> temp;
				temp_v[j] = temp;
			}
			v[i] = temp_v;
		}


		ans = checker();

		cout << "#" << testcase << " " << ans << endl;
		ans = 0;
	}
}