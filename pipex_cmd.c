#include "pipex.h"


int	get_command(char *cmd_str, t_cmd *cmd)
{
	char **sep_cmd;

	sep_cmd = ft_split(cmd_str, ' ');
	if (sep_cmd == NULL)
		return (-1);
	cmd->path = ft_strjoin("/bin/", sep_cmd[0]);
	cmd->argv = (char *const *)sep_cmd;
	cmd->envp = 0; // <--- ??? not sure what to put;

	return (0);
}

void	do_command(char *argv,t_cmd cmd)	//or maybe i don't need to separate this function
{
	get_command(argv, &cmd);
	execve(cmd.path, cmd.argv, cmd.envp);
	//error case ?
}


/*
int	main(int argc, char *argv[])
{
	t_cmd	command;
	
	get_command(argv[1], &command);
	printf("path: %s",command.path);	
	do_command(command);

	return (0);
}
*/

/*
what is the path? /bin/[cmd], /sbin/[cmd] --> the command given as *path will run
	how many paths are there ? how to cover all ?

difference between `` '' and " "
 -> works with " " but doesnt work with `` ''

$> ./pipex infile ``ls -l'' ``wc -l'' outfile

ls -> argv[0]
-l -> argv[1]
NULL -> argv[2]

if command and options (argv[1~]) don't match, display error

*/
