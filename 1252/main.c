#include <stdio.h>
#include <string.h>

int		get_min(char *str)
{
	int i = 0;
	while (str[i] && str[i] == '0')
	{
		i++;
	}
	return i - 1;
}

int		main(void)
{
	char 	left_num[81] = {0, };
	char 	right_num[81] = {0, };
	int		left_min;
	int		right_min;
	int 	left_len;
	int 	right_len;
	int		round_up;
	int		insert_num;
	char	new_num[162] = {0, };
	int		i;
	int		new_len;

	scanf("%s", left_num);
	scanf("%s", right_num);
	left_len = strlen(left_num);
	right_len = strlen(right_num);
	left_min = get_min(left_num);
	right_min = get_min(right_num);
	round_up = 0;
	i = 0;
	left_len--;
	right_len--;
	while (left_len != left_min || right_len != right_min)
	{
		insert_num = 0;
		if (round_up)
			insert_num += 1;
		round_up = 0;
		if (left_len != left_min && right_len != right_min)
			insert_num = insert_num + (right_num[right_len] - '0') + (left_num[left_len] - '0');
		else if (left_len != left_min)
			insert_num = insert_num + (left_num[left_len] - '0');
		else if (right_len != right_min)
			insert_num = insert_num + (right_num[right_len] - '0');
		if (insert_num == 2)
		{
			round_up = 1;
			insert_num = 0;
		}
		else if (insert_num == 3)
		{
			round_up = 1;
			insert_num = 1;
		}
		new_num[i] = insert_num + '0';
		if (left_len != left_min)
			left_len--;
		if (right_len != right_min)
			right_len--;
		i++;
	}
	new_len = strlen(new_num);
	if (new_len == 0 && round_up == 0)
		printf("%c", '0');
	if (round_up)
		printf("%c", '1');
	while (--new_len != -1)
		printf("%c", new_num[new_len]);
}
