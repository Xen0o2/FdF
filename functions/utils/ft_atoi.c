/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:49:33 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/06 20:30:16 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_atoi(const char *s)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*s == ' ' || *s == '\r' || *s == '\t')
		|| (*s == '\n' || *s == '\v' || *s == '\f'))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}