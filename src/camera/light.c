#include "../inc/minirt.h"

int clamp(int val, int min, int max)
{
	if (val < min)
		return min;
	else if (val > max)
		return max;
	return val;
}

int mult_color(int color, float intensity)
{
	// Extrair os componentes RGB
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;

	// Multiplicar cada componente pela intensidade
	r = clamp((int)(r * intensity), 0, 255);
	g = clamp((int)(g * intensity), 0, 255);
	b = clamp((int)(b * intensity), 0, 255);

	// Combinar os componentes multiplicados de volta em uma cor única
	return (r << 16) | (g << 8) | b;
}
