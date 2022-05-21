#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char		**str_malloc(int mem_size)
{
	char	**new_str;
	int		i;

	new_str = (char **)malloc(sizeof(char *) * (mem_size + 1));
	i = -1;
	while (++i < mem_size)
		new_str[i] = (char *)malloc(sizeof(char) * 51);
	return new_str;
}

int			get_mem_size(int len)
{
	int		mem_size;
	int		i;
	int		j;

	i = 0;
	mem_size = 0;
	while (++i < len)
	{
		j = i;
		while (++j < len)
			mem_size++;
	}
	return mem_size;
}
char		*str_rev(char *str)
{
	int		half_len;
	int		len;
	int		i;
	char	c;
	
	len = strlen(str);
	half_len = len / 2;
	i = -1;
	while (++i < half_len)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return str;
}

int compare(const void *a, const void *b)
{
	char	**str1;
	char	**str2;

	str1 = (char **)a;
	str2 = (char **)b;
	return strcmp(*str1, *str2);
}

int		main(void)
{
	char 	*str;
	char	*temp;
	char	*copy;
	char	**new_str;
	int		len;
	int		mem_size;
	int		first_pivot;
	int		second_pivot;
	int		k;

	str = (char *)malloc(sizeof(char) * 51);
	temp = (char *)malloc(sizeof(char) * 51);
	copy = (char *)malloc(sizeof(char) * 51);
	scanf("%s", str);
	len = strlen(str);
	mem_size = get_mem_size(len);
	new_str = str_malloc(mem_size);
	first_pivot = 0;
	k = 0;
	while (++first_pivot < len)
	{
		second_pivot = first_pivot;
		while (++second_pivot < len)
		{
			memset(copy, 0, 51);
			memset(temp, 0, 51);

			strncpy(temp, str, first_pivot);
			temp = str_rev(temp);
			strncpy(copy, temp, first_pivot);

			memset(temp, 0, 51);

			strncpy(temp, str + first_pivot, second_pivot - first_pivot);
			temp = str_rev(temp);
			strncpy(copy + first_pivot, temp, second_pivot - first_pivot);

			memset(temp, 0, 51);

			strncpy(temp, str + second_pivot, len - second_pivot);
			temp = str_rev(temp);
			strncpy(copy + second_pivot, temp, len - second_pivot);
			strcpy(new_str[k], copy);
			k++;
		}
	}
	qsort(new_str, mem_size, sizeof(new_str[0]), compare);
	printf("%s\n", new_str[0]);
}
