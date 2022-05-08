#include <stdio.h>
#include <time.h>

int		arr[45] = {1, 1};

int	fabo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (arr[n])
		return arr[n];
	else
	{
		arr[n] = fabo(n - 1) + fabo(n - 2);
		return arr[n];
	}
}

int		main(void)
{
	int		result;
	int		n;
	clock_t start, end;
	
	scanf("%d", &n);
	start = clock();
	result = fabo(n);
	end = clock();
	printf("%d\n", result);
	printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);
}	
