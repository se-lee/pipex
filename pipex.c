#include "pipex.h"

int main(int argc, char *argv[], char **env)
{
	int id;
	int fd[2];
	t_cmd	cmd;

	if (argc != 5)
		return (0);
	init_cmd(&cmd);
	pipe(fd); 
	id = fork(); 
	if (id > 0) 
	{
		redirect_input(argv[FILE1]);
		pipe_flow(fd, STDOUT_FILENO);
		do_command(argv[CMD1], env, cmd);
	}
	else if(id == 0) 
	{
		redirect_output(argv[FILE2]);
		pipe_flow(fd, STDIN_FILENO);
		do_command(argv[CMD2], env, cmd);
	}
	return (0);
} 
