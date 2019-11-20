/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:10:29 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/15 02:01:52 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1000
# include <stdlib.h>
# include <unistd.h>

int				get_next_line(const int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
void			help3(char *buff, char **line);
int				help2(char **save, char *buff, int fd, char **line);
char			*help(char *save, char **line);

#endif
