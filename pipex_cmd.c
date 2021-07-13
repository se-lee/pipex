#include "pipex.h"

int	get_command(char *cmd_str, t_cmd *cmd, char **env)
{
	int		i;
	char	*path;
	char	**sep_cmd;
	char	**sep_path;

	sep_cmd = ft_split(cmd_str, ' ');
	if (sep_cmd == NULL)
		return (-1);
	i = 0;
	path = NULL;
	while (env[i] != NULL && path == NULL)
	{
		path = ft_strstr(env[i], "PATH=");
		i++;
	}
	path = ft_strtrim(path, "PATH=");
	sep_path = ft_split(path, ':');
//	cmd->path = ft_strjoin("/usr/bin/", sep_cmd[0]);
	cmd->argv = (char *const *)sep_cmd;
	cmd->envp = env;
	return (0);
}

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
