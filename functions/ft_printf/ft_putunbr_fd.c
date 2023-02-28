/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:42:01 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/15 22:28:53 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_putunbr2_fd(unsigned long n, int fd, int *error)
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
		ft_putunbr2_fd(nn / 10, fd, error);
	ft_putchar_fd((nn % 10) + '0', fd, error);
}

int	ft_putunbr_fd(unsigned long n, int fd, int *error)
{
	unsigned long	cpy;
	int				length;

	cpy = n;
	length = 0;
	if (cpy == 0)
		length++;
	while (cpy)
	{
		cpy /= 10;
		length++;
	}
	ft_putunbr2_fd(n, fd, error);
	return (length);
}
