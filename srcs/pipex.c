#include "pipex.h"

// pipe function

// pipex main function


/*

pipe

fork

input the content of file1

do first command

pipe the result of first command

do second command


$> ./pipex infile ``ls -l'' ``wc -l'' outfile


*/

int pipex(int argc, char *argv[])
{
	int id;
	int fd[2];
	t_cmd *cmd = NULL;

	if (argc != 5)
		return (-1);
	pipe(fd); //have to make the pipe first
	id = fork(); //2versions of program
	if (id > 0)
	{
		redirect_input(FILE1);
		do_command(CMD1, cmd);
	}
	// else if(id == 0)
	// {//child, receive and write message
	// 	redirect_out(FILE2);
	// 	do_command(CMD2, cmd);
	// }
	
	return (0);
} 
