/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:18:18 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/17 20:20:25 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERR_MAP "Incorrect Map !"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_split
{
	char	**tab;
	int		i;
	int		j;
	int		sep;
	int		length;
}	t_split;

typedef struct s_fdf
{
	int	height;
	int	width;
	int	fd;
}	t_fdf;

typedef struct s_join
{
	char	*result;
	int		i;
	int		x;
}	t_join;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_printf(const char *placeholder, ...);
int		ft_putchar_fd(char c, int fd, int *error);
int		ft_putstr_fd(char *s, int fd, int *error);
int		ft_putnbr_fd(long n, int fd, int *error);
int		ft_putunbr_fd(unsigned long n, int fd, int *error);
int		ft_toupper(int c);
int		ft_strlen(char *s);
int     ft_atoi(const char *s);
char	**ft_split(char const *s, char c);

#endif
