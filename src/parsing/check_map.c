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

int map_began(t_list *lines)
{
	t_list *curr;
	curr = lines;
	while (curr)
	{
		while (*curr->content == ' ')
			curr->content++;
		if (curr->content[0] == '1')
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	check_header(t_map *map)
{
	map->header = map->lines;
	while (map->lines && !map_began(map->lines)){
		map->lines = map->lines->next;
	}
	t_list *tmp = map->lines;
	map->lines = NULL;
	map->lines = tmp;

	while ((*map)->lines && !map_began((*map)->lines))
	{
		if ((*map)->lines->content[0] == 'N' && (*map)->lines->content[1] == 'O')
			(*map)->header->content = (*map)->lines->content;
		else if ((*map)->lines->content[0] == 'S' && (*map)->lines->content[1] == 'O')
			(*map)->header->content = (*map)->lines->content;
		else if ((*map)->lines->content[0] == 'W' && (*map)->lines->content[1] == 'E')
			(*map)->header->content = (*map)->lines->content;
		else if ((*map)->lines->content[0] == 'E' && (*map)->lines->content[1] == 'A')
			(*map)->header->content = (*map)->lines->content;
		else if ((*map)->lines->content[0] == 'S' && (*map)->lines->content[1] == ' ')
			(*map)->header->content = (*map)->lines->content;
		else if ((*map)->lines->content[0] == 'F')
			(*map)->header->content = (*map)->lines->content;
		else if ((*map)->lines->content[0] == 'C')
			(*map)->header->content = (*map)->lines->content;
		else if ((*map)->lines->content[0] == '\0')
			(*map)->header->content = (*map)->lines->content;
		else
			return (0);
		(*map)->lines = (*map)->lines->next;
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
