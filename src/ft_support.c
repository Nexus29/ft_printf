/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:53:14 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 18:27:11 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	calc_num_length(long num, int base, t_ft_printf *data)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		if (data->flags.dot && data->flags.precision == 0)
			return (0);
		else
			return (1);
	}
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		len++;
		num /= base;
	}
	return (len);
}
