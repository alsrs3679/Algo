#include <iostream>

using namespace std;

int main()
{
	int E, S, M;
	int e, s, m;

	cin >> E >> S >> M;
	e = E;
	s = S;
	m = M;
	while (e != m || e != s)
	{
		if (e < m)
		{
			if (e <= s)
				e += 15;
			else if (s < e)
				s += 28;
		}
		else
		{
			if (m <= s)
				m += 19;
			else if (s < m)
				s += 28;
		}
	}
	cout << e;
}