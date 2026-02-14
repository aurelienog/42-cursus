/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_normalization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:13:09 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/14 16:31:34 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
char	*copy_to_array(t_numbers_list **numbers, int size)
{
	char	*copy;
	int	i;

	copy = malloc(size * sizeof(int));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = ft_atoi(numbers[i]);
		i++;
	}
	return (copy);
}
*/

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubblesort(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if (numbers[i] > numbers[j])
				swap(&numbers[i], &numbers[j]);
			j++;
		}
		i++;
	}
}

void	partition(int *numbers, int low, int high, int size)
{
}

void	quicksort(int *numbers, int low, int high, int size)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quickSort(arr, low, pivot_index - 1);
		quickSort(arr, pivot_index + 1, high);
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	i;
	int	numbers[] = {5, 4 , 3, 1, 2, 0};

	i = 0;
	bubblesort(numbers, 6);
	while(i < 6)
	{
		printf("%d", numbers[i]);
		i++;
	}
}*/
