#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int T, len_qu, len_str, count, ans;
	string str, qu;

	for (int q = 0; q < 10; q++)
	{
		count = 0;
		ans = 0;
		cin >> T;

		cin >> qu;
		cin >> str;


		len_qu = qu.size();
		len_str = str.size();

		for (int i = 0; i <= len_str - len_qu; i++)
		{
			for (int j = 0; j < len_qu; j++)
			{
				if (str.at(i + j) == qu.at(j))
					count++;
			}
			if (count == len_qu)
				ans++;

			count = 0;
		}

		cout << "#" << T << " " << ans << endl;

		qu.clear();
		str.clear();

	}
}