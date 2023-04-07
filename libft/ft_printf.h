/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:13:07 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/10 21:52:52 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_put_hex(unsigned int nb, char c);
int		ft_putnbr_u(unsigned int nb);
int		ft_put_address(unsigned long long nb);
int		ft_parse(va_list ptr, char c);
int		ft_printf(const char *str, ...);
char	*ft_capitalise(char *str);

#endif