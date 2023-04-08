/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:12:18 by hakaddou          #+#    #+#             */
/*   Updated: 2023/04/04 14:45:11 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef KEYS_H
# define KEYS_H

# define ESC 53
# define LEFT_AROW 123
# define RIGHT_AROW 124
# define DOWN_AROW 125
# define UP_AROW 126
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define ONE 18
# define TWO 19
# define THREE 20
# define LOOP 37
# define W_KEY 13
# define D_KEY 2
# define S_KEY 1
# define A_KEY 0
# define MESH 46
# define NMESH 45
# define REDO 666
# define Z_KEY 6
# define X_KEY 7

typedef struct s_keys
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	w;
	bool	s;
	bool	a;
	bool	d;
}			t_keys;


#endif