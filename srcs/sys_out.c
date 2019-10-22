/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:47:54 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/22 14:50:56 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	print_coords(t_coords **coords, int max_y, int max_x)
{
	int	x;
	int	y;


	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			ft_printf("x = %i y = %i z = %i\n",
				coords[y][x].x, coords[y][x].y, coords[y][x].z);
			x++;
		}
		y++;
	}
}
