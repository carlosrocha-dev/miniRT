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

int	hit_sphere(t_sphere sphere, t_ray ray, float *t)
{
	t_tuple	sphere_to_ray;
	t_tuple	equation;
	float	discriminant;
	float	t1;
	float	t2;

	sphere_to_ray = subtract(ray.origin, sphere.center);
	equation.x = dot(ray.direction, ray.direction);
	equation.y = 2.0 * dot(sphere_to_ray, ray.direction);
	equation.z = dot(sphere_to_ray, sphere_to_ray) - \
	(sphere.radius * sphere.radius);
	discriminant = equation.y * equation.y - 4 * equation.x * equation.z;

	if (discriminant < 0)
		return (0);

	t1 = (-equation.y + sqrt(discriminant)) / (2.0 * equation.x);
	t2 = (-equation.y - sqrt(discriminant)) / (2.0 * equation.x);

	if (t1 > 0 && t1 < t2)
		*t = t1;
	else if (t2 > 0)
		*t = t2;
	else
		return (0);

	return (1);
}
