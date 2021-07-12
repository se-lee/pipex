#include "pipex.h"

int main(int argc, char *argv[])
{
	int id;
	int fd[2];
	t_cmd cmd;

	pipe(fd); 
	id = fork(); 
	if (id > 0)
	{
		redirect_input(FILE1);
		close(fd[0]);
		do_command(CMD1, cmd);
	}
	else if(id == 0)
	{
		//wait here??
		redirect_output(FILE2);
		close(fd[1]);
		do_command(CMD2, cmd);
	}
	
	return (0);
} 
