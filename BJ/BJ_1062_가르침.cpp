#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector <string> str;
	string str_temp;
	for (int i = 0; i < N; i++)
	{
		cin >> str_temp;
		str.push_back(str_temp);
	}

	int asd = 'a';
	cout << asd << endl;

	cout << str[0].substr(3, 7);
}