#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int i, j;
	int temp1 = 0;
	int temp2 = 0;
	int count = 0;
	vector <int> v, ans;

	cin >> N;

	v.assign(N, 100);
	ans.assign(N, 100);

	for (i = 0; i < N; i++)
	{
		cin >> temp1;
		v[i] = temp1;
	}

	ans[v[0]] = 1;

	for (i = 1; i < N; i++)
	{
		temp2 = v[i];
		for (j = 0; j <= temp2; j++)
		{
			if ((i + 1) > ans[j])
			{
				count++;
				temp2++;
			}
		}
		ans[v[i] + count] = i + 1;
		count = 0;
	}


	for (i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}

}