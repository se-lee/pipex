#include "../includes/pipex.h"

// what is the path? /bin/[cmd], /sbin/[cmd] --> the command given as *path will run
//		how many paths are there ? how to cover all ?

int	get_command(char *cmd_str, t_cmd *cmd)
{
	char **cmd_sep;

	cmd_sep = ft_split(cmd_str, ' ');
	if (cmd_sep == NULL)
		return (-1);
	cmd->path = ft_strjoin("/bin/", cmd_sep[0]);
	cmd->argv = (char *const *)cmd_sep;
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

difference between `` '' and " "
 -> works with " " but doesnt work with `` ''

$> ./pipex infile ``ls -l'' ``wc -l'' outfile

ls -> argv[0]
-l -> argv[1]
NULL -> argv[2]

if command and options (argv[1~]) don't match, display error

*/

