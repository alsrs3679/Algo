#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

using namespace std;

int main()
{
	long long M, N, L, temp, x, y;
	int ans = 0;
	cin >> M >> N >> L;

	vector <long long> v;

	for (int i = 0; i < M; i++)
	{
		scanf("%lld", &temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		scanf("%lld %lld", &x, &y);
		if (y > L)
			continue;

		int a = 0, b = M - 1;
		//0번째 인덱스값보다 왼쪽에 위치
		if (x <= v[a])
		{
			if (v[a] - x + y <= L)
				ans++;
		}
		//마지막 인덱스값보다 오른쪽에 위치
		else if (v[b] <= x)
		{
			if (x - v[b] + y <= L)
				ans++;
		}
		//v[a] ~ v[b]에 x값이 존재
		else 
		{
			while (1)
			{
				long long c = (a + b) / 2;
				if (c == a)
					break;
				if (v[a] <= x && x < v[c])
					b = c;
				else
					a = c;
			}

			//v[a], v[b]와 동물의 위치만 비교
			if (abs(v[a] - x) + y <= L)
				ans++;
			else if (abs(v[b] - x) + y <= L)
				ans++;
		}
	}

	cout << ans;
}