#include "pipex.h"

int	redirect_input(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror (file);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_output(const char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
	{
		perror (file);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

void	pipe_flow(int *fd, int inout)
{
	dup2(fd[inout], inout);
	close(fd[0]);
	close(fd[1]);
}
