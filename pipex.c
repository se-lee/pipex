#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		id;
	int		fd[2];

	if (argc != 5)
		perror_exit("");
	pipe(fd);		
	if (pipe(fd) == -1)
		perror_exit("pipe failed");
	id = fork();
	if (id == -1)
		perror_exit("fork failed");
	if (id > 0)
	{
		redirect_input(argv[FILE1]); //do error handling
		pipe_flow(fd, STDOUT_FILENO);
		do_command(argv[CMD1], env);
	}
	else if (id == 0)
	{
		redirect_output(argv[FILE2]); //do error handling
		pipe_flow(fd, STDIN_FILENO);
		do_command(argv[CMD2], env);
	}
	return (0);
}

// group thoses functions(three) together and check whether they go ok.
// if a function returns fail, return fail.
//