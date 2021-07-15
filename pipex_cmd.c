#include "pipex.h"

void	init_cmd(t_cmd *cmd)
{
	cmd->sep_path = NULL;
	cmd->sep_cmd = NULL;
}

int	get_command(char *cmd_str, char **env, t_cmd *cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	cmd->sep_cmd = ft_split(cmd_str, ' ');
	if (cmd->sep_cmd == NULL)
		return (-1);
	while (env[i] != NULL && path == NULL)
	{
		path = ft_strstr(env[i], "PATH=");
		i++;
	}
	path = ft_strtrim(path, "PATH=");
	cmd->sep_path = ft_split(path, ':');
	i = 0;
	while (cmd->sep_path[i] != NULL)
	{
		cmd->sep_path[i] = ft_strjoin(cmd->sep_path[i], "/");
		cmd->sep_path[i] = ft_strjoin(cmd->sep_path[i], cmd->sep_cmd[0]);
		i++;
	}
	return (0);
}

void	do_command(char *argv, char **env, t_cmd cmd)
{
	int		i;
	
	get_command(argv, env, &cmd);
	i = 0;
	while (cmd.sep_path[i] != NULL)
	{
		execve(cmd.sep_path[i], cmd.sep_cmd, env);
		i++;
	}
}
