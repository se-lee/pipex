#include "pipex.h"

void	ft_append(char **a, char *str)
{
	char	*result;

	result = ft_strjoin(*a, str);
	free(*a);
	*a = result;
}

void	perror_exit(char *arg)
{
	perror(arg);
	exit(EXIT_FAILURE);
}

void	free_double(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}


// give up ~_~;
int		process_parent(char *argv[], int *fd, char **env)
{
	if (redirect_input(argv[FILE1]) == -1)
		return (-1);
	if (pipe_flow(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (do_command(argv[CMD1], env) == -1)
		return (-1);
	return (0);
}
