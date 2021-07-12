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
		close(fd[0]);
		redirect_input(FILE1);
		do_command(CMD1, cmd);
	}
	//wait where??
	else if(id == 0)
	{
		close(fd[1]);
		redirect_output(FILE2);
		do_command(CMD2, cmd);
	}
	
	return (0);
} 
