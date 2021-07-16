#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		id;
	int		fd[2];
//	int		proc_res;

	if (argc != 5)
		perror_exit("argc");
	pipe(fd);
	if (pipe(fd) == -1)
		perror_exit("pipe");
	id = fork();
	if (id == -1)
		perror_exit("fork");
	if (id > 0)
	{
		// proc_res = process_parent(argv, fd, env);
		// if (proc_res == -1)
		// 	perror(argv);
		redirect_input(argv[FILE1]);
		pipe_flow(fd, STDOUT_FILENO);
		do_command(argv[CMD1], env);
	}
	else if (id == 0)
	{
		redirect_output(argv[FILE2]);
		pipe_flow(fd, STDIN_FILENO);
		do_command(argv[CMD2], env);
	}
	return (0);
}

// group thoses functions(three) together and check whether they go ok.
// if a function returns fail, return fail.
//