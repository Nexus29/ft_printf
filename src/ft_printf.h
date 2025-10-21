/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:19:09 by glancell          #+#    #+#             */
/*   Updated: 2025/09/29 18:27:11 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		minus;		// ('-')
	int		zero;		// ('0')
	int		dot;		// ('.')
	int		hash;		// ('#')
	int		space;		// (' ')
	int		plus;		// ('+')
	int		width;		// max width
	int		precision;	// (-1 if not set)
	char	specifier;	// (c, s, p, d, i, u)
}	t_flags;

typedef struct s_ft_printf
{
	va_list	args;
	int		len;
	int		error;
	t_flags	flags;
}	t_ft_printf;

int		ft_printf(const char *format, ...);

// Parsing
void	parse_flags(const char *format, t_ft_printf *data, int *i);
void	parse_width(const char *format, t_ft_printf *data, int *i);
void	parse_precision(const char *format, t_ft_printf *data, int *i);
void	parse_specifier(const char *format, t_ft_printf *data, int *i);

// Printer
void	print_char(t_ft_printf *data);
void	print_string(t_ft_printf *data);
void	print_pointer(t_ft_printf *data);
void	print_int(t_ft_printf *data);
void	print_unsigned(t_ft_printf *data);
void	print_hex(t_ft_printf *data, int uppercase);
void	print_sign(t_ft_printf *data, int is_negative);

// Bonus formatting functions
void	apply_width(t_ft_printf *data, int len, int zero_pad);
void	apply_precision_str(t_ft_printf *data, char *str);
void	apply_precision_num(t_ft_printf *data, long num, int base);
int		calc_num_length(long num, int base, t_ft_printf *data);

// Utilities
void	ft_putchar_len(char c, t_ft_printf *data);
void	ft_putstr_len(char *str, t_ft_printf *data);
void	ft_putnbr_base(long n, char *base, t_ft_printf *data);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putchar_len(char c, t_ft_printf *data);
void	ft_putnbr_base_unsigned(unsigned long n, char *base, t_ft_printf *data);

#endif
