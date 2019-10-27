/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:17:09 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/27 14:52:24 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int				split_len(char **splited)
{
	int	count;

	count = 0;
	while (splited[count])
		count++;
	return (count);
}

void			free_splited(char **splited, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&splited[i]);
		i++;
	}
	ft_memdel((void **)&splited);
}
