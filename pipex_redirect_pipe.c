#include "pipex.h"

int	redirect_input(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror_exit((char *)file);
	// dup2(fd, STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) == -1)
		perror_exit("dup2");
	close(fd);
	return (0);
}

int	redirect_output(const char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		perror_exit((char *)file);
//	dup2(fd, STDOUT_FILENO);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror_exit("dup2");
	close(fd);
	return (0);
}

int	pipe_flow(int *fd, int inout)
{
	// dup2(fd[inout], inout);	
	if (dup2(fd[inout], inout) == -1)
		perror_exit("dup2");
	close(fd[0]);
	close(fd[1]);
	return (0);
}
