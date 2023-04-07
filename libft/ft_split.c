/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 03:59:17 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/10 20:26:30 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;
	int	done;

	i = 0;
	cnt = 0;
	done = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && !done)
			done = 1;
		else if (s[i] != c && done)
		{
			++cnt;
			done = 0;
		}
		++i;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	int			words;
	char		**tmp;

	if (!s)
		return (NULL);
	i = 0;
	words = word_count(s, c);
	tmp = malloc(sizeof(char *) * (words + 1));
	if (!tmp)
		return (NULL);
	words = 0;
	while (s[i] && words < word_count(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		tmp[words++] = ft_substr(s + i, 0, j);
		i += j;
	}
	tmp[words] = 0;
	return (tmp);
}

// int main ()
// {
// 	char str[] = "hadi is trying printf";
// 	int i = 0;
// 	char **str2 = ft_split (str, ' ');
// 	while (i < word_count (str, ' '))
// 	{
// 		ft_printf ("%s\n", str2[i]);
// 		i++;
// 	}
// 	ft_printf ("Sandy is %d years old\n", 23);
// }