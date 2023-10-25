/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:00:55 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 21:48:14 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H


struct s_ray;

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

// Cria uma tupla com os componentes x, y, z, e w fornecidos.
t_tuple	tuple(float x, float y, float z, float w);

// Cria uma tupla ponto com os componentes x, y e z fornecidos.
t_tuple	point(float x, float y, float z);

// Cria uma tupla vetor com os componentes x, y e z fornecidos.
t_tuple	vector(float x, float y, float z);

// Adiciona duas tuplas.
t_tuple	add(t_tuple a, t_tuple b);

// Subtrai uma tupla de outra.
t_tuple	subtract(t_tuple a, t_tuple b);

// Multiplica cada componente de uma tupla por um valor escalar.
t_tuple	multiply(t_tuple a, float scalar);

// Divide cada componente de uma tupla por um valor escalar.
t_tuple	divide(t_tuple a, float scalar);

// Calcula o produto escalar de duas tuplas.
float	dot(t_tuple a, t_tuple b);

// Calcula o produto vetorial de duas tuplas.
t_tuple	cross(t_tuple a, t_tuple b);

// Reflete uma tupla em relação a uma tupla normal.
t_tuple	reflect(t_tuple v, t_tuple n);

// Nega os valores de uma tupla.
t_tuple	negate(t_tuple a);

// Calcula a magnitude (comprimento) de uma tupla interpretada como vetor.
float	magnitude(t_tuple v);

// Normaliza uma tupla interpretada como vetor para ter magnitude de 1.
t_tuple	normalize(t_tuple v);

//
t_tuple point_at_parameter(struct s_ray r, float t);


#endif
