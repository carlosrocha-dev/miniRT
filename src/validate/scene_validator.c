/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:59:42 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/22 11:09:20 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

int	process_lines(int fd)
{
	char	*gnl;
	int		flag;
	int		camera;

	camera = 0;
	gnl = get_next_line(fd);
	while (gnl && *gnl)
	{
		flag = verifie_camera(gnl);
		if (flag == 1)
		{
			camera++;
			if (camera > 1)
			{
				printf("\033[31;1mError\n\033[0m");
				printf("The scene isn`t valid! More than one camera.\n");
				free(gnl);
				return (1);
			}
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (camera);
}

int	has_scene_is_valid(char *file)
{
	int	fd;
	int	camera_count;

	fd = open_file(file);
	if (fd == -1)
		return (1);
	camera_count = process_lines(fd);
	close(fd);
	if (camera_count == 0)
	{
		printf("\033[31;1mError\n\033[0m");
		printf("The scene isn`t valid, without camera.\n");
		return (1);
	}
	return (0);
}
