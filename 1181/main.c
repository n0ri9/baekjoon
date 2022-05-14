#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		swap(char *left, char *right)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * 51);

	strcpy(temp, right);
	strcpy(right, left);
	strcpy(left, temp);
	free(temp);
}

int			get_data(char **arr)
{
	int		i;
	int		n;

	i = -1;
	scanf("%d", &n);
	while (++i < n)
		scanf("%s", arr[i]);
	return n;
}

void		print_result(char **arr, int n)
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

void		cmp_sort(char **arr, int n)
{
	int		i;
	int		index;
	int		j;
	int		k;
	int		l;
	int		start;
	int		end;
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

void		merges(char **arr, char **result, int left, int right) {
	int		mid;
	int		i;
	int		j;
	int		k;
	int		l;

	mid = (left + right) / 2;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (strlen(arr[i]) > strlen(arr[j]))
			strcpy(result[k++], arr[j++]);
		else
			strcpy(result[k++], arr[i++]);
	}
	if (i > mid)
		while (j <= right)
			strcpy(result[k++], arr[j++]);
	else
		while (i <= mid)
			strcpy(result[k++], arr[i++]);
	l = left - 1;
	while (++l <= right)
		strcpy(arr[l], result[l]);
}

void		partition(char **arr, char **result, int left, int right) {
	int		mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		partition(arr, result, left, mid);
		partition(arr, result, mid + 1, right);
		merges(arr, result, left, right);
	}
}

int		main(void)
{
	char	**arr;
	char	**result;
	int		i;
	int		n;

	arr = (char **)malloc(sizeof(char *) * 20000);
	i = -1;
	while (++i < 20000)
		arr[i] = (char *)malloc(sizeof(char) * 51);

	result= (char **)malloc(sizeof(char *) * 20000);
	i = -1;
	while (++i < 20000)
		result[i] = (char *)malloc(sizeof(char) * 51);
	n = get_data(arr);
	partition(arr, result, 0, n - 1);
	cmp_sort(arr, n);
	print_result(arr, n);
}
