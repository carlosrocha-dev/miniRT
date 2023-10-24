/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:36:32 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 21:55:16 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// Multiplica cada componente de uma tupla por um valor escalar.
t_tuple	multiply(t_tuple a, float scalar)
{
	return (tuple(a.x * scalar, a.y * scalar, a.z * scalar, a.w * scalar));
}

// Divide cada componente de uma tupla por um valor escalar.
t_tuple	divide(t_tuple a, float scalar)
{
	if (scalar == 0)
	{
		perror("Division by zero!");
		exit(EXIT_FAILURE);
	}
	return (tuple(a.x / scalar, a.y / scalar, a.z / scalar, a.w / scalar));
}

// Calcula o produto escalar de duas tuplas.
float	dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// Calcula o produto vetorial de duas tuplas.
t_tuple	cross(t_tuple a, t_tuple b)
{
	return (vector(a.y * b.z - a.z * b.y, a.z * \
	b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

// Nega os valores de uma tupla.
t_tuple	negate(t_tuple a)
{
	return (tuple(-a.x, -a.y, -a.z, -a.w));
}
