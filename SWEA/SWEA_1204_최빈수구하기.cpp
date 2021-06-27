#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T, testcase, max = 0, temp;
	vector <int> v;

	cin >> testcase;

	for (int T = 1; T <= testcase; T++)
	{
		max = 0;
		cin >> temp;
		v.clear();
		v.assign(101, 0);
		for (int i = 0; i < 1000; i++)
		{
			cin >> temp;
			v[temp]++;
		}

		for (int i = 0; i < 101; i++)
		{
			if (max < v[i])
				max = v[i];
		}
		for (int i = 100; i >= 0; i--)
		{
			if (v[i] == max)
			{
				cout << "#" << T << " " << i << endl;
				break;
			}
		}
	}
}