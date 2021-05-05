#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v, num;

void combi(int now, int ind)
{
	if (now == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << num[i] << " ";
		cout << endl;
		return;
	}

	for(int i = ind; i < N; i++)
	{
		num[now] = v[i];
		combi(now + 1, i + 1);
	}

}

int main()
{
	while (1)
	{
		int temp;
		
		cin >> N;
		
		if (N == 0)
			break;

		v.clear();
		num.assign(6, 0);

		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			v.push_back(temp);
		}

		combi(0, 0);
		cout << endl;
	}
}