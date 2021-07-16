#include "pipex.h"

void	ft_append(char **a, char *str)
{
	char	*result;

	result = ft_strjoin(*a, str);
	free(*a);
	*a = result;
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
	while (env[i] != NULL && path == NULL && path != env[i])
	{
		path = ft_strstr(env[i], "PATH="); 
		i++;
	}
	path = ft_substr(path, 5, (ft_strlen(path) - 5)); //malloc
	cmd->sep_path = ft_split(path, ':'); //malloc
	free(path);
	i = 0;
	while (cmd->sep_path[i] != NULL)
	{
		ft_append(&cmd->sep_path[i], "/");
		ft_append(&cmd->sep_path[i], cmd->sep_cmd[0]);
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
		free(cmd.sep_path[i]);
		i++;
	}
//free cmd;
	perror(cmd.sep_cmd[0]);
}
