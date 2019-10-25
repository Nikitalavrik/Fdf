/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:48 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/25 17:36:32 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_coords	**rerange_coords(t_fdf *fdf, t_coords **coords, t_coords sizes)
{
	int	y;
	int	x;
	int	padding_x;
	int	padding_y;

	y = 0;
	padding_x = (WIDTH - fdf->width * fdf->zoom) / 2;
	padding_y = (HEIGHT - fdf->height * fdf->zoom) / 2;
	while (y < sizes.y)
	{
		x = 0;
		while (x < sizes.x)
		{
			coords[y][x].x = x * fdf->zoom + padding_x;
			coords[y][x].y = y * fdf->zoom + padding_y;
			coords[y][x].z = coords[y][x].prev_z * fdf->zoom;
			x++;
		}
		y++;
	}
	return (coords);
}

t_fdf	*setup_fdf(t_coords sizes, t_coords **coords)
{
	t_fdf *fdf;

	fdf = ft_memalloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = (int *)mlx_get_data_addr(fdf->image, &fdf->bits_per_pixel,
											&fdf->size_line, &fdf->endian);
	fdf->size = sizes;
	fdf->height = sizes.y;
	fdf->width = sizes.x;
	fdf->center.y = HEIGHT / 2;
	fdf->center.x = WIDTH / 2;
	fdf->up_down = 0.0f;
	fdf->left_right = 0.0f;
	fdf->coords = coords;
	fdf->zoom = (HEIGHT - 100) / sizes.y;
	fdf->padding_x = (WIDTH - fdf->width * fdf->zoom) / 2;
	fdf->padding_y = (HEIGHT - fdf->height * fdf->zoom) / 2;
	return (fdf);
}
