#include "cub3D.h"
int check_dup(t_map *map)
{

	t_list *curr;
	curr = map->header;
	while (curr){
		while (curr->next){
			if (curr->content == curr->next->content)
				return (1);
			curr->next = curr->next->next;
		}
		curr = curr->next;
	}
	return (0);
}

int map_began(char *content)
{
	int i;
	i = 0;
	while (content[i] == ' ')
		i++;
	return (content[i] == '1');
}

void split_map(t_map **map)
{
	(*map)->header = (*map)->lines;
	t_list *prev;
	prev = NULL;
	while ((*map)->lines && !map_began((*map)->lines->content)){
		prev = (*map)->lines;
		(*map)->lines = (*map)->lines->next;
	}
	if (prev)
		prev->next = NULL;
}

int	check_header(t_map **map)
{
	while ((*map)->header)
	{
		if ((*map)->header->content[0] == 'N' && (*map)->header->content[1] == 'O')
		{
			if (!parse_north(map, (*map)->north))
				return (0);
		}
		else if ((*map)->header->content[0] == 'S' && (*map)->header->content[1] == 'O')
		{
			if (!parse_south(map, (*map)->south))
				return (0);
		}
		else if ((*map)->header->content[0] == 'W' && (*map)->header->content[1] == 'E')
		{
			if (!parse_west(map, (*map)->west))
				return (0);
		}
		else if ((*map)->header->content[0] == 'E' && (*map)->header->content[1] == 'A')
		{
			if (!parse_east(map, (*map)->east))
				return (0);
		}
		else if ((*map)->header->content[0] == 'F')
		{
			if (!parse_color(map, (*map)->header->content, "F"))
				return (0);
		}
		else if ((*map)->header->content[0] == 'C')
		{
			if (!parse_color(map, (*map)->header->content, "C"))
				return (0);
		}
		else if ((*map)->header->content[0] == '\0')
		{
			(*map)->header = (*map)->header->next;
			continue ;
		}
		else
			return (0);
		(*map)->header = (*map)->header->next;
	}
	if (check_dup(*map))
		return (0);
	return (1);
}
/*
int check_map(t_map *map)
{
	
	return (1);
}*/
