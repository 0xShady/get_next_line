/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:08:51 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/15 02:03:19 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*help(char *save, char **line)
{
	char *str;

	str = NULL;
	if (save)
	{
		if ((str = ft_strchr(save, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(save);
			++str;
			ft_strcpy(save, str);
		}
		else
		{
			*line = ft_strdup(save);
			save = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (str);
}

void			help3(char *buff, char **line)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, buff);
	free(tmp);
}

int				help2(char **save, char *buff, int fd, char **line)
{
	int			size_read;
	char		*str;

	str = help(*save, line);
	while (!str)
	{
		if ((size_read = read(fd, buff, BUFFER_SIZE)) == 0)
		{
			free(buff);
			free(*save);
			save = NULL;
			return (0);
		}
		*(buff + size_read) = '\0';
		if ((str = ft_strchr(buff, '\n')))
		{
			*str = '\0';
			*str++;
			free(*save);
			*save = ft_strdup(str);
		}
		help3(buff, line);
	}
	free(buff);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char *save;
	char		*buff;

	if ((read(fd, NULL, 0) != 0) || fd < 0)
		return (-1);
	if (BUFFER_SIZE >= 2147483647)
		return (-1);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	return (help2(&save, buff, fd, line));
}
