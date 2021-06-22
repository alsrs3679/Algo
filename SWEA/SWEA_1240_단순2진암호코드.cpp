#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	vector <vector <char> > v;
	vector <char> temp_v;
	int last;
	int N, M;
	int testcase;
	int index_t = 6;
	int index_a = 7;
	int check1 = 0, check2 = 0;

	vector <int> ans;
	string temp_ans = "       ";
	//char temp_ans[7];
	//vector <char> temp_ans;
	ans.assign(8, 0);
	//temp_ans.assign(7, ' ');
	//vector <string> code;
	//code.assign(10, "");
	string code[10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };


	/*code[0] = "0001101";
	code[1] = "0011001";
	code[2] = "0010011";
	code[3] = "0111101";
	code[4] = "0100011";
	code[5] = "0110001";
	code[6] = "0101111";
	code[7] = "0111011";
	code[8] = "0110111";
	code[9] = "0001011";*/

	char find;

	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		index_a = 7;
		v.clear();
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			check1 = 0;
			for (int j = 0; j < M; j++)
			{
				cin >> find;
				if (find == '1')
					check1 = 1;
				temp_v.push_back(find);
			}
			v.push_back(temp_v);
			if (check1 == 0)
				v.pop_back();
			temp_v.clear();
			getchar();
		}


		for (int i = M - 1; i > 6; i--)
		{
			if (v[0][i] == '1')
			{
				for (int j = 0; j < 7; j++)
				{
					temp_ans[index_t--] = v[0][i - j];
				}

				for (int k = 0; k < 10; k++)
				{
					if (temp_ans == code[k])
					{
						ans[index_a--] = k;
						break;
					}
				}
				check2 = 1;
			}
			if (check2 == 1)
				i = i - 6;
			index_t = 6;

			check2 = 0;
		}

		last = (ans[0] + ans[2] + ans[4] + ans[6]) * 3 + (ans[1] + ans[3] + ans[5]) + ans[7];

		if (last % 10 == 0)
			cout << "#" << t << " " << ans[0] + ans[2] + ans[4] + ans[6] + ans[1] + ans[3] + ans[5] + ans[7] << endl;
		else
			cout << "#" << t << " " << 0 << endl;


	}

}