/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:34:02 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/23 08:23:51 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_tuple	tuple(float x, float y, float z, float w)
{
	t_tuple	result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return (result);
}

t_tuple	point(float x, float y, float z)
{
	return (tuple(x, y, z, 1.0));
}

t_tuple	vector(float x, float y, float z)
{
	return (tuple(x, y, z, 0.0));
}

t_tuple	add(t_tuple a, t_tuple b)
{
	return (tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

t_tuple	subtract(t_tuple a, t_tuple b)
{
	return (tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}
