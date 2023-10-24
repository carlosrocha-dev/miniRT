/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:36:54 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 20:31:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "tuples.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_light {
	t_tuple position; // Posição da luz
	int color; // Cor da luz
	float intensity; // Intensidade da luz
} t_light;

t_ray	init_ray(t_tuple origin, t_tuple direction);
int diffuse_shading(t_tuple normal, t_tuple light_dir, int base_color);

#endif
