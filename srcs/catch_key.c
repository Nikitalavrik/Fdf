/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:39:32 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/27 16:20:30 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	turn_on_music(t_fdf *fdf, int key)
{
	if (!fdf->music_on && key != 53)
	{
		system("afplay music/Soundtrack.mp3 &");
		fdf->music_on = 1;
	}
	else if (fdf->music_on)
	{
		system("killall afplay");
		fdf->music_on = 0;
	}
}

void	exit_fdf(t_fdf *fdf, int key)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	turn_on_music(fdf, key);
	exit(0);
}

void	repeat(t_fdf *fdf)
{
	ft_bzero(fdf->addr, WIDTH * HEIGHT * sizeof(int));
	vis_map(fdf);
	string_toolbar(fdf);
}

void	set_canonic(t_fdf *fdf)
{
	fdf->zoom = (HEIGHT - 100) / fdf->height;
	fdf->left_right = 0;
	fdf->up_down = 0;
}

int		catch_key(int key, t_fdf *fdf)
{
	if (key == 53)
		exit_fdf(fdf, key);
	if (key == 123)
		fdf->left_right -= 0.17453292519943;
	if (key == 124)
		fdf->left_right += 0.17453292519943;
	if (key == 126)
		fdf->up_down -= 0.17453292519943;
	if (key == 125)
		fdf->up_down += 0.17453292519943;
	if (key == 69 && fdf->zoom <= 1000)
		fdf->zoom *= 1.1;
	if (key == 78 && fdf->zoom >= 1)
		fdf->zoom *= 0.9;
	if (key == 34)
	{
		fdf->left_right = -0.174533;
		fdf->up_down = -1.047198;
	}
	if (key == 8)
		set_canonic(fdf);
	if (key == 46)
		turn_on_music(fdf, key);
	repeat(fdf);
	return (0);
}
