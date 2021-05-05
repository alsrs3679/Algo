#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int map2[16];
vector <int> map;
int ans = 0;
int N;

int check(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		if (map2[i] == c || (r - i) == abs(c - map2[i]))
			return 0;
	}
	return 1;
}
void chess(int r, int c)
{
	r++;
	if (r == N)
	{
		ans++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (check(r, i))
		{
			//map.push_back(i);
			map2[r] = i;
			chess(r, i);
			//map.pop_back();
		}
	}


}
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		//map.push_back(i);
		map2[0] = i;
		chess(0, i);
		//map.pop_back();
	}

	cout << ans;
}