/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:56:07 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 22:40:23 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_precision_zeros(t_ft_printf *data, int num_len)
{
	if (data->flags.dot && data->flags.precision > num_len)
		return (data->flags.precision - num_len);
	return (0);
}

static void	apply_zero_padding(t_ft_printf *data, int total_len)
{
	if (data->flags.zero && !data->flags.minus && !data->flags.dot)
	{
		while (data->flags.width-- > total_len)
			ft_putchar_len('0', data);
	}
}

void	print_unsigned(t_ft_printf *data)
{
	unsigned int	num;
	int				num_len;
	int				precision_zeros;
	int				total_len;

	num = va_arg(data->args, unsigned int);
	if (num == 0 && data->flags.dot && data->flags.precision == 0)
		num_len = 0;
	else
		num_len = calc_num_length(num, 10, data);
	precision_zeros = calculate_precision_zeros(data, num_len);
	total_len = num_len + precision_zeros;
	if (!data->flags.minus && (!data->flags.zero || data->flags.dot))
		apply_width(data, total_len, 0);
	apply_zero_padding(data, total_len);
	if (data->flags.dot)
	{
		while (precision_zeros-- > 0)
			ft_putchar_len('0', data);
	}
	if (!(num == 0 && data->flags.dot && data->flags.precision == 0))
		ft_putnbr_base(num, "0123456789", data);
	if (data->flags.minus)
		apply_width(data, total_len, 0);
}
