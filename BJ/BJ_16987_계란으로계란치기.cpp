#include <iostream>

using namespace std;

int N;
int maxx = 0;
int egg[8][3];


void dfs(int att, int def, int cnt)
{
	if (att == def)
		return;

	if (egg[def][2] == 0)
	{
		if (egg[att][0] <= egg[def][1])
		{
			egg[att][2] = 1;
			cnt++;
		}
		else
			egg[att][0] -= egg[def][1];

		if (egg[def][0] <= egg[att][1])
		{
			egg[def][2] = 1;
			cnt++;
		}
		else
			egg[def][0] -= egg[att][1];
	}
	else
		return;


	while (true)
	{
		if (++att >= N)
		{
			if (maxx < cnt)
				maxx = cnt;

			return;
		}
		else
		{
			if (egg[att][2] == 0)
				break;
		}
	}

	int att_h, att_p, def_h, def_p;
	for (int i = 0; i < N; i++)
	{
		att_h = egg[att][0];
		att_p = egg[att][2];
		def_h = egg[i][0];
		def_p = egg[i][2];
		dfs(att, i, cnt);
		egg[att][0] = att_h;
		egg[att][2] = att_p;
		egg[i][0] = def_h;
		egg[i][2] = def_p;
	}

	if (maxx < cnt)
		maxx = cnt;

}

int main() {

	cin >> N;
	int temp1, temp2;

	for (int i = 0; i < N; i++)
	{
		cin >> temp1 >> temp2;
		egg[i][0] = temp1;
		egg[i][1] = temp2;
	}

	maxx = 0;
	int att_h, att_p, def_h, def_p;
	for (int i = 1; i < N; i++)
	{
		att_h = egg[0][0];
		att_p = egg[0][2];
		def_h = egg[i][0];
		def_p = egg[i][2];
		dfs(0, i, 0);
		egg[0][0] = att_h;
		egg[0][2] = att_p;
		egg[i][0] = def_h;
		egg[i][2] = def_p;
	}

	cout << maxx << endl;
}

