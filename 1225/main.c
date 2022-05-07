#include <string.h>
#include <stdio.h>

int		main(void)
{
	long long	result;
	char		left_num[10001];
	char		right_num[10001];
	int			left_len;
	int			right_len;
	int			i;
	int			j;

	scanf("%s %s", left_num, right_num);
	if (left_num[0] == '0' || right_num[0] == '0')
	{
		printf("%d\n", 0);
		return 0;
	}
	left_len = strlen(left_num);
	right_len = strlen(right_num);
	result = 0;
	i = -1;
	while (++i < left_len)
	{
		j = -1;
		while (++j < right_len)
			result += ((left_num[i] - '0') * (right_num[j] - '0'));
	}
	printf("%lld\n", result);
}
