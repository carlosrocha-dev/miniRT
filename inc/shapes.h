/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:02:03 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 20:59:40 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

typedef struct s_sphere
{
	t_tuple	center;
	float	radius;
	int		color;
}	t_sphere;

t_sphere	init_sphere(t_tuple center, float radius, int color);
int			hit_sphere(t_sphere sphere, t_ray ray, float *t);

#endif
