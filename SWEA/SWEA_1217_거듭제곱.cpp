#include<iostream>

using namespace std;



int power(int N, int M, int accum)
{
	if (M == 0)
		return accum;
	else
		return power(N, M - 1, accum * N);
}

int main()
{
	for (int qwe = 0; qwe < 10; qwe++)
	{
		int N, M, ans;
		int T;
		cin >> T;
		cin >> N >> M;

		ans = power(N, M, 1);


		cout << "#" << T << " " << ans << endl;
	}
}