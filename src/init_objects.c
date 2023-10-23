/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:03:35 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 19:08:00 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_camera	init_camera(float fov, float aspect_ratio, float viewport_width, \
float focal_length)
{
	t_camera	camera;

	camera.fov = fov;
	camera.aspect_ratio = aspect_ratio;
	camera.viewport_width = viewport_width;
	camera.focal_length = focal_length;
	return (camera);
}

t_sphere	init_sphere(t_tuple center, float radius, int color)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	sphere.color = color;
	return (sphere);
}

t_ray	init_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}
