#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#pragma warning (disable:4996)

using namespace std;

int main()
{
	int N, M, temp, a = 0, b = 100000, mid = 1, key;
	vector <int> v1, v2;
	vector <int> ans;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		v1.push_back(temp);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);
		v2.push_back(temp);
	}
	ans.assign(M, 0);

	sort(v1.begin(), v1.end());

	for (int i = 0; i < M; i++)
	{
		a = 0;
		b = N - 1;
		key = i;

		while (a != b)
		{
			mid = floor((double)(a + b) / 2);

			if (v2[key] >= v1[mid])
			{
				if (v2[key] == v1[mid])
					b = a;
				else
				{
					a = mid + 1;
					mid++;
				}
			}
			else
				b = mid;
		}
		if (v1[mid] == v2[key])
			ans[i] = 1;
	}

	for (int i = 0; i < M; i++)
		printf("%d\n", ans[i]);
}