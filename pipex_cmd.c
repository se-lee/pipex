#include "pipex.h"

int	get_command(char *cmd_str, t_cmd *cmd, char **env)
{
	char **sep_cmd;

	sep_cmd = ft_split(cmd_str, ' ');
	if (sep_cmd == NULL)
		return (-1);
	cmd->path = ft_strjoin("/bin/", sep_cmd[0]);
	sep_cmd[0] = cmd->path;
	cmd->argv = (char *const *)sep_cmd;
	cmd->envp = env;
	printf("%s\n", env[0]);

	return (0);
}

/*
/usr/local/bin:
/usr/bin:
/bin:
/usr/sbin:
/sbin:
/usr/local/munki:
/opt/X11/bin
*/

void	do_command(char *argv, char **env)
{
	t_cmd cmd;

	get_command(argv, &cmd, env); 
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

difference between `` '' and " "??
 -> works with " " but doesnt work with `` ''

if command and options (argv[1~]) don't match, display error

*/
