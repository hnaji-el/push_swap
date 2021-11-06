/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaji-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 02:14:17 by hnaji-el          #+#    #+#             */
/*   Updated: 2021/11/06 20:37:08 by hnaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	eof_neof(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_len(char *str, int len)
{
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

int	read_join(char **str, int fd, int r)
{
	char	*buffer;
	char	*fr;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	if (!eof_neof(*str))
	{
		while (r > 0)
		{
			r = read(fd, buffer, BUFFER_SIZE);
			if (r == -1)
				return (-1);
			buffer[r] = '\0';
			fr = *str;
			*str = ft_strjoin(*str, buffer);
			if (*str == NULL)
				return (-1);
			ft_free_1d((void **)&fr);
			if (eof_neof(*str))
				break ;
		}
	}
	ft_free_1d((void **)&buffer);
	return (r);
}

int	filling_line(char **line, char **str, int r, int len)
{
	char		*fr;

	*line = ft_substr(*str, 0, len);
	if (*line == NULL)
		return (-1);
	fr = *str;
	if (r == 0)
	{
		*str = NULL;
		ft_free_1d((void **)&fr);
		return (0);
	}
	*str = ft_strdup(*str + len + 1);
	if (*str == NULL)
		return (-1);
	ft_free_1d((void **)&fr);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			r;
	int			len;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (str == NULL)
	{
		str = ft_strdup("");
		if (str == NULL)
			return (-1);
	}
	r = read_join(&str, fd, 1);
	if (r == -1)
		return (-1);
	len = ft_len(str, 0);
	return (filling_line(line, &str, r, len));
}
