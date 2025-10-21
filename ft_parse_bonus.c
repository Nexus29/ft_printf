/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:55:20 by glancell          #+#    #+#             */
/*   Updated: 2025/09/28 23:30:02 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isflag(int c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}

void	parse_flags(const char *format, t_ft_printf *data, int *i)
{
	while (ft_isflag(format[*i]))
	{
		if (format[*i] == '-')
			data->flags.minus = 1;
		else if (format[*i] == '0')
			data->flags.zero = 1;
		else if (format[*i] == '#')
			data->flags.hash = 1;
		else if (format[*i] == ' ')
			data->flags.space = 1;
		else if (format[*i] == '+')
			data->flags.plus = 1;
		(*i)++;
	}
}

void	parse_width(const char *format, t_ft_printf *data, int *i)
{
	if (ft_isdigit(format[*i]))
	{
		data->flags.width = 0;
		while (ft_isdigit(format[*i]))
		{
			data->flags.width = data->flags.width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
}

void	parse_precision(const char *format, t_ft_printf *data, int *i)
{
	if (format[*i] == '.')
	{
		data->flags.dot = 1;
		data->flags.precision = 0;
		(*i)++;
		if (ft_isdigit(format[*i]))
		{
			data->flags.precision = 0;
			while (ft_isdigit(format[*i]))
			{
				data->flags.precision = data->flags.precision * 10
					+ (format[*i] - '0');
				(*i)++;
			}
		}
	}
}

void	parse_specifier(const char *format, t_ft_printf *data, int *i)
{
	char	*specifiers;
	int		j;

	j = 0;
	specifiers = "cspdiuxX%";
	while (specifiers[j])
	{
		if (format[*i] == specifiers[j])
		{
			data->flags.specifier = format[*i];
			(*i)++;
			return ;
		}
		j++;
	}
}
