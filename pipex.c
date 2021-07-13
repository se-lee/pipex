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
		redirect_input(argv[FILE1]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_command(argv[CMD1], env, cmd);
	}
	else if(id == 0) 
	{
		redirect_output(argv[FILE2]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		do_command(argv[CMD2], env, cmd);
	}

	return (0);
} 
