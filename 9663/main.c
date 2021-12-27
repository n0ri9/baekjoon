#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

void	set(int i, int *pos, int *flag, int *flag_l, int *flag_r, int n)
{
	int j;

	j = 0;
	while (j < n)
	{
		if (!flag[j] && !flag_l[i + j] && !flag_r[i - j + (n - 1)])
		{
			pos[i] = j;
			if (i == (n - 1))
				cnt++;
			else
			{
				flag[j] = 1;
				flag_l[i + j] = 1;
				flag_r[i - j + (n - 1)] = 1;
				set(i + 1, pos, flag, flag_l,  flag_r, n);
				flag[j] = 0;
				flag_l[i + j] = 0;
				flag_r[i - j + (n - 1)] = 0;
			}
		}
		j++;
	}
}

int	main(void)
{
	int i;
	int n;
	int *pos;
	int *flag;
	int *flag_l;
	int *flag_r;

	i = 0;
	scanf("%d", &n);
	pos = (int *)malloc(sizeof(int) * n);
	flag = (int *)malloc(sizeof(int) * n);
	flag_l = (int *)malloc(sizeof(int) * ((n * 2) - 1));
	flag_r = (int *)malloc(sizeof(int) * ((n * 2) - 1));
	while (i < n)
	{
		flag[i] = 0;
		i++;
	}
	i = 0;
	while (i < (n * 2) - 1)
	{
		flag_l[i] = 0;
		flag_r[i] = 0;
		i++;
	}
	set(0, pos, flag, flag_l,  flag_r, n);
	printf("%d\n", cnt);
	free(pos);
	free(flag);
	free(flag_l);
	free(flag_r);
	return (0);
}
