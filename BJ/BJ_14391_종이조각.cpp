#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	string temp;
	cin >> N >> M;

	vector <vector <int> > v;
	vector <int> v_temp;


	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
			v_temp.push_back(temp[j] - 48);

		v.push_back(v_temp);
		v_temp.clear();
	}


	int max = 0;
	int sum, r_sum, c_sum;
	for (int i = 0; i < (1 << N * M); i++)
	{
		sum = 0;
		for (int r = 0; r < N; r++)
		{
			r_sum = 0;
			for (int c = 0; c < M; c++)
			{
				if ((1 << r * M + c & i) == 0)
				{
					r_sum *= 10;
					r_sum += v[r][c];
				}
				else
				{
					sum += r_sum;
					r_sum = 0;
				}
			}
			sum += r_sum;
		}


		for (int c = 0; c < M; c++)
		{
			c_sum = 0;
			for (int r = 0; r < N; r++)
			{
				if ((1 << r * M + c & i) != 0)
				{
					c_sum *= 10;
					c_sum += v[r][c];
				}
				else
				{
					sum += c_sum;
					c_sum = 0;
				}
			}
			sum += c_sum;
		}

		if (max < sum)
			max = sum;
	}

	cout << max;
}