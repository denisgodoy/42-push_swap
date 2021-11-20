#include "push_swap.h"

int	ft_check_args(int argc, char **argv);

int main(int argc, char **argv)
{
	int	i;

	if (ft_check_args(argc, argv) < 0)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	printf("argc %d\n", argc);
	i = 1;
	while (argv[i])
		printf("argv %s\n", argv[i++]);
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return (-1);
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (-1);
	}
	return (0);
}