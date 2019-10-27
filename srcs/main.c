/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:46 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/27 16:39:38 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_coords	sizes;
	t_coords	**coords;

	if (argc != 2)
		print_error("Woops, where file ?\n");
	coords = parse_file(&sizes, argv[1]);
	fdf = setup_fdf(sizes, coords);
	vis_map(fdf);
	string_toolbar(fdf);
	mlx_key_hook(fdf->win, &catch_key, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
