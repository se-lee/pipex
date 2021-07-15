#include "pipex.h"

int	get_command(char *cmd_str, char **env, t_cmd *cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	cmd->sep_cmd = ft_split(cmd_str, ' '); //malloc
	if (cmd->sep_cmd == NULL)
		return (-1);
	while (env[i] != NULL && path != env[i]) //start of the string
	{
		path = ft_strstr(env[i], "PATH="); 
		i++;
	}
	path = ft_strtrim(path, "PATH="); //malloc
	//ft_substr, remove first 5 chars.
	cmd->sep_path = ft_split(path, ':'); //malloc
	i = 0;
	while (cmd->sep_path[i] != NULL)
	{
		cmd->sep_path[i] = ft_strjoin(cmd->sep_path[i], "/"); //malloc
		cmd->sep_path[i] = ft_strjoin(cmd->sep_path[i], cmd->sep_cmd[0]); //malloc
		i++;
	}
	return (0);
}

void	do_command(char *argv, char **env)
{
	int		i;
	t_cmd	cmd;

	get_command(argv, env, &cmd);
	i = 0;
	while (cmd.sep_path[i] != NULL)
	{
		execve(cmd.sep_path[i], cmd.sep_cmd, env);
		i++;
	}
	perror(cmd.sep_cmd[0]);
}
