#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft/libft.h"

# define FILE1	1
# define CMD1	2
# define CMD2	3
# define FILE2	4

typedef struct s_cmd
{
	char		**sep_path;
	char *const	*sep_cmd;
}				t_cmd;

int		redirect_input(const char *file);
int		redirect_output(const char *file);
int		pipe_flow(int *fd, int inout);
int		get_command(char *cmd_str, char **env, t_cmd *cmd);
int		do_command(char *argv, char **env);
void	ft_append(char **a, char *str);
void	free_double(char **ptr);
void	perror_exit(char *arg);



#endif

/*
pipex_cmd:
        - what does strtrim do ? 
			--> takes out every character in "reference set". not the exact string.
        - strtrim might remove too much
        - strstr looks for anywhere in the string not just the start (PATH could be found anywhere)
        - cmd should not be an argument of do_command
        - unfinished error handling

problems:
        - leaks, leaks everywhere
*/