/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:39:32 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/23 17:38:55 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"


int		catch_key(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (key == 123)
		fdf->left_right += 0.01;
	if (key == 124)
		fdf->left_right -= 0.01;
	if (key == 126)
		fdf->up_down += 0.01;
	if (key == 125)
		fdf->up_down -= 0.01;
	if (key == 69)
		fdf->zoom = 1.5;
	if (key == 78)
		fdf->zoom = 0.9;
	ft_printf("key = %i\n", key);
	ft_bzero(fdf->addr, WIDTH * HEIGHT * sizeof(int));
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 75, 75);
	if ((key >= 123 && key <= 126) || key == 78 || key == 69)
		change_view(fdf, fdf->coords, key);
	vis_map(fdf);
	// fdf->left_right = 0;
	return (0);
}