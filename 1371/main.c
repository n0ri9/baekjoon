#include <stdio.h>

int		main(void)
{
	int		arr[26] = {0, };
	char	*str;
	int		max;
	int		r;
	int		i;

	while ((r = getchar()) > 0)
	{
		if (r >= 'a' && r <= 'z')
			arr[r - 'a'] += 1;
	}
	i = -1;
	max = 0;
	while (++i < 26)
		if (max < arr[i])
			max = arr[i];
	i = -1;
	while (++i < 26)
		if (max == arr[i])
			printf("%c", i + 'a');
}
