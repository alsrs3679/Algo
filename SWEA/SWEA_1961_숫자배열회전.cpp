#include<iostream>
#include<vector>

using namespace std;

int testcase, T, N, temp;
vector <int> temp_v, temp_ans;
vector <vector <int>> v1, ans;
int mul;
void rotate()
{
	vector <vector <int>> q;
	mul = 1;
	temp = 0;
	for (int a = 0; a < 3; a++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				temp_v.push_back(v1[j][i]);
			}
			q.push_back(temp_v);
			temp_v.clear();
		}

		v1 = q;

		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				temp = temp + v1[i][j] * mul;
				mul = mul * 10;
			}
			ans[i][a] = temp;
			temp = 0;
			mul = 1;
		}
		q.clear();
	}
}

int main()
{
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++)
	{
		cin >> N;
		temp_ans.assign(N, 0);
		ans.assign(N, temp_ans);

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> temp;
				temp_v.push_back(temp);
			}
			v1.push_back(temp_v);
			temp_v.clear();
		}

		rotate();
		for (int qwe = 0; qwe < N - 1; qwe++)
		{
			mul = mul * 10;
		}
		cout << "#" << testcase << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int mk = mul;
				while (mk > ans[i][j])
				{
					cout << "0";
					mk = mk / 10;
				}
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}

		ans.clear();
		v1.clear();
		temp_ans.clear();
		temp_v.clear();
	}
}
