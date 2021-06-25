#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T;

	for (T = 1; T <= 10; T++)
	{
		int N, temp, sum = 0, max = 0;
		cin >> N;
		vector <vector <int>> v;
		vector <int> v_temp;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				scanf("%d", &temp);
				v_temp.push_back(temp);
				sum = sum + temp;
			}
			v.push_back(v_temp);
			if (max < sum)
				max = sum;
			sum = 0;
			v_temp.clear();
		}

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
				sum = sum + v[j][i];

			if (max < sum)
				max = sum;
			sum = 0;
		}

		for (int i = 0; i < 100; i++)
			sum = sum + v[i][i];

		if (max < sum)
			max = sum;

		sum = 0;

		for (int i = 0; i < 100; i++)
			sum = sum + v[i][99 - i];

		if (max < sum)
			max = sum;



		cout << "#" << T << " " << max << endl;

		v.clear();
		v_temp.clear();
		sum = 0, max = 0;
	}
}