#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	stack<char> st;
	string question;
	int num, check = 0;

	cin >> num;

	for (int k = 0; k < num; k++)
	{
		cin >> question;

		for (int i = 0; i < question.length(); i++)
		{
			if (question.at(i) == '(')
				st.push(question.at(i));
			else if (st.empty())
			{
				check = 1;
				break;
			}
			else
				st.pop();
		}
		if (st.empty() && check != 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		while (!st.empty())
			st.pop();
		check = 0;
	}

}