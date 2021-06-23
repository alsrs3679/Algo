#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;

	cin >> T;

	for (int testcase = 1; testcase <= T; testcase++)
	{
		string num;
		vector <char> aa;
		int ans = 0;
		int len;

		cin >> num;

		len = num.length();

		aa.assign(len, '0');

		for (int i = 0; i < len; i++)
		{
			if (num[i] == aa[i])
				continue;

			else
			{
				ans++;
				for (int j = i; j < len; j++)
				{
					if (aa[j] == '0')
						aa[j] = '1';

					else if (aa[j] == '1')
						aa[j] = '0';

				}
			}
		}

		printf("#%d %d\n", testcase, ans);
	}

