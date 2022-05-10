#include <stdio.h>

int		main(void)
{
	int		i;
	int		j;
	int		n;
	char	arr[51];
	char	new_arr[51] = {0, };


	scanf("%d", &n);
	i = -1;
	while (++i < n)
	{
		scanf("%s", arr);
		j = -1;
		while (arr[++j])
		{
			if (!i)
				new_arr[j] = arr[j];
			if (new_arr[j] != arr[j])
				new_arr[j] = '?';
		}
		new_arr[j] = '\0';
	}
	printf("%s\n", new_arr);
}
