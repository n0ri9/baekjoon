#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_str
{
	char	str[51];
	int		len;
} t_str;

t_str sort[20000];

void		print_result(t_str *arr, int n)
{
	int		i;

}

void		get_data(t_str *arr, int n)
{
	int		i;
	int		j;
	char	temp[51];
	int		len;

	i = -1;
	while (++i < n)
	{
		scanf("%s", temp);
		arr[i].len = strlen(temp);
		strcpy(arr[i].str, temp);
	}
}

void merge(t_str* arr, int first, int mid, int last) {
    int i;
    int j;
    int k;

	i = first;
	j = mid + 1;
	k = first;
    while(i <= mid && j <= last)
	{
        if (arr[i].len < arr[j].len)
            sort[k++] = arr[i++];
        else if (arr[i].len > arr[j].len )
            sort[k++] = arr[j++];
        else
		{
            if (strcmp(arr[i].str, arr[j].str) < 0)
                sort[k++] = arr[i++];
            else
                sort[k++] = arr[j++];
        }
    }
    if (i > mid)
        while (j <= last)
            sort[k++] = arr[j++];
    else
        while (i <= mid)
            sort[k++] = arr[i++];
	k = first -1;
	while (++k <= last)
        arr[k] = sort[k];
}

void		merge_sort(t_str* arr, int first, int last)
{
    int		mid;

    if (first < last) {
        mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int		main(void)
{
	t_str	*arr;
	int		n;

	scanf("%d", &n);
	arr = (t_str *)malloc(sizeof(t_str) * (n + 1));
	get_data(arr, n);
	merge_sort(arr, 0, n - 1);
	printf("%s\n", arr[0].str);
	for (int i = 1; i < n; i++)
	{
			if (strcmp(arr[i-1].str, arr[i].str) != 0)
				printf("%s\n", arr[i].str);
	}
}
