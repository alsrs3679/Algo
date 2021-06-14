#include <iostream>
#include <vector>

using namespace std;

int min_locate(vector <int>& a, int check)
{
	int answer = 999999999;
	int loc = -1;
	for (int i = 0; i < 3; i++)
	{
		if (check == i)
			continue;
		else if (answer > a.at(i))
		{
			answer = a.at(i);
			loc = i;
		}
	}
	return loc;
}

int main()
{
	vector< vector<int> > v;
	vector<int> sum;
	vector<int> temp;

	sum.push_back(0);
	sum.push_back(0);
	sum.push_back(0);

	int n_house = 0, check = 0;
	int r, g, b;

	cin >> n_house;

	for (int i = 0; i < n_house; i++)
	{
		cin >> r >> g >> b;

		temp.push_back(r);
		temp.push_back(g);
		temp.push_back(b);

		v.push_back(temp);
		temp.clear();
	}

	for (int j = 1; j < n_house; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			check = min_locate(v[j - 1], k);
			sum[k] = v[j][k] + v[j - 1][check];
		}
		v[j] = sum;
	}

	int ans_loc = min_locate(v[n_house - 1], 9);

	cout << v[n_house - 1][ans_loc] << endl;
}