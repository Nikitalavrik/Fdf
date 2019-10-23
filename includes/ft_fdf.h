/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:03:40 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/23 16:23:46 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "../libft/ft_printf/include/ft_printf.h"
# include "../minilibx_macos/mlx.h"
#	include <math.h>

# define HEIGHT 720
# define WIDTH	1280

typedef struct	s_coords
{
	int		x;
	int		y;
	int		z;
}				t_coords;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*image;
	int			*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			height;
	int			width;
	t_coords	center;
	t_coords	**coords;
	float		up_down;
	float		left_right;
}				t_fdf;

int				split_len(char **splited);
void			free_splited(char **splited, int size);
t_coords		**parse_file(t_coords *sizes, char *filename);

t_fdf			*setup_fdf(t_coords sizes, t_coords **coords);

void			change_view(t_fdf *fdf, t_coords **coords, int key);
t_coords		**rerange_coords(t_fdf *fdf, t_coords **coords, t_coords sizes);

int				catch_key(int key, t_fdf *fdf);

void			vis_map(t_fdf *fdf);

void			print_coords(t_coords **coords, int max_y, int max_x);
void			print_error(char *message);

#endif