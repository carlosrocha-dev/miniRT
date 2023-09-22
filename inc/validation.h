/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:04:45 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/22 11:31:05 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

//Prompt
int		validate_args(int argc);

//camera
int		verifie_camera(char *gnl);
int		open_file(char *file);
int		process_lines(int fd);
int		has_scene_is_valid(char *file);

#endif