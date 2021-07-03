
#include <stdio.h>
// for printf

#include <unistd.h>
// for close

#include <fcntl.h>
// for open & rights

int main() 
{
	// Create the new output
	int output = open("log.txt", O_CREAT | O_WRONLY, 0644);

	// Create you say that accessing with fd STDOUT_FILENO (=1)
	// is the same as reading from the `output`
	dup2(output, STDOUT_FILENO);

	//
	// Here:
	//     read(output, buffer, n);
	//     read(STDOUT_FILENO, buffer, n);
	//
	close(output);

	// Here output (the number) is not linked to 'log.txt' anymore

	printf("Hello !\n");

	// Thus when you write to fd 1 ie (STDOUT_FILENO)
	// you write to 'log.txt'

	fflush(stdout);
	// This is to make sure the buffer used by printf is emptied
	// and that every that you wanted to write has been told the system

	close(STDOUT_FILENO);
	// Here you can close the fd STDOUT_FILNO which is 'log.txt'
}
