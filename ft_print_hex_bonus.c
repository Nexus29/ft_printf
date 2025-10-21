/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:58:22 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 21:11:58 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	calculate_hex_lengths(t_ft_printf *data, unsigned int num, int *l)
{
	l[0] = 1;
	if (num != 0)
		l[0] = calc_num_length(num, 16, data);
	l[1] = 0;
	if (data->flags.dot && data->flags.precision > l[0])
		l[1] = data->flags.precision - l[0];
	l[2] = 0;
	if (data->flags.hash && num != 0)
		l[2] = 2;
	l[3] = l[2] + l[0] + l[1];
}

static void	print_hex_number(t_ft_printf *data, unsigned int num,
	char *base, char *prefix)
{
	int	l[4];

	calculate_hex_lengths(data, num, l);
	if (!data->flags.minus && (!data->flags.zero || data->flags.dot)
		&& data->flags.width > l[3])
		apply_width(data, l[3], 0);
	if (l[2] > 0 && (!data->flags.zero || data->flags.dot))
		ft_putstr_len(prefix, data);
	else if (!data->flags.minus && data->flags.zero && !data->flags.dot)
	{
		if (l[2] > 0)
			ft_putstr_len(prefix, data);
		if (data->flags.width > l[3])
			apply_width(data, l[3], 1);
	}
	else if (l[2] > 0)
		ft_putstr_len(prefix, data);
	while (l[1]-- > 0)
		ft_putchar_len('0', data);
	if (num == 0)
		ft_putchar_len('0', data);
	else
		ft_putnbr_base_unsigned(num, base, data);
	if (data->flags.minus && data->flags.width > l[3])
		apply_width(data, l[3], 0);
}

static int	handle_zero_precision_case(t_ft_printf *data, unsigned int num)
{
	int	len;

	if (!(num == 0 && data->flags.dot && data->flags.precision == 0))
		return (0);
	if (data->flags.hash)
	{
		len = 1;
		if (!data->flags.minus && data->flags.width > len)
			apply_width(data, len, 0);
		ft_putchar_len('0', data);
		if (data->flags.minus && data->flags.width > len)
			apply_width(data, len, 0);
	}
	else if (data->flags.width > 0)
		apply_width(data, 0, 0);
	return (1);
}

static void	setup_hex_base_prefix(char **base, char **prefix, int uppercase)
{
	if (uppercase)
	{
		*base = "0123456789ABCDEF";
		*prefix = "0X";
	}
	else
	{
		*base = "0123456789abcdef";
		*prefix = "0x";
	}
}

void	print_hex(t_ft_printf *data, int uppercase)
{
	unsigned int	num;
	char			*base;
	char			*prefix;

	setup_hex_base_prefix(&base, &prefix, uppercase);
	num = va_arg(data->args, unsigned int);
	if (handle_zero_precision_case(data, num))
		return ;
	print_hex_number(data, num, base, prefix);
}
