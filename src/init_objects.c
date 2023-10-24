/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:03:35 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 23:08:28 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// t_camera	init_camera(float fov, float aspect_ratio, float viewport_width,
// float focal_length)
// {
// 	t_camera	camera;

// 	camera.fov = fov;
// 	camera.aspect_ratio = aspect_ratio;
// 	camera.viewport_width = viewport_width;
// 	camera.focal_length = focal_length;
// 	return (camera);
// }

// t_sphere	init_sphere(t_tuple center, float radius, int color)
// {
// 	t_sphere	sphere;

// 	sphere.center = center;
// 	sphere.radius = radius;
// 	sphere.color = color;
// 	return (sphere);
// }

t_ray	init_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

int diffuse_shading(t_tuple normal, t_tuple light_dir, int base_color)
{
    float diffuse = dot(normal, light_dir);
    if (diffuse < 0.0)
        diffuse = 0.0;
    int intensity = (int)(255 * diffuse);

    // Multiplicando a cor base pela intensidade para obter cor iluminada
    int red = (base_color >> 16 & 0xFF) * intensity;
    int green = (base_color >> 8 & 0xFF) * intensity;
    int blue = (base_color & 0xFF) * intensity;

    return ((red << 16) + (green << 8) + blue);
}
