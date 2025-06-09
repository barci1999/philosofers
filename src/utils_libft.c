/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:39:45 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/09 21:45:32 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

enum_type	ft_str_isdigit(char *str)
{
	if (str[0] == '-')
		str++;
	while (*str)
	{
		if (!(*str >= 0 && *str <= 9))
			return (KO);
		str++;
	}
	return (OK);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static long	handle_overflow(long res, int sign, char next_digit)
{
	if (res > LONG_MAX / 10 || (res == LONG_MAX / 10 && next_digit > '7'))
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	res;
	long	overflow_check;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflow_check = handle_overflow(res, sign, str[i]);
		if (overflow_check)
			return (overflow_check);
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*array;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	array = (char *) malloc(count * size);
	if (array == NULL)
		return (NULL);
	memset(array, 0, (count * size));
	return (array);
}