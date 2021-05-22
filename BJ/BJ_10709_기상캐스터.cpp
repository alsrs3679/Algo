#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int H, W;
	int count = 0;
	char a;

	cin >> H >> W;
	getchar();
	vector <vector <int> > v;
	vector <int> temp_v;

	temp_v.assign(W, 0);
	v.assign(H, temp_v);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			scanf("%c", &a);
			if (a == 'c')
			{
				v[i][j] = 0;
				count = 1;
			}
			else if (count == 0)
				v[i][j] = -1;
			else
			{
				v[i][j] = count;
				count++;
			}
		}
		getchar();
		count = 0;
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}

}