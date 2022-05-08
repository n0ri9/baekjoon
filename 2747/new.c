#include <stdio.h>
#include <time.h>

int	fabo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 3;
	else
		return fabo(n - 1) + fabo(n - 2);
}

int		main(void)
{
	clock_t start, end;
	int		result;
	int		n;
	
	scanf("%d", &n);
	start = clock();
	result = fabo(n);
	end = clock();
	printf("%d\n", result);
	printf("%f\n", (float)(end - start) / CLOCKS_PER_SEC);
}	
