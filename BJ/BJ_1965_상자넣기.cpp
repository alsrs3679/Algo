#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string n_string;
	vector<int> v;
	vector<int> max_v;
	int box = 0;
	int max = -1;
	int k;
	int check = 0;
	string n_temp = "";

	cin >> box;
	cin.ignore();
	getline(cin, n_string);

	for (int i = 0; i < n_string.length(); i++)
	{
		if (n_string.at(i) == ' ')
		{
			v.push_back(atoi(n_temp.c_str()));
			n_temp = "";
		}
		else
			n_temp += n_string.at(i);
	}
	v.push_back(atoi(n_temp.c_str()));

	for (int s = 0; s < box; s++)
		max_v.push_back(0);

	for (int j = 1; j < box; j++)
	{
		for (k = 0; k < j; k++)
		{
			if (v[j] > v[k])
			{
				if (max < max_v[k])
				{
					max = max_v[k];
					check = 1;
				}

			}
		}
		max_v[k] = max + 1;
		max = -1;
		check = 0;
	}

	for (int q = 0; q < box; q++)
	{
		if (max < max_v[q])
			max = max_v[q];
	}
	cout << max + 1 << endl;

}
