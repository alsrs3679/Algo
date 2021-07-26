#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector <int> population, temp_v;
vector <vector <int> > v;

vector <int> temp_part, lt, rt;
vector <vector <int> > part;

vector <int> num, num_check;

int minn = 99999;

int Combi(int n, int r)
{
	if (n == r || r == 0)
		return 1;

	return(Combi(n - 1, r - 1) + Combi(n - 1, r));
}

void particial(int depth)
{
	if (N == depth)
	{
		int i;
		for (i = 0; i < N; i++)
		{
			if (num_check[i] == 1)
				temp_part.push_back(num[i]);
		}
		part.push_back(temp_part);
		temp_part.clear();
		return;
	}
	num_check[depth] = 1;
	particial(depth + 1);
	num_check[depth] = 0;
	particial(depth + 1);
}

int main()
{
	int temp, temp2;
	cin >> N;

	population.push_back(0);
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		population.push_back(temp);
	}

	temp_v.assign(N + 1, 0);
	v.assign(N + 1, temp_v);

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{
			cin >> temp2;
			v[i][temp2] = 1;
		}
		num.push_back(i);
		num_check.push_back(0);
	}

	particial(0);

	int len = part.size();

	for (int i = 1; i <= len / 2 - 1; i++)
	{
		lt = part[i];
		rt = part[len - 1 - i];

		queue <int> que1, que2;
		vector <int> check_que1, check_que2;
		check_que1.assign(lt.size(), 0);
		check_que2.assign(rt.size(), 0);


		que1.push(lt[0]);
		que2.push(rt[0]);
		check_que1[0] = 1;
		check_que2[0] = 1;
		while (!que1.empty())
		{
			int ind1 = que1.front();
			que1.pop();

			for (int j = 0; j < lt.size(); j++)
			{
				/*if (lt.size() == 1)
					check_que1[0] = 0;*/
				if (check_que1[j] == 1)
					continue;
				else
				{
					if (v[ind1][lt[j]] == 1)
					{
						que1.push(lt[j]);
						check_que1[j] = 1;
					}
				}
			}


		}

		while (!que2.empty())
		{
			int ind2 = que2.front();
			que2.pop();

			for (int j = 0; j < rt.size(); j++)
			{
				/*if (rt.size() == 1)
					check_que2[0] = 0;*/
				if (check_que2[j] == 1)
					continue;
				else
				{
					if (v[ind2][rt[j]] == 1)
					{
						que2.push(rt[j]);
						check_que2[j] = 1;
					}
				}
			}
		}

		int check1 = 0, check2 = 0;
		int lt_sum = 0, rt_sum = 0;

		for (int j = 0; j < lt.size(); j++)
		{
			lt_sum += population[lt[j]];
			if (check_que1[j] == 0)
				check1 = 1;
		}

		for (int j = 0; j < rt.size(); j++)
		{
			rt_sum += population[rt[j]];
			if (check_que2[j] == 0)
				check2 = 1;
		}

		if (check1 == 0 && check2 == 0)
		{
			if (abs(lt_sum - rt_sum) < minn)
				minn = abs(lt_sum - rt_sum);
		}
		else
			continue;

	}
	if (minn == 99999)
		minn = -1;
	cout << minn;

}