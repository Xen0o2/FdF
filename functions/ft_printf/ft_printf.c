/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:14:51 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/15 22:35:43 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	puthex2(unsigned long value, int maj, int first, int *error)
{
	char	*base;

	base = "0123456789abcdef";
	if (first)
		ft_putstr_fd("0x", 1, error);
	if (value > 15)
		puthex2(value / 16, maj, 0, error);
	if (maj)
		ft_putchar_fd(ft_toupper(base[value % 16]), 1, error);
	else
		ft_putchar_fd(base[value % 16], 1, error);
}

int	puthex(unsigned long value, int maj, int first, int *error)
{
	int				length;
	unsigned long	cpy;

	length = 2 * first + 1;
	cpy = value;
	while (value > 15)
	{
		value /= 16;
		length++;
	}
	puthex2(cpy, maj, first, error);
	return (length);
}

int	ft_format(char c, va_list args, int *error)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar_fd(va_arg(args, int), 1, error);
	if (c == 's')
		length += ft_putstr_fd(va_arg(args, char *), 1, error);
	if (c == 'p')
		length += puthex(((unsigned long) va_arg(args, void *)), 0, 1, error);
	if (c == 'd' || c == 'i')
		length += ft_putnbr_fd(va_arg(args, int), 1, error);
	if (c == 'u')
		length += ft_putunbr_fd(va_arg(args, unsigned int), 1, error);
	if (c == 'x' || c == 'X')
		length += puthex(va_arg(args, unsigned int), c == 'X', 0, error);
	if (c == '%')
		length += ft_putchar_fd('%', 1, error);
	return (length);
}

int	ft_printf(const char *placeholder, ...)
{
	va_list	args;
	int		length;
	int		error;

	if (!placeholder)
		return (-1);
	va_start(args, placeholder);
	length = 0;
	error = 0;
	while (*placeholder)
	{
		if (*placeholder == '%')
		{
			if (*(placeholder + 1))
				length += ft_format(*++placeholder, args, &error);
		}
		else
			length += ft_putchar_fd(*placeholder, 1, &error);
		placeholder++;
	}
	va_end(args);
	if (error == -1)
		return (-1);
	else
		return (length);
}
