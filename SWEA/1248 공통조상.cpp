#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > v;
vector <int> temp_v;
int Answer_num;
int Answer_size = 1;

void Set_level(int pa_level, int ch)
{
	v[3][ch] = v[3][ch] + pa_level + 1;
	
	if (v[1][ch] != 0)
		Set_level(v[3][ch], v[1][ch]);

	if (v[0][ch] != 0)
		Set_level(v[3][ch], v[0][ch]);

}

void Compare(int a, int b)
{
	if (v[3][a] == v[3][b])
	{
		if (a == b)
			Answer_num = a;
		else
			Compare(v[2][a], v[2][b]);
	}

	else if (v[3][a] > v[3][b])
		Compare(v[2][a], b);
	else
		Compare(a, v[2][b]);
}

void get_size(int ans)
{
	if (v[1][ans] != 0)
	{
		Answer_size++;
		get_size(v[1][ans]);
	}

	if (v[0][ans] != 0)
	{
		Answer_size++;
		get_size(v[0][ans]);
	}

}

int main()
{
	int T, testcase;

	cin >> testcase;

	for (T = 1; T <= testcase; T++)
	{
		int V, E, A, B;
		int par, chi;

		Answer_num = 0;
		Answer_size = 1;
		temp_v.clear();
		v.clear();

		cin >> V >> E >> A >> B;

		temp_v.assign(V + 1, 0);
		v.assign(4, temp_v);

		for (int i = 0; i < E; i++)
		{
			cin >> par >> chi;
			if (v[0][par] == 0)
			{
				v[0][par] = chi;
				v[2][chi] = par;
			}
			else
			{
				v[1][par] = chi;
				v[2][chi] = par;
			}

			Set_level(v[3][par], chi);
			
		}

		Compare(A, B);
		get_size(Answer_num);

		cout << "#" << T << " " << Answer_num << " " << Answer_size << endl;
	}
}