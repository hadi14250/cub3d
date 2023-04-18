/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:24:00 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 08:09:34 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	return_double_len(char **split)
{
	int	i;
	int	d;

	d = 0;
	i = 0;
	if (!split || !split[0])
		return (0);
	while (split[i] != NULL)
	{
		d += (ft_strlen(split[i]));
		i++;
	}
	return (d - i);
}

char	*ft_maptrim(char const *s1, char const *set)
{
	int		i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen((char *)s1);
	while (*s1 && ft_strrchr(set, s1[i]))
		i--;
	res = ft_substr(s1, 0, i + 1);
	return (res);
}

void	trim_comma(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0' && str[i] != '\n')
	{
		if (str[i] == ',')
			str[i] = ' ';
	}
}

int	check_next_line(t_cub *cub, char *str, int len)
{
	int	num[2];

	num[1] = 0;
	while (len >= 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	num[0] = len;
	if (len >= 0 && str[len] == '\n')
	{
		while (len >= 0 && (str[len] == ' ' || str[len] == '\t'
				|| str[len] == '\n' || str[len] == '\r' || str[len] == '\f'
				|| str[len] == '\v'))
				len--;
		if (len >= 0 && (str[len] == '1' || str[len] == '0'
				|| str[len] == ' ' || str[len] == 'E' || str[len] == 'S'
				|| str[len] == 'W' || str[len] == 'N'))
		{
			num[1] = 1;
			while (len >= 0 && str[len] != '\n')
				if (str[len--] == 'F' || str[len] == 'C')
					num[1] = 0;
			if (num[1] != 0)
				exit_cub(cub, 1, "Error\nconesecutive new lines in map\n");
		}
	}
	return (num[0]);
}

void	check_for_lines(t_cub *cub)
{
	char	*str;
	int		len;

	len = ft_strlen(cub->map_1d) - 1;
	str = cub->map_1d;
	while (len >= 0 && (str[len] == ' ' || str[len] == '\t'
			|| str[len] == '\n' || str[len] == '\r'
			|| str[len] == '\f' || str[len] == '\v'))
			len--;
	while (len >= 0 && (str[len] == '1' || str[len] == '0'
			|| str[len] == ' ' || str[len] == 'E' || str[len] == 'S'
			|| str[len] == 'W' || str[len] == 'N' || str[len] == '\n'
			|| str[len] == '\t'))
	{
		if (str[len] == '\n')
			len = check_next_line(cub, str, len - 1);
		len--;
	}
}
