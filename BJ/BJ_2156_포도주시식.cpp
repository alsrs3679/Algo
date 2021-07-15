#include<iostream>
#include<vector>

using namespace std;

int find_max(int a, int b, int c)
{
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}

int main()
{
	vector <int> v;
	vector <int> dpv;

	int i;
	int num, temp;

	cin >> num;

	for (i = 0; i < num; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	dpv.push_back(v[0]);
	dpv.push_back(v[0] + v[1]);
	dpv.push_back(find_max(dpv[1], dpv[0] + v[2], v[1] + v[2]));
	for (i = 3; i < num; i++)
		dpv.push_back(find_max(dpv[i - 1], dpv[i - 2] + v[i], dpv[i - 3] + v[i - 1] + v[i]));

	cout << dpv[num - 1];

}