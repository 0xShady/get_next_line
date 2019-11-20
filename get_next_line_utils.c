/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:15:21 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/02 00:33:19 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	char	*tab;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (!(tab = (char *)malloc((i + j) * sizeof(char) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
	{
		tab[i] = s2[j];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	if (!(result = malloc(size * count)))
		return (0);
	while (i < count * size)
	{
		result[i++] = 0;
	}
	return (result);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	s = (char *)malloc((i + 1) * sizeof(char));
	if (s == 0)
		return (0);
	while (s1[j] != '\0')
	{
		s[j] = s1[j];
		j++;
	}
	s[i] = '\0';
	return (s);
}
