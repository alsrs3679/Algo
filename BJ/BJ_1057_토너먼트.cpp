#include <iostream>

using namespace std;

int main()
{
	int N, A, B;
	int max_game = 1;
	int temp, ans;
	cin >> N >> A >> B;

	int cnt = 0;
	while (1)
	{
		cnt++;

		N = (N + 1) / 2;
		A = (A + 1) / 2;
		B = (B + 1) / 2;
		if (A == B)
		{
			ans = cnt;
			break;
		}
		
	}

	cout << ans;
}