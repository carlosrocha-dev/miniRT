/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:23:19 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:54 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_atoi(const char* nptr) {
	if (nptr == NULL) {
		return 0;
	}
	while (ft_isspace(*nptr)) {
		nptr++;
	}
	int sign = 1;
	if (*nptr == '-') {
		sign = -1;
		nptr++;
	} else if (*nptr == '+') {
		nptr++;
	}
	int result = 0;
	while (*nptr != '\0') {
		if (*nptr < '0' || *nptr > '9') {
			return 0;
		}
		int digit = *nptr - '0';
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
			return (sign == -1 ? INT_MIN : INT_MAX);
		}
		result = result * 10 + digit;
		nptr++;
	}
	return result * sign;
}
