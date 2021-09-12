#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	int temp;
	int x;
	int div = 1;
	int temp_div;
	int ans = 0;
	int power = 1;

	cin >> n >> x;

	for (int i = 1; i <= n; i++)
	{
		temp = i;
		if (temp >= div * 10)
		{
			div = div * 10;
			power++;
		}
		temp_div = div;
		while (temp != 0)
		{
			if (temp / temp_div == x)
				ans++;
			temp = temp % temp_div;
			temp_div = temp_div / 10;
		}
	}
	cout << ans;
}