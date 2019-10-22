/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:48 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/22 20:13:33 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_fdf	*setup_fdf(t_coords sizes)
{
	t_fdf *fdf;

	fdf = ft_memalloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = (int *)mlx_get_data_addr(fdf->image, &fdf->bits_per_pixel,
											&fdf->size_line, &fdf->endian);
	fdf->height = sizes.y;
	fdf->width = sizes.x;
	return (fdf);
}