/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:36:54 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/24 10:55:25 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
/*
NOTE: ajustar a estrutura para receber os tipos corretos
*/
typedef struct s_ray
{
	t_tuple		origin;
	t_tuple	direction;
}	t_ray;

#endif
