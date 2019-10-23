/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:46 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/23 17:37:04 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_coords	**coords;
	t_coords	sizes;

	if (argc != 2)
		print_error("Woops, where file ?\n");

	coords = parse_file(&sizes, argv[1]);
	fdf = setup_fdf(sizes, coords);
	coords = rerange_coords(fdf, coords, sizes);
	// change_view(fdf, fdf->coords);
	vis_map(fdf);
	mlx_key_hook(fdf->win, &catch_key, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}