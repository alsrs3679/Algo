#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T, testcase;

	cin >> testcase;

	for (T = 1; T <= testcase; T++)
	{
		vector <vector <int> > v, ans_v;
		vector <int> temp_v;
		int N, temp;
		int cnt = 0;
		int min = 10000;
		int ansx, ansy;
		int ans = 0;


		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> temp;
				temp_v.push_back(temp);
			}
			v.push_back(temp_v);
			temp_v.clear();
		}

		temp_v.assign(N + 1, 0);
		ans_v.assign(2, temp_v);


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (v[i][j])
				{
					cnt++;
				}
				else if(cnt != 0)
				{
					if (ans_v[0][cnt] == 0)
						ans++;

					ans_v[0][cnt]++;
					cnt = 0;
				}
			}
			if (cnt != 0)
			{
				if (ans_v[0][cnt] == 0)
					ans++;

				ans_v[0][cnt]++;
				cnt = 0;
			}
		}

		for (int i = 1; i <= N; i++)
			ans_v[1][i] = i * ans_v[0][i];
		



		cout << "#" << T << " " << ans << " ";

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (ans_v[1][j] > 0 && ans_v[1][j] <= min)
				{
					if (ans_v[1][j] == min)
					{
						if (ansy > ans_v[0][j])
						{
							min = ans_v[1][j];
							ansx = j;
							ansy = ans_v[0][j];
						}
					}
					else
					{

						min = ans_v[1][j];
						ansx = j;
						ansy = ans_v[0][j];
					}
				}
			}
			if(min != 10000)
				cout << ansy << " " << ansx << " ";
			ans_v[1][ansx] = 0;
			min = 10000;
			

		}
		cout << endl;

	}
}