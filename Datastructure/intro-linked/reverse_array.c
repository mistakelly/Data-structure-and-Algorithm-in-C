#include <stdio.h>

/*define function to reverse an array*/

void	reverse_array(int *arr, int size)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
    end = size - 1;

	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int	main(void)
{
	int array[] = {1, 2, 3, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);

	reverse_array(array, size);

	for (int i = 0; i < size; i++)
	{
		/* code */
		printf("%d\n", array[i]);
	}
}