/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:51:19 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 23:15:32 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_pointer_length(unsigned long ptr_val)
{
	int	len;

	len = 2;
	if (ptr_val == 0)
		return (3);
	while (ptr_val > 0)
	{
		len++;
		ptr_val /= 16;
	}
	return (len);
}

static int	print_pointer_hex(unsigned long n, t_ft_printf *data)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += print_pointer_hex(n / 16, data);
	ft_putchar_len(base[n % 16], data);
	return (len + 1);
}

void	print_pointer(t_ft_printf *data)
{
	void			*ptr;
	int				len;
	unsigned long	ptr_val;

	ptr = va_arg(data->args, void *);
	if (!ptr)
	{
		len = 5;
		if (!data->flags.minus)
			apply_width(data, len, 0);
		ft_putstr_len("(nil)", data);
		if (data->flags.minus)
			apply_width(data, len, 0);
		return ;
	}
	ptr_val = (unsigned long)ptr;
	len = calc_pointer_length(ptr_val);
	if (!data->flags.minus)
		apply_width(data, len, 0);
	ft_putstr_len("0x", data);
	print_pointer_hex(ptr_val, data);
	if (data->flags.minus)
		apply_width(data, len, 0);
}
