#include <stdio.h>
#include <stdlib.h>

int		**arr_init(int n)
{
	int **arr;
	int	i;

	arr = (int **)malloc(sizeof(int *) * n);

	i = -1;
	while (++i < n)
		arr[i] = (int *)malloc(sizeof(int) * n);
	return (arr);
}

int		main(void)
{
	int n;
	int m;
	int	i;
	int	j;
	int	**arr;

	scanf("%d %d", &n, &m);
	arr = arr_init(n);
	printf("n : %d\n", n);
	printf("m : %d\n", m);

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			scanf("%d", &arr[i][j]);
	}
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			printf("%d ", arr[i][j]);
		putchar('\n');
	}
}
