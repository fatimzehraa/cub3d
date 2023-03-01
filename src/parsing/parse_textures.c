#include "cub3D.h"

int parse_north(t_map **map, char *texture)
{
	if ((*map)->north){
		(*map)->duplicated = 1;
		return (0);
	}
	if (open(texture, O_RDONLY) == -1)
		return (0);
	(*map)->north = texture;
	return (1);
}

int parse_south(t_map **map, char *texture)
{
	if ((*map)->south){
		(*map)->duplicated = 1;
		return (0);
	}
	if (open(texture, O_RDONLY) == -1)
		return (0);
	(*map)->south = texture;
	return (1);
}

int parse_west(t_map **map, char *texture)
{
	if ((*map)->west){
		(*map)->duplicated = 1;
		return (0);
	}
	if (open(texture, O_RDONLY) == -1)
		return (0);
	(*map)->west = texture;
	return (1);
}

int parse_east(t_map **map, char *texture)
{
	if ((*map)->east){
		(*map)->duplicated = 1;
		return (0);
	}
	if (open(texture, O_RDONLY) == -1)
		return (0);
	(*map)->east = texture;
	return (1);
}
#include "libft.h"

int parse_floor(t_map **map, int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		print_error("Invalid color");
		return (0);
	}
	(*map)->floor.r = r;
	(*map)->floor.g = g;
	(*map)->floor.b = b;
	return (1);
}

int parse_ceiling(t_map **map, int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		print_error("Invalid color");
		return (0);
	}
	(*map)->ceiling.r = r;
	(*map)->ceiling.g = g;
	(*map)->ceiling.b = b;
	return (1);
}

int parse_color(t_map **map, char *color, char *type)
{
	char *r;
	char *g;
	char *b;

	r = ft_strtrim(color, " ,");
	g = ft_strtrim(color, " ,");
	b = ft_strtrim(color, " ,");
	if (ft_strncmp(type, "F", 1) == 0)
	{
		if (!parse_floor(map, ft_atoi(r), ft_atoi(g), ft_atoi(b)))
			return (0);
	}
	else if (ft_strncmp(type, "C", 1) == 0)
	{
		if (!parse_ceiling(map, ft_atoi(r), ft_atoi(g), ft_atoi(b)))
			return (0);
	}
	return (1);
}


