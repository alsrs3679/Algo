#include <iostream>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	int T, N, max, min, temp;
	int max_index, min_index;
	vector <int> v;

	for (int T = 1; T <= 10; T++)
	{
		cin >> N;
		for (int i = 0; i < 100; i++)
		{
			scanf("%d", &temp);
			v.push_back(temp);
		}

		while (N > 0)
		{
			max = 0, min = 1000;
			for (int i = 0; i < 100; i++)
			{
				if (v[i] > max)
				{
					max = v[i];
					max_index = i;
				}
				if (v[i] < min)
				{
					min = v[i];
					min_index = i;
				}
			}

			v[min_index]++;
			v[max_index]--;
			N--;
		}
		max = 0, min = 1000;
		for (int i = 0; i < 100; i++)
		{
			if (v[i] > max)
				max = v[i];
			if (v[i] < min)
				min = v[i];
		}
		cout << "#" << T << " " << max - min << endl;

		v.clear();
	}

}