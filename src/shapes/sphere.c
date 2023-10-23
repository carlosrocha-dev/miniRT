/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:36:57 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/23 08:16:21 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/tuples.h"

t_sphere	init_sphere(t_tuple center, float radius, int color)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	sphere.color = color;
	return (sphere);
}

int	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_tuple	sphere_to_ray;
	t_tuple	equation;
	float	discriminant;

	sphere_to_ray = subtract(ray.origin, sphere.center);
	equation.x = dot(ray.direction, ray.direction);
	equation.y = 2.0 * dot(sphere_to_ray, ray.direction);
	equation.z = dot(sphere_to_ray, sphere_to_ray) - \
	(sphere.radius * sphere.radius);
	discriminant = equation.y * equation.y - 4 * equation.x * equation.z;
	return (discriminant > 0);
}