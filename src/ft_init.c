/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:57:08 by glancell          #+#    #+#             */
/*   Updated: 2025/09/28 23:51:50 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->specifier = 0;
}

static void	process_specifier(t_ft_printf *data)
{
	if (data->flags.specifier)
	{
		if (data->flags.specifier == 'c')
			print_char(data);
		else if (data->flags.specifier == 's')
			print_string(data);
		else if (data->flags.specifier == 'p')
			print_pointer(data);
		else if (data->flags.specifier == 'd' || data->flags.specifier == 'i')
			print_int(data);
		else if (data->flags.specifier == 'u')
			print_unsigned(data);
		else if (data->flags.specifier == 'x')
			print_hex(data, 0);
		else if (data->flags.specifier == 'X')
			print_hex(data, 1);
		else if (data->flags.specifier == '%')
			ft_putchar_len('%', data);
	}
}

static void	parse_format(const char *format, t_ft_printf *data)
{
	int	i;

	i = 0;
	while (format[i] && !data->error)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			init_flags(&data->flags);
			parse_flags(format, data, &i);
			parse_width(format, data, &i);
			parse_precision(format, data, &i);
			parse_specifier(format, data, &i);
			process_specifier(data);
		}
		else
		{
			ft_putchar_len(format[i], data);
			i++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	t_ft_printf	data;

	if (!format)
		return (-1);
	data.len = 0;
	data.error = 0;
	init_flags(&data.flags);
	va_start(data.args, format);
	parse_format(format, &data);
	va_end(data.args);
	if (data.error)
		return (-1);
	return (data.len);
}
