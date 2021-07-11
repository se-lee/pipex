#include "pipex.h"

//int execve(const char *path, char *const argv[], char *const envp[]);
// what is the path? /bin/[cmd], /sbin/[cmd] --> the command given as *path will run
// argv -- argv[0]: the command, argv[1, 2, ...]: options, don't forget to end with NULL to make sure it's the end;


// find command
/*

eg.
$> ./pipex infile ``ls -l'' ``wc -l'' outfile

ls -> argv[0]
-l -> argv[1]
NULL -> argv[2]

maximum number of options?

do split? with sep " ";


put argv[0](==cmd name) to path so that it runs the cmd
strjoin? with /bin/ ?

if command and options (argv[1~]) don't match, display error

*/

