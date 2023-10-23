/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:28:31 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 21:07:18 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	float	fov;
	float	aspect_ratio;
	float	viewport_width;
	float	focal_length;
}	t_camera;

t_camera	init_camera(float fov, float aspect_ratio, \
float viewport_width, float focal_length);

#endif
