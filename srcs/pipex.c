/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:29:27 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/27 12:11:36 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av)
{
	extern char **environ;
	int	fd[2];
	int	pid1;
	int	pid2;
	
	if (ac != 5)
		errors("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2");
	if (pipe(fd) == -1)
		errors("Error");
	pid1 = fork();
	if (pid1 == -1)
		errors("Error");
	if  (!pid1)
		in_exec(fd, av, environ);
	pid2 = fork();
	if (pid2 == -1)
		errors("Error");
	if (!pid2)
		out_exec(fd, av, environ);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
