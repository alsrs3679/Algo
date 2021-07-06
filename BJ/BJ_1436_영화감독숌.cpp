#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int N, go = 0, num;
	int cnt = 0;
	int check = 0;
	cin >> N;
	int ans = 0;
	while (cnt != N)
	{
		check = 0;
		num = go;
		while (num != 0)
		{
			if (num % 10 == 6)
			{
				check++;
				if (check == 3)
					break;
				num = num / 10;
			}
			else
			{
				check = 0;
				num = num / 10;
			}
		}



		if (check == 3)
		{
			cnt++;
			ans = go;
		}
		go++;
	}

	if (N == 1)
		ans = 666;

	cout << ans << endl;

}