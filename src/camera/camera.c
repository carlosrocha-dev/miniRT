/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:35:53 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 20:36:10 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_camera	init_camera(float fov, float aspect_ratio,
	float viewport_width, float focal_length)
{
	t_camera	camera;

	camera.fov = fov;
	camera.aspect_ratio = aspect_ratio;
	camera.viewport_width = viewport_width;
	camera.focal_length = focal_length;
	return (camera);
}
