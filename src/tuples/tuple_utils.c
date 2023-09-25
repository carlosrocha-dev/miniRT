/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:40:19 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/24 10:56:45 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

/*
Reflect indica um raio de luz atingindo uma superfície e sendo refletido.
A direção do raio refletido é determinada pela direção do raio incidente e
pelo vetor normal à superfície no ponto de incidência. A função calcula a
direção refletida.
*/
// t_tuple	reflect(t_tuple v, t_tuple n)
// {
// 	t_tuple	sub;

// 	sub = multiply(n, 2 * dot(v, n));
// 	return (subtract(v, sub));
// }

// // Calcula a magnitude (comprimento) de uma tupla interpretada como vetor.
// float	magnitude(t_tuple v)
// {
// 	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
// }

// // Normaliza uma tupla interpretada como vetor para ter magnitude de 1.
// t_tuple	normalize(t_tuple v)
// {
// 	float	mag;

// 	mag = magnitude(v);
// 	if (mag == 0)
// 	{
// 		perror("Cannot normalize a zero vector!");
// 		exit(EXIT_FAILURE);
// 	}
// 	return (divide(v, mag));
// }
