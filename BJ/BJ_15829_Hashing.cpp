#include <iostream>
#include <vector>

using namespace std;

long long cal(long long a, int b)
{
	for (int i = 0; i < b; i++)
	{
		a *= 31;
		a = a % 1234567891;
	}
	return a;
}

int main()
{
	int L;
	string s;
	cin >> L >> s;

	long long temp, ans = 0, asd = 96;
	//96
	for (int i = 0; i < L; i++)
	{
		temp = s.at(i) - asd;
		temp = cal(temp, i);
		ans += temp;
		ans = ans % 1234567891;
	}

	cout << ans;
}