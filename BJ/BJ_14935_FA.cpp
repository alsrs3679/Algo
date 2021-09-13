#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int power = 1;
	int n;
	int div = 1;
	int temp;
	int fa = 0;
	int check = 0;
	string ans;

	cin >> n;

	while (fa != n)
	{
		fa = n;

		if (n / div >= 10)
		{
			div = div * 10;
			power++;
		}
		temp = n / div;
		n = temp * power;
		check++;
		if (check > 10000000000)
		{
			ans = "NFA";
			break;
		}
	}

	if (fa == n)
		ans = "FA";

	cout << ans;
}