#include "pipex.h"

int pipex(int argc, char *argv[])
{
		int id;
	int fd[2];
	t_cmd cmd;

	if (argc != 5)
		return (-1);
	pipe(fd); //have to make the pipe first
	id = fork(); 
	if (id > 0)
	{
		close(fd[0]);
		redirect_input(FILE1);
		do_command(CMD1, cmd);
	}
	else if(id == 0)
	{
		waitpid(id, NULL, 0);
		close(fd[1]);
		redirect_output(FILE2);
		do_command(CMD2, cmd);
	}
	
	return (0);
} 
