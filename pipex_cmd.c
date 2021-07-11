#include "pipex.h"

//int execve(const char *path, char *const argv[], char *const envp[]);
// what is the path? /bin/[cmd], /sbin/[cmd] --> the command given as *path will run
//		how many paths are there ? how to cover all ?
// argv -- argv[0]: the command, argv[1, 2, ...]: options, don't forget to end with NULL to make sure it's the end;

int	get_command(char *cmd_str, t_cmd *cmd)
{
	char **cmd_sep;

	cmd_sep = ft_split(cmd_str, ' ');
	if (cmd_sep == NULL)
		return (-1);
	cmd->path = ft_strjoin("/bin/", cmd_sep[0]);
	cmd->argv = cmd_sep;
	cmd->envp = 0; // <--- ??? i dont know what to put here.

	return (0);
}

void	do_command(t_cmd cmd)
{
	execve(cmd.path, cmd.argv, cmd.envp);

	//error case ?
}

/*

eg.
$> ./pipex infile ``ls -l'' ``wc -l'' outfile

ls -> argv[0]
-l -> argv[1]
NULL -> argv[2]

maximum number of options?

put argv[0](==cmd name) to path so that it runs the cmd
strjoin? with /bin/ ?

if command and options (argv[1~]) don't match, display error

*/

