#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	for (int gogo = 0; gogo < 10; gogo++)
	{
		int T, num, temp, check = 1, min = 0x7FFFFFFF, div;
		vector <int> v;
		v.assign(8, 0);

		cin >> T;

		for (int i = 0; i < 8; i++)
		{
			cin >> num;
			v[i] = num;
			if (min > num)
				min = num;
		}

		div = min / 15;

		for (int i = 0; i < 8; i++)
			v[i] = v[i] - 15 * (div - 1);


		while (check)
		{
			for (int i = 1; i <= 5; i++)
			{
				temp = v[0] - i;
				if (temp <= 0)
				{
					check = 0;
					temp = 0;
				}
				for (int j = 1; j < 8; j++)
					v[j - 1] = v[j];
				v[7] = temp;
				if (check == 0)
					break;
			}
		}


		cout << "#" << T << " ";
		for (int i = 0; i < 8; i++)
			cout << v[i] << " ";
		cout << endl;
	}
}
