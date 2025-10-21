/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:09:50 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 23:12:21 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, t_ft_printf *data)
{
	if (write(1, &c, 1) == -1)
		data->error = 1;
	else
		data->len++;
}

void	ft_putstr_len(char *str, t_ft_printf *data)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar_len(str[i], data);
		if (data->error)
			return ;
		i++;
	}
}

void	ft_putnbr_base(long n, char *base, t_ft_printf *data)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return ;
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base, data);
	ft_putchar_len(base[n % base_len], data);
}

void	ft_putnbr_base_unsigned(unsigned long n, char *base, t_ft_printf *data)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_base_unsigned(n / base_len, base, data);
	ft_putchar_len(base[n % base_len], data);
}
