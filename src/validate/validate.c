/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:29:58 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/22 11:20:08 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/*
NOTE: Verifies if funtion system is permitted in the project.
*/
int	validate_args(int argc)
{
	if (argc != 2)
	{
		printf("\033[33;1mError\n\033[0m");
		printf("An scene should be indicated!\n<./miniRT scene/scene.rt>\n");
		printf("You can use the following scenes:\n\n");
		system("ls -1 scene/");
		printf("\n");
		return (1);
	}
	return (0);
}

int	verifie_camera(char *gnl)
{
	int	i;

	i = 0;
	if (gnl[i] == 'C')
	{
		i++;
		while (gnl[i] == ' ')
			i++;
		if ((gnl[i] == '-' || (gnl[i] >= '0' && gnl[i] <= '9')))
			return (1);
	}
	return (0);
}
