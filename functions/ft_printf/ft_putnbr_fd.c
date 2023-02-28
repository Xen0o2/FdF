/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:06:52 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/15 22:28:05 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_putnbr2_fd(long n, int fd, int *error)
{
	unsigned long	nn;

	if (n < 0)
	{
		nn = -n;
		ft_putchar_fd('-', fd, error);
	}	
	else
		nn = n;
	if (nn > 9)
		ft_putnbr2_fd(nn / 10, fd, error);
	ft_putchar_fd((nn % 10) + '0', fd, error);
}

int	ft_putnbr_fd(long n, int fd, int *error)
{
	long	cpy;
	int		length;

	cpy = n;
	length = n <= 0;
	while (cpy)
	{
		cpy /= 10;
		length++;
	}
	ft_putnbr2_fd(n, fd, error);
	return (length);
}
