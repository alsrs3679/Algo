#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	vector <bool> v;
	int temp, T;

	//	string todo;

	char todo[10] = { "" };
	v.assign(21, 0);

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%s", todo);
		if (strcmp(todo, "add") == 0)
		{
			scanf("%d", &temp);
			v[temp] = 1;
		}
		else if (strcmp(todo, "remove") == 0)
		{
			scanf("%d", &temp);
			v[temp] = 0;
		}
		else if (strcmp(todo, "check") == 0)
		{
			scanf("%d", &temp);
			printf("%d\n", (int)v[temp]);
		}
		else if (strcmp(todo, "toggle") == 0)
		{
			scanf("%d", &temp);
			v[temp] = !v[temp];
		}
		else if (strcmp(todo, "all") == 0)
		{
			for (int j = 1; j <= 20; j++)
			{
				v[j] = 1;
			}
		}
		else if (strcmp(todo, "empty") == 0)
		{
			for (int j = 1; j <= 20; j++)
			{
				v[j] = 0;
			}
		}
	}
}