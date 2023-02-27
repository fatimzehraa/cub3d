#include "cub3D.h"

int	end_with(char *s1, char *s2)
{
	int	i;
	int	k;

	i = ft_strlen(s1);
	k = ft_strlen(s2);
	if (k > i)
		return (0);
	while (k--)
	{
		i--;
		if (s1[i] != s2[k])
			return (0);
	}
	return (1);
}

int	args_err(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_error("please add the map file.ber to run the game");
		return (1);
	}
	if (argc > 2)
	{
		print_error("too many arguments!");
		return (1);
	}
	if (!end_with(argv[1], ".cub"))
	{
		print_error("your filename should have the extension .cub");
		return (1);
	}
	return (0);
}
