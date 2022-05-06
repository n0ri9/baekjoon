#include <stdio.h>

int		main(void)
{
	int		arr[100] = {0, };
	int		s1;
	int		s2;
	int		s3;
	int		i;
	int		j;
	int		k;
	int		max;
	int		get_index;

	scanf("%d %d %d", &s1, &s2, &s3);
	i = 0;
	while (++i <= s1)
	{
		j = 0;
		while (++j <= s2)
		{
			k = 0;
			while (++k <= s3)
			{
				arr[i + j + k] += 1;
			}
		}
	}
	i = -1;
	max = 0;
	while (++i < 100)
	{
		if (max < arr[i])
		{
			max = arr[i];
			get_index = i;
		}
	}
	printf("%d\n", get_index);
}
