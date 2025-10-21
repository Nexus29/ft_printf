/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applier_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:20:52 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 18:27:11 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width(t_ft_printf *data, int content_len, int zero_pad)
{
	int		padding;
	char	padding_char;

	if (data->flags.width <= content_len)
		return ;
	padding = data->flags.width - content_len;
	padding_char = ' ';
	if (zero_pad && !data->flags.minus && !data->flags.dot)
		padding_char = '0';
	while (padding-- > 0)
		ft_putchar_len(padding_char, data);
}

void	apply_precision_str(t_ft_printf *data, char *str)
{
	int	max_len;
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	max_len = ft_strlen(str);
	if (data->flags.dot && data->flags.precision >= 0
		&& data->flags.precision < max_len)
		max_len = data->flags.precision;
	while (str[i] && i < max_len)
	{
		ft_putchar_len(str[i], data);
		i++;
	}
}

void	print_sign(t_ft_printf *data, int is_negative)
{
	if (is_negative)
		ft_putchar_len('-', data);
	else if (data->flags.plus)
		ft_putchar_len('+', data);
	else if (data->flags.space)
		ft_putchar_len(' ', data);
}

void	apply_precision_num(t_ft_printf *data, long num, int base)
{
	int	num_len;
	int	precision;
	int	zeros_needed;

	num_len = calc_num_length(num, base, data);
	precision = data->flags.precision;
	if (data->flags.dot && precision > num_len)
	{
		zeros_needed = precision - num_len;
		while (zeros_needed-- > 0)
			ft_putchar_len('0', data);
	}
}
