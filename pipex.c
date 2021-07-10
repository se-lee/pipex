#include "pipex.h"

int	redirect_input(const char *file)
{
// a function to open file 1 and send to stdin
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror ("Fail");
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_output(const char *file)
{// to send the content to file2
	int fd;

	fd = open(file, O_CREAT | O_WRONLY, 0644); // or O_RDWR?? 0644 for rights
	if (fd < 0)
	{
		perror ("Fail");
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int main()
{
	redirect_input("infile");
	redirect_output("outfile");
	printf("this is a test");
	char *argv[2];
	argv[1] = "outfile";
	execve("/bin/cat", argv, 0); // -> this (over)writes the content of infile to outfile
	return (0);
}

// pipe

