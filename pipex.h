#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft/libft.h"

# define FILE1	argv[1]
# define CMD1	argv[2]
# define CMD2	argv[3]
# define FILE2	argv[4]


/*
struct for cmd?
int execve(const char *path, char *const argv[], char *const envp[]);
*/

typedef struct	s_cmd
{
	const char	*path;
	char *const *argv;
	char *const	*envp;
}				t_cmd;

int	redirect_input(const char *file);
int	redirect_output(const char *file);

#endif


/* MEMO MEMO MEMO
$> ./pipex file1 cmd1 cmd2 file2 

argv[0] = pipex xxxxx
argv[1] = file1	---> redirecttion; const char *file
argv[2] = cmd1	---> execve
argv[3] = cmd2	---> execve
argv[4] = file2	---> redirection; const char *file

- need to think through how to do cmd part. 

*/