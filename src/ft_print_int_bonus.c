/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:52:31 by glancell          #+#    #+#             */
/*   Updated: 2025/10/16 09:41:43 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_int_number(t_ft_printf *data, int num, int *params)
{
	long	abs_num;

	abs_num = num;
	if (params[0])
		abs_num = -(long)num;
	if (!data->flags.minus && (!data->flags.zero || data->flags.dot))
	{
		if (data->flags.width > params[3])
			apply_width(data, params[3], 0);
	}
	print_sign(data, params[0]);
	while (params[2]-- > 0)
		ft_putchar_len('0', data);
	if (!data->flags.minus && data->flags.zero && !data->flags.dot)
	{
		if (data->flags.width > params[3])
			apply_width(data, params[3], 1);
	}
	ft_putnbr_base_unsigned(abs_num, "0123456789", data);
	if (data->flags.minus && data->flags.width > params[3])
		apply_width(data, params[3], 0);
}

static void	calculate_int_params(int num, t_ft_printf *data, int *params)
{
	long	abs_num;

	if (num < 0)
		params[0] = 1;
	else
		params[0] = 0;
	abs_num = num;
	if (params[0])
		abs_num = -(long)num;
	params[1] = calc_num_length(abs_num, 10, data);
	if (num == 0)
		params[1] = 1;
	params[2] = 0;
	if (data->flags.dot && data->flags.precision > params[1])
		params[2] = data->flags.precision - params[1];
	params[3] = params[1] + params[2];
	if (params[0] || data->flags.plus || data->flags.space)
		params[3]++;
}

static void	print_int_min_padding(t_ft_printf *data,
	int precision_zeros, int total_len)
{
	if (!data->flags.minus && (!data->flags.zero || data->flags.dot))
	{
		if (data->flags.width > total_len)
			apply_width(data, total_len, 0);
	}
	ft_putchar_len('-', data);
	while (precision_zeros-- > 0)
		ft_putchar_len('0', data);
	if (!data->flags.minus && data->flags.zero && !data->flags.dot)
	{
		if (data->flags.width > total_len)
			apply_width(data, total_len, 1);
	}
}

static void	handle_int_min(t_ft_printf *data)
{
	int	precision_zeros;
	int	total_len;

	if (data->flags.dot && data->flags.precision == 0)
	{
		if (data->flags.width > 0)
			apply_width(data, 0, 0);
		return ;
	}
	precision_zeros = 0;
	if (data->flags.dot && data->flags.precision > 10)
		precision_zeros = data->flags.precision - 10;
	total_len = 11 + precision_zeros;
	print_int_min_padding(data, precision_zeros, total_len);
	ft_putstr_len("2147483648", data);
	if (data->flags.minus && data->flags.width > total_len)
		apply_width(data, total_len, 0);
}

void	print_int(t_ft_printf *data)
{
	int	num;
	int	params[4];

	num = va_arg(data->args, int);
	if (num == -2147483648)
	{
		handle_int_min(data);
		return ;
	}
	if (num == 0 && data->flags.dot && data->flags.precision == 0)
	{
		if (data->flags.width > 0)
			apply_width(data, 0, 0);
		return ;
	}
	calculate_int_params(num, data, params);
	print_int_number(data, num, params);
}
