/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:46 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/22 20:21:17 by nlavrine         ###   ########.fr       */
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
	coords = rerange_coords(coords, sizes);
	fdf = setup_fdf(sizes);
	vis_map(fdf, coords);
	mlx_loop(fdf->mlx);
	return (0);
}