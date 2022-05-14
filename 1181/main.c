#include <stdio.h>
#include <string.h>

void	swap(char *left, char *right)
{
	char	temp[51] = {0, };

	strcpy(temp, right);
	strcpy(right, left);
	strcpy(left, temp);
}

int		get_data(char arr[20000][51])
{
	int		i;
	int		n;

	i = -1;
	scanf("%d", &n);
	while (++i < n)
		scanf("%s", arr[i]);
	return n;
}

void	size_sort(char arr[20000][51], int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - i - 1)
			if (strlen(arr[j]) > strlen(arr[j + 1]))
				swap(arr[j], arr[j + 1]);
	}
}

void	print_result(char arr[20000][51], int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		if (i >= 1 && strcmp(arr[i], arr[i + 1]) != 0)
			printf("%s\n", arr[i]);
		else if (i == 0)
			printf("%s\n", arr[i]);
	}
}

void	cmp_sort(char arr[20000][51], int n)
{
	int		i;
	int		index;
	int		j;
	int		k;
	int		l;
	int		size;
	int		start;
	int		end;
	int		max_size;
	int		now_len;
	int		save_len;
	int		start_flag;
	int		end_flag;

	index = -1;
	start = 0;
	end = 0;
	save_len = -1;
	start_flag = 0;
	end_flag = 0;
	while (++index < n)
	{
		now_len = strlen(arr[index]);
		if (save_len == now_len && !start_flag)
		{
			start = index - 1;
			start_flag = 1;
		}
		else if (save_len != now_len && !end_flag && start_flag)
		{
			end = index - 1;
			end_flag = 1;
		}
		save_len = now_len;
		if (start_flag && end_flag)
		{
			i = start;
			k = i;
			j = end;
			l = 0;
			while (i < j)
			{
				k = start;
				while (k < j - l)
				{
					if (strcmp(arr[k], arr[k + 1]) > 0)
						swap(arr[k], arr[k + 1]);
					k++;
				}
				l++;
				i++;
			}
			start_flag = 0;
			end_flag = 0;
		}
	}
}

int		main(void)
{
	char	arr[20000][51] = {0, };
	int		n;

	n = get_data(arr);
	size_sort(arr, n);
	cmp_sort(arr, n);
	print_result(arr, n);
}
