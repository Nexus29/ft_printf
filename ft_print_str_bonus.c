/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:48:22 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 23:18:51 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_ft_printf *data)
{
	char	c;
	int		len;

	len = 1;
	c = (char)va_arg(data->args, int);
	if (!data->flags.minus)
		apply_width(data, len, 0);
	ft_putchar_len(c, data);
	if (data->flags.minus)
		apply_width(data, len, 0);
}

static int	handle_null_string(t_ft_printf *data, char **str)
{
	int	print_len;

	print_len = 0;
	if (*str == NULL)
	{
		if (data->flags.dot && data->flags.precision == 0)
			print_len = 0;
		else if (data->flags.dot && data->flags.precision > 0
			&& data->flags.precision < 6)
			print_len = 0;
		else
		{
			*str = "(null)";
			print_len = 6;
			if (data->flags.dot && data->flags.precision >= 0
				&& data->flags.precision < print_len)
				print_len = data->flags.precision;
		}
	}
	return (print_len);
}

static int	handle_normal_string(t_ft_printf *data, char *str)
{
	int	print_len;

	print_len = ft_strlen(str);
	if (data->flags.dot && data->flags.precision >= 0
		&& data->flags.precision < print_len)
		print_len = data->flags.precision;
	return (print_len);
}

static void	print_string_content(t_ft_printf *data, char *str, int print_len)
{
	int	i;

	i = 0;
	if (data->flags.dot && data->flags.precision >= 0)
	{
		while (i < print_len && str[i])
		{
			ft_putchar_len(str[i], data);
			i++;
		}
	}
	else
		ft_putstr_len(str, data);
}

void	print_string(t_ft_printf *data)
{
	char	*str;
	int		print_len;

	str = va_arg(data->args, char *);
	print_len = handle_null_string(data, &str);
	if (str != NULL)
		print_len = handle_normal_string(data, str);
	if (!data->flags.minus)
		apply_width(data, print_len, 0);
	if (print_len > 0)
		print_string_content(data, str, print_len);
	if (data->flags.minus)
		apply_width(data, print_len, 0);
}
