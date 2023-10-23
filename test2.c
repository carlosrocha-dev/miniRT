/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:14:00 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 18:17:28 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct  s_vector
{
    float x, y, z;
}               t_vector;

typedef struct  s_ray
{
    t_vector origin, direction;
}               t_ray;

t_vector vector_add(t_vector a, t_vector b)
{
    return (t_vector){a.x + b.x, a.y + b.y, a.z + b.z};
}

t_vector vector_multiply(t_vector a, float t)
{
    return (t_vector){a.x * t, a.y * t, a.z * t};
}

t_vector vector_subtract(t_vector a, t_vector b)
{
    return (t_vector){a.x - b.x, a.y - b.y, a.z - b.z};
}

float vector_dot(t_vector a, t_vector b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float vector_length(t_vector v)
{
    return sqrt(vector_dot(v, v));
}

t_vector vector_normalize(t_vector v)
{
    float length = vector_length(v);
    return (t_vector){v.x / length, v.y / length, v.z / length};
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
    int width = 2000, height = 1000;
    printf("P3\n%d %d\n255\n", width, height);

    t_vector origin = {0, 0, 0};
    t_vector lower_left_corner = {-2.0, -1.0, -1.0};
    t_vector horizontal = {4.0, 0.0, 0.0};
    t_vector vertical = {0.0, 2.0, 0.0};
    t_vector sphere_center = {0.0, 0.0, -1.0};
    float sphere_radius = 0.5;
    t_vector light_position = {2.0, 2.0, -2.0};
    float t;

    for (int j = height - 1; j >= 0; j--)
    {
        for (int i = 0; i < width; i++)
        {
            float u = (float)i / (float)width;
            float v = (float)j / (float)height;
            t_ray ray = {origin, vector_add(vector_add(lower_left_corner,
                                    vector_multiply(horizontal, u)), vector_multiply(vertical, v))};
            if (intersect_ray_sphere(ray, sphere_center, sphere_radius, &t))
            {
                t_vector point = vector_add(ray.origin, vector_multiply(ray.direction, t));
                t_vector normal = vector_normalize(vector_subtract(point, sphere_center));
                t_vector light_dir = vector_normalize(vector_subtract(light_position, point));

                float diffuse = vector_dot(normal, light_dir);
                if (diffuse < 0.0)
                    diffuse = 0.0;

                int intensity = (int)(255 * diffuse);
                printf("%d %d %d\n", intensity, intensity, intensity);
            }
            else
                printf("0 0 0\n");
        }
    }
    return (0);
}
