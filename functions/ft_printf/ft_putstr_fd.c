/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:00:51 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/15 22:27:33 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_putstr_fd(char *s, int fd, int *error)
{
	int	length;

	if (s)
	{
		length = ft_strlen(s);
		while (*s)
			ft_putchar_fd(*s++, fd, error);
		return (length);
	}
	else
	{
		*error = write(1, "(null)", 6);
		return (6);
	}
}
