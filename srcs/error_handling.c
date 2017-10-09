#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	put_error(int code, char *language)
{
	if (code == 1 && ft_strcmp(language, "fr") == 0)
		ft_putstr("Le fichier n'existe pas\n");
	else if (code == 1)
		ft_putstr("The file doesn't exist\n");
	if (code == 2 && ft_strcmp(language, "fr") == 0)
		ft_putstr("Map invalide, elle doit contenir que des cifres\n");
	else if (code == 2)
		ft_putstr("Map not valid, it must contain only letters\n");
	if (code == 3 && ft_strcmp(language, "fr") == 0)
	{
		ft_putstr("Map pas bien structure.\n");
		ft_putstr("Il faut avoir le meme nombre des coordonees ");
		ft_putstr("sur chaque ligne\n");
	}
	else if (code == 3)
	{
		ft_putstr("Map is not well structured.\n");
		ft_putstr("You must have the same number of rows and columns.\n");
	}
	exit(EXIT_FAILURE);
}

