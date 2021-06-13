#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;
vector <string> str;
vector <int> visit;
int N, K;
int ans = 0;

void combi(int ind, int cnt)
{
	if (cnt > K - 5)
		return;

	if (cnt == K - 5)
	{
		vector <int> alpa;
		alpa.assign(26, 0);

		for (int i = 0; i < arr.size(); i++)
		{
			if (visit[i] == 1)
				alpa[arr[i]] = 1;
		}
		
		int temp_ans = 0;
		for (int i = 0; i < N; i++)
		{
			string s = str[i];
			int che = 0;
			for (int j = 4; j < s.length() - 4; j++)
			{
				if (s.at(j) == 'a' || s.at(j) == 'c' || s.at(j) == 'i' || s.at(j) == 'n' || s.at(j) == 't' || alpa[s.at(j) - 97] == 1)
					continue;
				che = 1;
				break;
			}
			if (che == 0)
				temp_ans++;
		}
		if (ans < temp_ans)
			ans = temp_ans;
		return;
	}

	for (int i = ind; i < arr.size(); i++)
	{
		visit[i] = 1;
		combi(i + 1, cnt + 1);
		visit[i] = 0;
	}

}

int main()
{
	cin >> N >> K;
	string str_temp;
	for (int i = 0; i < N; i++)
	{
		cin >> str_temp;
		str.push_back(str_temp);
	}
	if (K < 5)
	{
		cout << 0;
		return 0;
	}
	if (K == 26)
	{
		cout << N;
		return 0;
	}

	vector <int> alpa;

	for (int i = 0; i < N; i++)
	{
		alpa.assign(26, 0);
		string s = str[i];
		s = s.substr(4);
		for (int j = 0; j < s.length() - 4; j++)
		{
			int temp = s.at(j);
				
			if (temp == 97 || temp == 99 || temp == 105 || temp == 110 || temp == 116)
				continue;
				
			alpa[temp - 97] = 1;
		}
		for (int k = 0; k < 26; k++)
		{
			if (alpa[k] == 1)
			{
				int check = 0;
				for (int q = 0; q < arr.size(); q++)
				{
					if (arr[q] == k)
					{
						check = 1;
						break;
					}
				}
				if (check == 0)
					arr.push_back(k);
			}
		}
	}

	visit.assign(arr.size(), 0);

	combi(0, 0);
	cout << ans;

	// 전부 지웠다가 다시작성 후 실패...

}