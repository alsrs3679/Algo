#include <iostream> 
#include <vector>

using namespace std;

int main()
{
	int testcase;

	vector <int> v, check_v;

	v.assign(1000000, 0);
	check_v.assign(79498, 0);

	int count = 0;

	cin.tie(0);

	for (int i = 2; i < 1000000; i++)
	{
		if (!v[i])
		{
			check_v[count++] = i;
			for (int j = 2; j * i < 1000000; j++)
				v[j * i] = 1;
		}
	}

	cin >> testcase;
	while (testcase--)
	{
		int temp;
		int res = 0;
		cin >> temp;
		for (int i = 0; check_v[i] < temp; i++)
			if (temp - check_v[i] >= check_v[i] && !v[temp - check_v[i]])
				res++;
		cout << res << '\n';
	} return 0;
}

