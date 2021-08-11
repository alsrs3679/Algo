#include <iostream>
#include <vector>

using namespace std;


int N, M;
vector <int> v, ans;

void permu(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < depth; i++)
		{
			if (ans[i] != 0)
				cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (v[i] == 0)
		{
			v[i] = 1;
			ans[depth] = i + 1;
			permu(depth + 1);
			v[i] = 0;
		}
	}
}


int main()
{
	cin >> N >> M;

	v.assign(N, 0);
	ans.assign(M, 0);

	permu(0);
}