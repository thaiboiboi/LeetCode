#include <stdio.h>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

char has[110][210][210];
int n;
int ans;
char map[110][210];

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
    freopen("TAMGIAC.inp","r",stdin);
    freopen("TAMGIAC.out","w",stdout);
	int cas = 1;

	while (scanf("%d", &n) == 1 && n)
	{
		memset(has, 0, sizeof has);
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; map[i][j]; j++)
			{
				if (map[i][j] == '-')
				{
					ans = 1;
				}
			}
		}
		int l = n * 2 - 1;
		for (int j = 1; j < l; j += 2)
		{
			if (map[0][j] == '-')
			{
				ans = 1;
				has[0][j][1] = 1;
			}
		}
		for (int i = 1; i < n; i++)
		{
			l = (n - i) * 2 - 1;
			for (int j = 1; j < l; j += 2)
			{
				if (map[i][j] == '#')	continue;
				has[i][j][1] = 1;
				ans = max(ans, 1);
				for (int len = 3; len + j <= l; len += 2)
				{
					if (map[i][j + len - 1] == '#' || map[i][j + len - 2] == '#')
					{
						break;
					}
					if (has[i - 1][j + 2][len - 2])
					{
						has[i][j][len] = 1;
						ans = max(ans, len);
					}
				}
			}
		}
		memset(has, 0, sizeof has);
		has[n - 1][0][1] = (map[n - 1][0] == '-');
		for (int i = n - 2; i >= 0; i--)
		{
			l = (n - i) * 2 - 1;
			for (int j = 0; j < l; j += 2)
			{
				if (map[i][j] == '#')	continue;
				has[i][j][1] = 1;
				ans = max(ans, 1);
				for (int len = 3; len + j <= l; len += 2)
				{
					if (map[i][j + len - 1] == '#' || map[i][j + len - 2] == '#')
					{
						break;
					}
					if (has[i + 1][j][len - 2])
					{
						has[i][j][len] = 1;
						ans = max(ans, len);
					}
				}
			}
		}
		printf("%d\n",(ans + 1)/2 * (1 + ans)/2);
	}
	return 0;
}
