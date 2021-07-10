#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

int	redirect_input(const char *file); //why const char *?
int	redirect_output(const char *file);

#endif