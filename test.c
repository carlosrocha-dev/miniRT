/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:08:24 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 18:09:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct  s_vector
{
    float x;
    float y;
    float z;
}               t_vector;

typedef struct  s_ray
{
    t_vector origin;
    t_vector direction;
}               t_ray;

t_vector vector_subtract(t_vector a, t_vector b)
{
    t_vector result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return (result);
}

float vector_dot(t_vector a, t_vector b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

int intersect_ray_sphere(t_ray ray, t_vector sphere_center, float sphere_radius, float *t)
{
    t_vector oc = vector_subtract(ray.origin, sphere_center);
    float a = vector_dot(ray.direction, ray.direction);
    float b = 2.0 * vector_dot(oc, ray.direction);
    float c = vector_dot(oc, oc) - sphere_radius * sphere_radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return (0);
    *t = (-b - sqrt(discriminant)) / (2.0 * a);
    return (1);
}

int main(void)
{
    int width = 200;
    int height = 100;
    printf("P3\n%d %d\n255\n", width, height);

    t_vector lower_left_corner = { -2.0, -1.0, -1.0 };
    t_vector horizontal = { 4.0, 0.0, 0.0 };
    t_vector vertical = { 0.0, 2.0, 0.0 };
    t_vector origin = { 0.0, 0.0, 0.0 };
    t_vector sphere_center = { 0.0, 0.0, -1.0 };
    float sphere_radius = 0.5;
    float t;

    for (int j = height - 1; j >= 0; j--)
    {
        for (int i = 0; i < width; i++)
        {
            float u = (float)i / (float)width;
            float v = (float)j / (float)height;
            t_ray ray;
            ray.origin = origin;
            ray.direction.x = lower_left_corner.x + u * horizontal.x + v * vertical.x;
            ray.direction.y = lower_left_corner.y + u * horizontal.y + v * vertical.y;
            ray.direction.z = lower_left_corner.z + u * horizontal.z + v * vertical.z;

            if (intersect_ray_sphere(ray, sphere_center, sphere_radius, &t))
                printf("255 255 255\n");
            else
                printf("0 0 0\n");
        }
    }
    return (0);
}
