#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <vector <long long> > v;
vector <long long> temp_v;

int main()
{
	int T, testcase;

	cin >> testcase;

	for (T = 1; T <= testcase; T++)
	{
		long long N, locate, E, Answer = 0;
		long long min = 2000000000000;
		long long next;
		cin >> N;

		temp_v.assign(N, 0);
		v.push_back(temp_v);
		temp_v.clear();

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> locate;
				temp_v.push_back(locate);
			}
			v.push_back(temp_v);
			temp_v.clear();
		}

		cin >> E;

		for (int i = 1; i < N; i++)
		{
			if (min > pow((v[1][0] - v[1][i]), 2) + pow((v[2][0] - v[2][i]), 2))
			{
				next = i;
				min = pow((v[1][0] - v[1][i]), 2) + pow((v[2][0] - v[2][i]), 2);
			}
		}



	}
}