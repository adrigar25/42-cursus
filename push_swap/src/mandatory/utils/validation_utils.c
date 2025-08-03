/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:14:25 by agarcia           #+#    #+#             */
/*   Updated: 2025/07/31 16:05:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_number(const char *str)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i] == '-');
		i++;
	}
	if (!str[i])
		return (0);
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	return (num >= -2147483648 && num <= 2147483647);
}

int	valid_numbers(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	if (!numbers || !*numbers)
		return (0);
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			return (0);
		j = 0;
		while (j < i)
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
