#include "pipex.h"

int main(int argc, char *argv[], char **env)
{
	int id;
	int fd[2];
	t_cmd cmd;

	pipe(fd); 
	id = fork(); 

	if (id > 0) 
	{
		redirect_input(argv[1]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_command(argv[2], env);
	}
	else if(id == 0) 
	{
		redirect_output(argv[4]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_command(argv[3], env);
	}

	return (0);
} 
