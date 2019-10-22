/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:21:31 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/22 13:23:06 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		print_error(char *message)
{
	int i;

	i = 0;
	while (message[i])
	{
		write(2, &(message[i]), 1);
		i++;
	}
	exit(0);
}