/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:40:37 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/21 16:12:37 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

char	*ft_read(int fd, char *all)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readed;

	readed = 1;
	while (readed != 0 && !ft_strchr(all, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(all);
			return (0);
		}
		buffer[readed] = 0;
		all = ft_strjoin(all, buffer);
	}
	return (all);
}

char	*get_one_line(char *all)
{
	char	*line;
	int		i;

	if (!all[0])
		return (0);
	line = malloc((ft_strlen(all) + 2) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (all[i] && all[i] != '\n')
	{
		line[i] = all[i];
		i++;
	}
	if (all[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*get_rest(char *all)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (all[i] && all[i] != '\n')
		i++;
	if (!all[i])
	{
		free(all);
		return (0);
	}
	result = malloc((ft_strlen(all) - i++ + 1) * sizeof(char));
	if (!result)
		return (0);
	while (all[i])
		result[j++] = all[i++];
	result[j] = 0;
	free(all);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*all[2048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all[fd] = ft_read(fd, all[fd]);
	if (!all[fd])
		return (0);
	line = get_one_line(all[fd]);
	all[fd] = get_rest(all[fd]);
	return (line);
}
