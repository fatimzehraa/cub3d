#include "cub3D.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <list.h>

t_list	*get_lines(int fd)
{
	t_list	*lines;
	char	*line;
	t_list	*new_node;

	lines = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		new_node = ft_lstnew(line);
		if (new_node == NULL)
		{
			free(line);
			ft_lstclear(&lines, free);
			return (NULL);
		}
		ft_lstadd_back(&lines, new_node);
	}
	return (lines);
}

void	print_error(char *message)
{
	write(2, message, ft_strlen(message));
}

void print_lines(t_list *lines)
{
	while (lines != NULL)
	{
		printf("%s \n", lines->content);
		lines = lines->next;
	}
}

t_list	*parse(char *filename, t_map *map)
{
	t_list	*lines;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("failed to open the file");
		return (NULL);
	}
	lines = get_lines(fd);
	close(fd);
	if (lines == NULL)
	{
		print_error("failed to read the file");
		return (NULL);
	}
	map->lines = lines;
	split_map(&map);
	if (!check_header(&map))
	{
		print_error("the textures or f&c are invalid");
		ft_lstclear(&lines, free);
		return (NULL);
	}
	print_lines(map->header);
//	print_lines(lines);
	//if (check_map(map))
	//	return (lines);
	print_error("the map is invalid");
	//ft_lstclear(&lines, free);
	return (NULL);
}

