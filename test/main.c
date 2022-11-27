#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char **args;
	char **env;
	char *path;

	path = strdup("/usr/bin/wc");
	args = malloc(sizeof(char *) * 3);
	if (!args)
		return (0);
	args[0] = strdup("wc");
	args[1] = strdup("-l");
	args[2] = 0;

	env = malloc(sizeof(char *));
	if (!env)
		return (0);
	env[0] = 0;
	if (execve(path, args + 1, env) == -1)
		printf("fail execution\n");
	printf("------------------>\n");
	free(path);
	free(args[0]);
	free(args[1]);
	free(args);
	free(env);
}