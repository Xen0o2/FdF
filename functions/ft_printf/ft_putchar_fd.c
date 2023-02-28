/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:28:36 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/15 22:35:58 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_putchar_fd(char c, int fd, int *error)
{
	int	result;

	result = 0;
	if (*error != -1)
		result = write(fd, &c, 1);
	if (result == -1)
		*error = -1;
	return (result);
}
