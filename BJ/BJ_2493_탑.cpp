#include <iostream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	int N;
	int min_ind = -1, max = 0, ind = 0, temp;
	
	cin >> N;

	vector <int> v, v_ind;

	v.assign(N + 1, 0);
	v_ind.assign(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &temp);
		v[i] = temp;

		if (min_ind != -1)
		{
			if (v[min_ind] >= temp)
			{
				printf("%d ", min_ind);
				v_ind[min_ind] = i;
				min_ind = i;
				continue;
			}
		}

		if (temp >= max)
		{
			if (temp == max)
				printf("%d ", ind);
			else
				printf("0 ");

			min_ind = i;
			max = temp;
			ind = i;
		}
		else
		{
			int temp_ind = ind;
			while (1)
			{
				if (v_ind[temp_ind] == 0)
				{
					printf("%d ", temp_ind);
					min_ind = i;
					v_ind[temp_ind] = i;
					break;
				}

				if (v[v_ind[temp_ind]] > temp)
				{
					temp_ind = v_ind[temp_ind];
					continue;
				}
				else if (v[v_ind[temp_ind]] < temp)
				{
					printf("%d ", temp_ind);
					min_ind = i;
					v_ind[temp_ind] = i;
					break;
				}
				else
				{
					printf("%d ", v_ind[temp_ind]);
					min_ind = i;
					v_ind[temp_ind] = i;
					break;
				}

			}
		}

	}
}