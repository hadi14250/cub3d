/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:51:44 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/07 17:31:56 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gl_trim_stat(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = ft_calloc((gl_strlen(str) - i + 1), 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	i++;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*gl_trim_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	tmp = ft_calloc (i + 1, 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		tmp[i] = '\0';
	return (tmp);
}

char	*gl_get_line(char *str, int fd)
{
	char	*buf;
	char	*temp;
	int		count;

	count = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (0);
	while (!gl_strchr (str, '\n') && count != 0)
	{
		count = read (fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[count] = '\0';
		temp = gl_strjoin (str, buf);
		free(str);
		str = temp;
	}
	free (buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*next_line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	stat = gl_get_line (stat, fd);
	if (!stat)
		return (0);
	else if (!stat[0])
	{
		free(stat);
		return (0);
	}
	next_line = gl_trim_line (stat);
	stat = gl_trim_stat(stat);
	return (next_line);
}
