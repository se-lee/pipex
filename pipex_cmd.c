#include "pipex.h"

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
	path = ft_substr(path, 5, (ft_strlen(path) - 5));
	cmd->sep_path = ft_split(path, ':');
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

int	do_command(char *argv, char **env)
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
	perror_exit(cmd.sep_cmd[0]); //if execve fails, will exit(1). 
	free_double(cmd.sep_path); //if exit(1), quits before free here?
	free_double((char **)cmd.sep_cmd);
	return (0);
}
